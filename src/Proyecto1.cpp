#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Punto.hh"
#include "Util.hh"

/**
 * @brief Obtiene un vector con los puntos presentes en cada linea del archivo
 * indicado.
 *
 * @param archivo Ruta al archivo que contiene los puntos.
 * @return std::vector<Punto>* Vector con puntos parseados.
 */
std::vector<Punto>* obtenerPuntos(std::string archivo) {
  std::ifstream infile(archivo);
  std::string linea;
  std::vector<Punto>* puntos = new std::vector<Punto>();
  int i = 0;
  while (std::getline(infile, linea)) {
    i++;  // permite indicar el número de línea en caso de advertencia.
    std::istringstream iss(linea);
    try {
      Punto* punto = new Punto(
          linea);  // Crea un punto si el formato de la línea es aceptado.
      puntos->push_back(*punto);  // Agrega el punto al vector.
    } catch (const std::exception& e) {
      // Ignorar línea e imprimir advetencia.
      std::cerr << "Advertencia: Línea " << i << " del archivo " << archivo
                << ": " << e.what() << "Contenido: " << linea << std::endl;
      continue;
    }
  }
  return puntos;
}

/**
 * @brief Programa principal.
 *
 * @return int .
 */
int main(int argc, char** argv) {
  std::string archivo;
  // El primer argumento es el ejecutable, por lo que se requieren 2 argumentos
  // como mínimo.
  if (argc < 2) {
    std::cerr << "Error: Se requiere un argumento que indique la ruta del "
                 "archivo que contiene la lista de puntos."
              << std::endl;
    return 1;
  } else {
    if (argc > 2) {
      std::cerr
          << "Advertencia: Argumentos ignorados, solo se acepta un argumento."
          << std::endl;
    }
    archivo = argv[1];
  }
  if (!Util::fileExists(archivo)) {
    std::cerr
        << "Error: La ruta del archivo no es correcta, el archivo no existe."
        << std::endl;
    return 1;
  }

  std::vector<Punto>* puntos = obtenerPuntos(archivo);
  std::cout << "Lista de puntos:" << std::endl;
  for (auto it = puntos->begin(); it != puntos->end(); ++it) {
    it->printPunto();
    std::cout << std::endl;
  }
  return 0;
}
