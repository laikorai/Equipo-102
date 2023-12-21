#include "actividad.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip> //para que se vea bonito a la hora de imprimir las actividades.
#include <set>  
#include <sstream>

/****************************************************************************************************************/
/*********************************************FUNCIÓN crearActividad*********************************************/
void Actividad::crearActividad() // le pedimos al usuario la informacion y la guardamos en la clase actividad
{
    std::string aux_aforo = "empty";

    std::cout << "Por favor, acontinuacion rellenes los datos de la actividad academica\n";
    std::cout << "NOMBRE de la actividad: \n";
    std::cin >> nombre_;

}

/****************************************************************************************************************/
/*********************************************FUNCIÓN escribirFichero*********************************************/
void Actividad::escribirFichero()
{

    const char *nombreArchivo = "todas_actividades.txt";

    // Crear un objeto ofstream (salida de archivo) para escribir en el archivo
    std::ofstream archivoSalida(nombreArchivo, std::ios::app);

    // Verificar si se pudo abrir el archivo
    if (!archivoSalida.is_open())
    {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        exit(EXIT_SUCCESS); // Terminar con error
    }

    // Escribir en el archivo
    archivoSalida << nombre_ << " " << aforo_ << " " << fecha_ << " " << director_ << " " << lugar_ << " " << descripcion_ << std::endl;

    // Cerrar el archivo
    archivoSalida.close();
}

/****************************************************************************************************************/
/********************************************FUNCIÓN visualizarActividades, y subfunciones...********************/

// Función para imprimir una línea de separación
void printSeparator()
{
    std::cout << std::setw(43) << std::setfill('_') << "" << std::setfill(' ') << std::endl;
}

// Función para imprimir una actividad en formato de tabla
void printActivity(int numero, const std::string &nombre, int aforo, const std::string &fecha,
                   const std::string &director, const std::string &lugar, const std::string &descripcion)
{
    // Encabezado de la actividad
    std::cout << "|         ACTIVIDAD " << numero << "           |\n";

    // Línea de separación superior
    std::cout << "+------------------+---------+------------+------------+------------+----------------+\n";

    // Cuerpo de la tabla
    std::cout << "|   Nombre         |  Aforo  |   Fecha    |  Director  |   Lugar    |   Descripcion  |\n";
    std::cout << "+------------------+---------+------------+------------+------------+----------------+\n";
    // Contenido de la actividad
    std::cout << "|  " << std::setw(16) << std::left << nombre << "|  " << std::setw(7) << aforo
              << "|  " << std::setw(10) << fecha << "|  " << std::setw(10) << director
              << "|  " << std::setw(10) << lugar << "|" << std::setw(10) << descripcion << std::setw(10) << "|\n";

    // Línea de separación inferior
    std::cout << "+------------------+---------+------------+------------+------------+----------------+\n\n";
}

