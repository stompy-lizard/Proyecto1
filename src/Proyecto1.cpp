#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include <cstdlib>

#include "Punto.hh"
#include "Util.hh"

// includes for drawing the Voronoi Diagram
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/draw_voronoi_diagram_2.h>

// typedefs for defining the adaptor
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> DT;
typedef CGAL::Delaunay_triangulation_adaptation_traits_2<DT> AT;
typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2<DT> AP;
typedef CGAL::Voronoi_diagram_2<DT, AT, AP> VD;

// typedef for the result type of the point location
typedef AT::Site_2 Site_2;

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
 * @brief Dibuja el diagrama de voronoi en una ventana nueva. Basado en el ejemplo de CGAL
 *
 * @param puntosNuevos Nombre del archivo a leer.
 * @return int Informa éxito.
 */
int draw(std::string puntosNuevos) {
  std::ifstream ifs(puntosNuevos);
  assert(ifs);
  VD vd;
  Site_2 t;
  while (ifs >> t) {
    vd.insert(t);
  }
  ifs.close();
  assert(vd.is_valid());
  CGAL::draw(vd);
  return EXIT_SUCCESS;
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

  std::ofstream nuevoArchivo; //declaramos stream
  nuevoArchivo.open("puntosNuevos");//archivo nuevo abierto
  if( !nuevoArchivo ) //si no se pudo abrir 
      std::cerr << "Error: nose puedo abrir el archivo nuevoArchvo" << std::endl;

  std::vector<Punto>* puntos = obtenerPuntos(archivo);
  std::cout << "Lista de puntos:" << std::endl;
  for (auto it = puntos->begin(); it != puntos->end(); ++it) {
    nuevoArchivo << it->getX();
    nuevoArchivo << " ";
    nuevoArchivo << it->getY();
    nuevoArchivo << std::endl;
    it->printPunto();
    std::cout << std::endl;
  }
  nuevoArchivo.close();

  draw("./puntosNuevos");

  return 0;
}
