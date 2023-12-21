// includes
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "menus.h"
#include "actividad.h"


/**************************** MENU ORGANIZADOR ***************************************/
void menu1()
{
    int opcion = 0;
    Actividad a1;
    std::string nom_actividad;

    // Declarar las variables fuera del bloque switch
    const char *nombreArchivo = "todas_actividades.txt";
    std::ifstream archivoEntrada;
    std::string linea;

    std::cout << "\n¡Bienvenido Organizador!";

    do
    {
        std::cout << "\n\n--------------MENU->organizador--------------\n\n";
        std::cout << "      1. Crear actividad Academica\n";
        std::cout << "      2. Añadir informacion actividad\n";
        std::cout << "      3. Activar actividad academica\n";
        std::cout << "      4. Visualizar todas las actividades academicas\n";
        std::cout << "      5. Visualizar sólo las actividades académicas Activas\n";
        std::cout << "      6. Ver los preinscritos a las actividades\n";
        std::cout << "      7. Salir del sistema\n";
        std::cout << "\n---------------------------------------------\n";

        // Solicitar al usuario que elija una opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Creación de una actividad académica

            a1.crearActividad();
            a1.escribirFichero();
            break;

        case 2:
            // añadir informacion

            a1.visualizarActividades(false);

            std::cout << "Introduce el nombre de la actividad que quieres añadir informacion: ";
            std::cin >> nom_actividad;

            a1.modificarActividad(nom_actividad);
            break;

        case 3:
            // Activación de visualización de las actividades académicas

            a1.visualizarActividades(false);
                    
            std::cout << "Introduce el nombre de la actividad que quieres activar: ";
            std::cin >> nom_actividad;
            
            a1.activarActividad(nom_actividad);
            break;


        case 4:
            // visualizar actividades.

            a1.visualizarActividades(false);
            break;

        case 5:
            // visualizar actividades que SOLO ESTEN ACTIVAS

            a1.visualizarActividades(true);
            break;

        case 6:
            //ver a los preinscritos
            a1.verPreinscritos();

        case 7:
            std::cout << "Saliendo del programa.\n";
            exit(EXIT_SUCCESS);

        default:
            std::cout << "Opción no valida. Intente de nuevo.\n";
        }

    } while (opcion != 7);
}



/*************************** MENU DIRECTOR ACADEMICO *********************************/
void menu2()
{
    int opcion = 0;
    Actividad a1;
    std::string nom_actividad;

    // Declarar las variables fuera del bloque switch
    const char *nombreArchivo = "todas_actividades.txt";
    std::ifstream archivoEntrada;
    std::string linea;

    std::cout << "\n¡Bienvenido Director Académico!";

    do
    {       
        std::cout << "\n\n-----------MENU->director academico------------\n\n";
        std::cout << "      1. Añadir informacion actividad\n";
        std::cout << "      2. Activar actividad academica\n";
        std::cout << "      3. Visualizar todas las actividades academicas\n";
        std::cout << "      4. Visualizar sólo las actividades académicas Activas\n";
        std::cout << "      5. Ver los preinscritos a las actividades\n";
        std::cout << "      6. Salir del sistema\n";
        std::cout << "\n---------------------------------------------\n";

        // Solicitar al usuario que elija una opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            // añadir informacion

            a1.visualizarActividades(false);

            std::cout << "Introduce el nombre de la actividad que quieres añadir informacion: ";
            std::cin >> nom_actividad;

            a1.modificarActividad(nom_actividad);
            break;
            

        case 2:
            // Activación de visualización de las actividades académicas

            a1.visualizarActividades(false);
                    
            std::cout << "Introduce el nombre de la actividad que quieres activar: ";
            std::cin >> nom_actividad;
            
            a1.activarActividad(nom_actividad);
            break;

        case 3:
            // visualizar actividades.

            a1.visualizarActividades(false);
            break;


        case 4:
            // visualizar actividades que SOLO ESTEN ACTIVAS

            a1.visualizarActividades(true);
            break;

        case 5:
            //ver a los preinscritos
            a1.verPreinscritos();

            break;

        case 6:
            
            std::cout << "Saliendo del programa.\n";
            exit(EXIT_SUCCESS);


        default:
            std::cout << "Opción no valida. Intente de nuevo.\n";
        }

    } while (opcion != 5);
}



/*************************** MENU USUARIO REGISTRADO *********************************/
void menu3()
{
    int opcion = 0;
    Actividad a1;

    std::cout << "\n¡Bienvenido Usuario Registrado!";

    do
    {   
        std::cout << "\n\n-----------MENU->Usuario Registrado----------\n\n";
        std::cout << "      1. Ver informacion de las actividades\n";
        std::cout << "      2. Preinscribirse\n";
        std::cout << "      3. Salir del sistema\n";
        std::cout << "\n---------------------------------------------\n";

        // Solicitar al usuario que elija una opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1: 
        // ver informacion
            a1.visualizaActividadesRellenas();
            break;

        case 2:
        //preinscribirse
            a1.visualizarActividades(true);
            a1.preinscribirUsuario();

            break;

        case 3:
            std::cout << "Saliendo del programa.\n";
            exit(EXIT_SUCCESS);
            break;

        default:
            std::cout << "Opción no valida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}




/********************************** MENU USUARIO VISITANTE *********************************************/
void menu4()
{
    int opcion = 0;
    Actividad a1;

    std::cout << "\n¡Bienvenido Usuario Visitante!\n\n";

    do
    {     
        std::cout << "\n\n------------MENU->usuario visitante----------\n\n";
        std::cout << "      1. Ver informacion de las actividades\n";
        std::cout << "      2. Salir del sistema\n";
        std::cout << "\n---------------------------------------------\n";

        // Solicitar al usuario que elija una opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            // ver informacion
            a1.visualizaActividadesRellenas();
            break;

        case 2:
            std::cout << "Saliendo del programa.\n";
            exit(EXIT_SUCCESS);

            break;

        default:
            std::cout << "Opción no valida. Intente de nuevo.\n";
        }

    } while (opcion != 2);
}

/*******************************************************************************************************/