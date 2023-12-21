#ifndef _ACTIVIDAD_H_
#define _ACTIVIDAD_H_

#include <string>
#include <set>

class Actividad
{
private:
    std::string nombre_;
    int aforo_;
    std::string fecha_;
    std::string lugar_;
    std::string director_;
    int activa_; // valdrá 1 si la actividad está activa, y 0 si no lo está. Este campo es para diferenciar las actividades que están activas de las que no.
    std::string descripcion_;

public:
    // constructor
    Actividad(std::string nombre = "empty", int aforo = 0, std::string fecha = "empty", std::string lugar = "empty", std::string director = "empty", int activa = 0,std::string descripcion = "empty")
    {
        nombre_ = nombre;
        aforo_ = aforo;
        fecha_ = fecha;
        lugar_ = lugar;
        director_ = director;
        activa_ = activa;
        descripcion_=descripcion;
    }

    
    void crearActividad();
    void escribirFichero();
    void activarActividad(std::string actividad);
    void visualizarActividades(bool soloActivas);
    void visualizaActividadesRellenas();
    void modificarActividad(const std::string &nombre);

    void preinscribirUsuario();
    void verPreinscritos();
    
};

#endif