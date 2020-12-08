#include "aldeano.h"

void Aldeano::setName(const string &name)
{
    this->name = name;
}

string Aldeano::getName() const
{
    return name;
}

void Aldeano::setEdad(const size_t &edad)
{
    this->edad = edad;
}

size_t Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this->genero = genero;
}

string Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setSalud(const size_t &salud)
{
    this->salud = salud;
}

size_t Aldeano::getSalud() const
{
    return salud;
}