// tests.cpp
#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

#include "actividad.h"  // Asegúrate de incluir tus archivos de código

TEST_CASE("Crear y Visualizar Actividad") {
    Actividad a;
    a.crearActividad();

    // Realiza pruebas para verificar si la actividad se creó correctamente
    REQUIRE(/* Condición de prueba */);
    
    // Continúa con más pruebas según sea necesario
}

// Agrega más TEST_CASE según tus necesidades
