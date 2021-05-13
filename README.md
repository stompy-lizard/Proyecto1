<h1> Proyecto1_IE0724 </h1>

<h2> Curso: Laboratorio de programación IE - 0724</h2>
  
<h2> Tema: Visualización de diagramas de Voronoi haciendo uso del lenguaje de programación C++ </h2>

<h2>Integrantes:</h2>

<p>
  <ul>
    <li> Robin González Ricz, B43011.           </li>
    <li> Jonathan Ramírez Hernández, B55730.    </li>
    <li> Emilio Javier Rojas Álvarez, B15680.   </li>
  </ul>
</p>

<hr>

## Table of contents
* [Síntesis del funcionamiento del programa](#program-info)
* [Instrucciones de compilación y ejecución](#instructions)

<h3>  Síntesis del funcionamiento del programa  </h3>
  <p >
      El programa se encarga de realizar la visualización de un diagrama de Voronoi bidimensional de un conjunto de pares ordenados que también deben
      ser bidimensionales, es decir, de la forma (x,y). La visualización del diagrama se realiza con la ayuda de la biblioteca CGAL, que es un proyecto
      de software que provee algoritmos geométricos desarrollados en C++.
  </p>
  
  <p>
      Para la visualización del diagrama, el programa requiere extraer la información contenida en un archivo de texto de formato txt; éste es recibido como             entrada por éste y es procesado para determinar, primeramente, si los valores introducidos tienen el tipo y formato adecuados (en este caso, de tipo               "float") y para dibujar el diagrama de Voronoi con el apoyo de CGAL. Una vez que el diagrama es dibujado por el programa, éste se almacena en un archivo de       formato .png en la carpeta "build" (que se mencionará en la siguiente sección) que se tiene por nombre "diagrama.png". Este archivo puede abrirse con 
      cualquier visor de imágenes integrado en el sistema operativo.
  </p>

  
<h3> Instrucciones de compilación y ejecución </h3>
  <p>
      Para la compilación y ejecución del programa es necesario tener instalada la herramienta de automatización de código CMake. 
      Se debe descargar el repositorio y dentro de la carpeta en la que están incluidos los directorios de "include" y "test" ejecutar las siguientes
      instrucciones en la consola (terminal) de comandos:
      <ul>
        <li> mkdir build && cd build      </li>
        <li> cmake ..                     </li>
        <li> make                         </li>
        <li> ./Proyecto1 ../[nombre_del_archivo].txt    </li>
      </ul>
  </p>
  
  <p>
      La última instrucción del ejecutable, por ejemplo, puede ser escrita como:
  </p>
```
mkdir build && cd build
cmake ..
make
./Proyecto1 ../puntos.txt # ejecutar
```
