// includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include "menus.h"
#include "actividad.h"

int main()
{

    int opcion = 0;

    std::cout << "BIENVENIDO A EVENTOMOMENTO.\n\n";

    do
    {

        std::cout << "--------------------MENU---------------------\n\n";
        std::cout << "1.Organizador\n";
        std::cout << "2.DirectorAcademico\n";
        std::cout << "3.Usuario registrado\n";
        std::cout << "4.Usuario visitante\n";
        std::cout << "5.Salir del sistema\n";
        std::cout << "---------------------------------------------\n\n";

        // Solicitar al usuario que elija una opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            // crear actividad
            menu1();

            break;

        case 2:
            // director academico
            menu2();
            break;

        case 3:
            // usu.registrado
            menu3();
            break;

        case 4:
            // usu. visitante
            menu4();
            break;

        case 5:
            std::cout << "Saliendo del programa.\n";
            exit(EXIT_SUCCESS);
            break;

        default:
            std::cout << "Opción no valida. Intente de nuevo.\n";
        }

    } while (opcion != 5);

    return 0;
}
