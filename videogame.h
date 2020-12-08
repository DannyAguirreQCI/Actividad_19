#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{
    vector<Civilizacion> civilizaciones;

public:
    VideoGame();
    VideoGame(const string &usuario);
    //Videogame
    void setUsuario(const string &valor);
    string getUsuario() const;
    void agregarcivilizacion(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void crearcivilizacion(const Civilizacion &c, size_t n);
    void primeracivilizacion();
    void ultimacivilizacion();
    void ordenar();
    void ordenarubicacionx();
    void ordenarubicaciony();
    void ordenarpuntuacion();
    void modificar();
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();
    void recuperar_aldeans();
    void check();

    size_t size();
    Civilizacion* eliminar(const Civilizacion &c);
    Civilizacion* buscar(const Civilizacion &c);
    void eliminarUltimo();

    //Aldeanos

    friend VideoGame& operator<<(VideoGame &v, const Civilizacion &c)
    {
        v.agregarcivilizacion(c);

        return v;
    }

    friend istream& operator>> (istream &in, VideoGame &v)
    {
        cout<<"Usuario:";
        getline(cin, v.usuario);

        return in;
    }

private:
    string usuario;
    string name1;
    int i;
};

#endif