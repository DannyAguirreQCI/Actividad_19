#include "civilizacion.h"
#include <fstream>

Civilizacion :: Civilizacion()
{
    nombre = "-";
    ubicacionx = "-";
    ubicaciony = "-";
    puntuacion = 0;
    puntaje = 0;
}

    Civilizacion :: Civilizacion(const string &nombre,
                                const string &ubicacionx,
                                const string &ubicaciony,
                                const size_t &puntuacion)
    {
            this->nombre = nombre;
            this->ubicacionx = ubicacionx;
            this->ubicaciony = ubicaciony;
            this->puntuacion = puntuacion;
    }

void Civilizacion::setNombre(const string &valor)
{
    nombre = valor;
}

string Civilizacion::getNombre() const
{
    return nombre;
}

void Civilizacion::setUbicacionX(const string &valor)
{
    ubicacionx = valor;
}

string Civilizacion::getUbicacionX() const
{
    return ubicacionx;
}

void Civilizacion::setUbicacionY(const string &valor)
{
    ubicaciony = valor;
}

string Civilizacion::getUbicacionY() const
{
    return ubicaciony;
}

void Civilizacion::setPuntuacion(const size_t &valor)
{
    puntuacion = valor;
}

size_t Civilizacion::getPuntuacion() const
{
    return puntuacion;
}

void Civilizacion::setName(const string &name)
{
    this->name = name;
}

string Civilizacion::getName()
{
    return name;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarName(const string &name)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;

        if(name == a.getName())
        {
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarEdad(size_t edad)
{
    aldeanos.remove_if([edad](const Aldeano &a){return a.getEdad() >= edad;});
}

void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() <=salud;});
}

void Civilizacion::ordenarName()
{
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::search(const string &name)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;

        if(name != a.getName()){
            cout << "Aldeano no encontrado" << endl;
        }
        else if(name == a.getName())
        {
            cout << "----------------------------------------"<<endl;
            cout << left;
            cout<< setw(10)<< "NOMBRE";
            cout<< setw(5)<< "EDAD";
            cout<< setw(7)<< "GENERO";
            cout<< setw(6)<< "SALUD";
            cout<<endl;
            cout << *it << endl;
            break;
        }
    }
}

void Civilizacion::modific(const string &name)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        string nombre;
        size_t edad;
        string genero;
        size_t salud;
        string op;
        int cont=0;

        if(name != a.getName()){
            cout << "Aldeano no encontrado" << endl;
        }
        else if(name == a.getName())
        {
            while (true)
            {
                system("cls");
                cout << "----------------------------------------"<<endl;
                cout << left;
                cout<< setw(10)<< "NOMBRE";
                cout<< setw(5)<< "EDAD";
                cout<< setw(7)<< "GENERO";
                cout<< setw(6)<< "SALUD";
                cout<<endl;
                cout << *it << endl;
                cout << endl;
                cout << "++++++++++MENU MODIFICAR++++++++++" << endl;
                cout << "1) Modificar Nombre" << endl;
                cout << "2) Modificar Edad" << endl;
                cout << "3) Modificar Genero" << endl;
                cout << "4) Modificar Salud" << endl;
                cout << "5) Regresar" << endl;
                cout << "Opcion: ";
                getline(cin, op);
                cout << endl;

                if(op == "1"){
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Nombre: ";
                    getline(cin, nombre);
                    a.setName(nombre);
                    cont++;
                    cout <<"Aldeano modificado con exito" <<endl <<endl;
                }
                else if(op == "2"){
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Edad: ";
                    cin >> edad; cin.ignore();
                    a.setEdad(edad);
                    cont++;
                    cout <<"Aldeano modificado con exito" <<endl <<endl;
                }
                else if (op == "3"){
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Genero: ";
                    getline(cin, genero);
                    a.setGenero(genero);
                    cont++;
                    cout <<"Aldeano modificado con exito" <<endl <<endl;
                }
                else if(op == "4"){
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Salud:";
                    cin >> salud; cin.ignore();
                    a.setSalud(salud);
                    cont++;
                    cout <<"Aldeano modificado con exito" <<endl <<endl;
                }
                else if(op == "5"){
                    break;
                }
                cont++;
            }
        }
    }
}

void Civilizacion::puntajemas()
{
    puntaje = puntaje + 100;
}

size_t Civilizacion::getPuntaje() const
{
    return puntaje;
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeans(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeans << aldeano.getName() << endl;
        aldeans << aldeano.getEdad()   << endl;
        aldeans << aldeano.getGenero() << endl;
        aldeans << aldeano.getSalud()  << endl;
    }
    aldeans.close();
}

void Civilizacion::recuperar_aldeanos()
{
    string tempo;
    string tempop;
    int edad;
    int salud;
    Aldeano a;

    ifstream aldeans(getNombre()+ ".txt", ios::out);
    if (aldeans.is_open())
    {  
        while(true)
        {  
            getline(aldeans, tempo);
            if(aldeans.eof())
            {
                break;
            }
            a.setName(tempo);

            getline(aldeans, tempo);
            edad = stoi(tempo);
            a.setEdad(edad);

            getline(aldeans, tempo);
            a.setGenero(tempo);

            getline(aldeans, tempo);
            salud = stoi(tempo);
            a.setSalud(salud);

            agregarFinal(a);

            cuenta++;
            
        }
        aldeans.close();
    }
}

void Civilizacion::eliminar_inicio()
{
    if(aldeanos.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else
            {
                aldeanos.pop_front();
            }
}