void Actividad::visualizarActividades(bool soloActivas)
{
    std::cout << "\n\n\n\n";
    std::cout << "\n Las actividades ";
    if (soloActivas)
    {
        std::cout << "activas ";
    }

    std::cout << "son estas:\n";

    std::ifstream archivoTodas("todas_actividades.txt");
    std::ifstream archivoActivas("actividades_activas.txt");

    if (!archivoTodas.is_open() || !archivoActivas.is_open())
    {
        std::cerr << "No se pudo abrir uno o ambos archivos." << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::string nombre;
    int aforo;
    std::string fecha;
    std::string director;
    std::string lugar;
    std::string descripcion;

    std::set<std::string> actividadesActivas;
    std::string activa;

    // Leer actividades activas y almacenarlas en un conjunto
    while (archivoActivas >> activa)
    {
        actividadesActivas.insert(activa);
    }

    archivoActivas.close(); // Cerrar archivo de actividades activas

    static int numeroActividad = 1;

    // Leer y mostrar cada actividad
    while (archivoTodas >> nombre >> aforo >> fecha >> director >> lugar >> descripcion)
    {
        if (!soloActivas || actividadesActivas.count(nombre) > 0)
        {
            printActivity(numeroActividad++, nombre, aforo, fecha, director, lugar, descripcion);
        }
    }

    archivoTodas.close(); // Cerrar archivo de todas las actividades
}

/****************************************************************************************************************/
/********************************************FUNCIÓN activarActividad********************************************/

void Actividad::activarActividad(std::string actividad)
{
    // Abrir el archivo de actividades activas
    std::ofstream archivoActivas("actividades_activas.txt", std::ios::app);

    if (!archivoActivas.is_open())
    {
        std::cerr << "Error al abrir el archivo de actividades activas." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Escribir el nombre de la actividad activa en el archivo
    archivoActivas << actividad << std::endl;

    // Cerrar el archivo
    archivoActivas.close();
}



/****************************************************************************************************************/
/**********************************FUNCIÓN visualizaActividadesRellenas******************************************/
void Actividad::visualizaActividadesRellenas()
{
    std::ifstream archivoTodas("todas_actividades.txt");

    if (!archivoTodas.is_open())
    {
        std::cerr << "No se pudo abrir el archivo de actividades." << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::string nombre;
    int aforo;
    std::string fecha;
    std::string director;
    std::string lugar;
    std::string descripcion;

    static int numeroActividad = 1;

    // Leer y mostrar cada actividad con descripciones
    while (archivoTodas >> nombre >> aforo >> fecha >> director >> lugar >> descripcion)
    {
        printSeparator();
        std::cout << "  ACTIVIDAD " << numeroActividad++ << std::endl;
        printSeparator();
        std::cout << std::left << std::setw(20) << "Nombre:" << nombre << std::endl;
        std::cout << std::left << std::setw(20) << "Aforo:" << aforo << std::endl;
        std::cout << std::left << std::setw(20) << "Fecha:" << fecha << std::endl;
        std::cout << std::left << std::setw(20) << "Director:" << director << std::endl;
        std::cout << std::left << std::setw(20) << "Lugar:" << lugar << std::endl;
        std::cout << std::left << std::setw(20) << "Descripción:" << descripcion << std::endl;
        std::cout << std::endl;
    }

    archivoTodas.close(); // Cerrar archivo de todas las actividades
}

/****************************************************************************************************************/
/********************************************FUNCIÓN modificar fichero ****************************/

void Actividad::modificarActividad(const std::string &nombre)
{
    // Abre el archivo para leer las actividades
    std::ifstream archivoEntrada("todas_actividades.txt");

    if (!archivoEntrada.is_open())
    {
        std::cerr << "No se pudo abrir el archivo de actividades." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Variables temporales para almacenar los datos de la actividad
    std::string nombreTmp;
    int aforoTmp;
    std::string fechaTmp;
    std::string lugarTmp;
    std::string directorTmp;
    std::string descripcionTmp;

    // Variables para determinar si se encontró la actividad
    bool actividadEncontrada = false;

    // Crea un archivo temporal para escribir las actividades modificadas
    std::ofstream archivoTemporal("temporal.txt");

    // Lee las actividades del archivo, busca la actividad por nombre y realiza la modificación
    while (archivoEntrada >> nombreTmp >> aforoTmp >> fechaTmp >> directorTmp >> lugarTmp >> descripcionTmp )
    {
        if (nombreTmp == nombre)
        {
            // Encuentra la actividad, solicita al usuario los nuevos valores
            std::cout << "Modificando la actividad: " << nombreTmp << std::endl;
            std::cout << "Nuevo aforo: ";
            std::cin >> aforoTmp;
            std::cout << "FECHA: ";
            std::cin >> fechaTmp;
            std::cout << "DIRECTOR: ";
            std::cin >> directorTmp;
            std::cout << "LUGAR: ";
            std::cin >> lugarTmp;
            std::cout << "DESCRIPCION: ";
            std::cin >> descripcionTmp;
            // Similarmente, puedes solicitar y actualizar otros atributos

            // Indica que la actividad ha sido encontrada
            actividadEncontrada = true;
        }

        // Escribe la actividad (modificada o no) en el archivo temporal
        archivoTemporal << nombreTmp << " " << aforoTmp << " " << fechaTmp << " " << directorTmp << " " << lugarTmp << " " << descripcionTmp  << std::endl;
    }

    // Cierra los archivos
    archivoEntrada.close();
    archivoTemporal.close();

    // Reemplaza el archivo original con el archivo temporal
    std::rename("temporal.txt", "todas_actividades.txt");

    // Muestra un mensaje si la actividad no se encontró
    if (!actividadEncontrada)
    {
        std::cout << "No se encontró ninguna actividad con el nombre especificado." << std::endl;
    }
}



void Actividad::preinscribirUsuario()
{
    std::string nombreActividad;
    std::string nombreUsuario;

    std::cout << "Introduce el nombre de la actividad para preinscribirte: ";
    std::cin >> nombreActividad;

    std::cin.ignore(); // Ignorar el salto de línea dejado por la entrada anterior

    std::cout << "Introduce tu nombre y apellidos para la preinscripción: ";
    std::getline(std::cin, nombreUsuario);

    const char *nombreArchivoPreinscritos = "preinscritos.txt";

    // Abrir el archivo en modo de escritura
    std::ofstream archivoPreinscritos(nombreArchivoPreinscritos, std::ios::app);
    if (!archivoPreinscritos.is_open())
    {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivoPreinscritos << std::endl;
        exit(EXIT_SUCCESS);
    }

    // Escribir la preinscripción en el archivo
    archivoPreinscritos << nombreActividad << nombreUsuario << std::endl;

    // Cerrar el archivo
    archivoPreinscritos.close();

    std::cout << "Te has preinscrito en la actividad exitosamente." << std::endl;
}

void Actividad::verPreinscritos()
{
    // Abre el archivo de preinscritos para lectura
    std::ifstream archivoPreinscritos("preinscritos.txt");

    if (!archivoPreinscritos.is_open())
    {
        std::cerr << "No se pudo abrir el archivo de preinscritos." << std::endl;
        return;
    }

    std::string nombreActividad, nombreUsuario;
    std::string linea;

    std::cout << "Preinscritos:\n";
    std::cout << "------------------------\n";

    // Lee y muestra cada línea del archivo de preinscritos
    while (std::getline(archivoPreinscritos, linea))
    {
        // Utiliza un stringstream para dividir la línea en palabras
        std::istringstream ss(linea);
        ss >> nombreActividad; // El primer token es el nombre de la actividad

        // El resto de la línea es el nombre del usuario
        std::getline(ss, nombreUsuario);

        std::cout << "Actividad: " << nombreActividad << " || Usuario: " << nombreUsuario << std::endl;
    }

    std::cout << "------------------------\n";

    // Cierra el archivo
    archivoPreinscritos.close();
}
