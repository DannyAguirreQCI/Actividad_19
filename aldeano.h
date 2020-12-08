#ifndef ALDEANO_H
#define ALDEANO_H

#include<iostream>
#include<iomanip>
using namespace std;

class Aldeano
{
    public:
    Aldeano() {}
    Aldeano(const string &name,
            const size_t &edad,
            const string &genero,
            const size_t &salud)
            :name(name), edad(edad), genero(genero), salud(salud) {}

    void setName(const string &name);
    string getName() const;

    void setEdad(const size_t &edad);
    size_t getEdad() const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(const size_t &salud);
    size_t getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(10) << a.name;
        out << setw(5) << a.edad;
        out << setw(7) << a.genero;
        out << setw(6) << a.salud;

        return out;
    }

    bool operator<(const Aldeano &a)
    {
        return name < a.getName();
    }

private:
    string name;
    size_t edad;
    string genero;
    size_t salud;
};

#endif