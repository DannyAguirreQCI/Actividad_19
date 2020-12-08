#include "videogame.h"
#include "menucivilizacion.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()
{
    usuario = "-";
}

VideoGame::VideoGame(const string &usuario)
{
    this->usuario = usuario;
}

void VideoGame::setUsuario(const string &valor)
{
    usuario = valor;
}

string VideoGame::getUsuario() const
{
    return usuario;
}

void VideoGame::agregarcivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void VideoGame::crearcivilizacion(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::primeracivilizacion()
{
    if (civilizaciones.empty())
    {
        cout << "Vector esta vacio" << endl;
    }
    else
    {
        cout << "----------------------------------------"<<endl;
        cout << left;
        cout<< setw(10)<< "NOMBRE";
        cout<< setw(12)<< "UBICACION X";
        cout<< setw(12)<< "UBICACION Y";
        cout<< setw(10)<< "PUNTUACION";
        cout<<endl;
        cout << civilizaciones.front();
    }
}

void VideoGame::ultimacivilizacion()
{
    if (civilizaciones.empty())
    {
        cout << "Vector esta vacio" << endl;
    }
    else
    {
        cout << "----------------------------------------"<<endl;
        cout << left;
        cout<< setw(10)<< "NOMBRE";
        cout<< setw(12)<< "UBICACION X";
        cout<< setw(12)<< "UBICACION Y";
        cout<< setw(10)<< "PUNTUACION";
        cout<<endl;
        cout << civilizaciones.back();
    }
}

void VideoGame::ordenar()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void VideoGame::ordenarubicacionx()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](const Civilizacion c1, const Civilizacion c2){return c1.getUbicacionX() <  c2.getUbicacionX();});
}

void VideoGame::ordenarubicaciony()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](const Civilizacion c1, const Civilizacion c2){return c1.getUbicacionY() <  c2.getUbicacionY();});
}

void VideoGame::ordenarpuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](const Civilizacion c1, const Civilizacion c2){return c1.getPuntuacion() <  c2.getPuntuacion();});
}

Civilizacion* VideoGame::eliminar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        civilizaciones.erase(it);
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
    
}

void VideoGame::modificar()
{
    int cont=0;
    cout<<"Nombre de la civilizacion: ";
    getline(cin, name1);
    cout<< endl;
    for (i=0; i < civilizaciones.size(); i++)
    {
        if(civilizaciones[i].getNombre() == name1)
        {
            string nombre;
            string ubix;
            string ubiy;
            size_t puntuacion;
            string op;

            while (true)
            {
                system("cls");
                cout << "++++++++++MENU MODIFICAR++++++++++" << endl;
                cout << "1) Modificar Nombre" << endl;
                cout << "2) Modificar Ubicacion X" << endl;
                cout << "3) Modificar Ubicacion Y" << endl;
                cout << "4) Modificar Puntuacion" << endl;
                cout << "5) Regresar" << endl;
                cout << "Opcion: ";
                getline(cin, op);
                cout << endl;

                if(op == "1")
                {
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Nombre: ";
                    getline(cin, nombre);
                    civilizaciones[i].setNombre(nombre);
                    cont++;
                    cout <<"Civilizacion modificada con exito" <<endl <<endl;
                    break;
                }
                else if(op == "2")
                {
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Ubicacion X: ";
                    getline(cin, ubix);
                    civilizaciones[i].setUbicacionX(ubix);
                    cont++;
                    cout <<"Civilizacion modificada con exito" <<endl <<endl;
                    break;
                }
                else if (op == "3")
                {
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Ubicacion Y: ";
                    getline(cin, ubiy);
                    civilizaciones[i].setUbicacionX(ubiy);
                    cont++;
                    cout <<"Civilizacion modificada con exito" <<endl <<endl;
                    break;
                }
                else if(op == "4")
                {
                    cout <<"Ingresa el nuevo dato" <<endl
                    <<"Puntuacion:";
                    cin >> puntuacion;
                    civilizaciones[i].setPuntuacion(puntuacion);
                    cont++;
                    cout <<"Civilizacion modificada con exito" <<endl <<endl;
                    break;
                }
                else if(op == "5")
                {
                    break;
                }
            }
        }
        cont++;
    }
    if(cont==civilizaciones.size())
    {
        cout << "Civilizacion no encontrada" << endl;
    }
}

void VideoGame::mostrar()
{
    cout << "----------------------------------------"<<endl;
    cout << left;
    cout<< setw(10)<< "NOMBRE";
    cout<< setw(12)<< "UBICACION X";
    cout<< setw(12)<< "UBICACION Y";
    cout<< setw(10)<< "PUNTUACION";
    cout<<endl;
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &c = civilizaciones[i];

        cout<< c;
    }
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::check()
{
    if(civilizaciones.empty()){
        cout << "No hay civilizaciones" << endl;
    }
     else{
        for(size_t i = 0; i < civilizaciones.size(); i++)
        {
            Civilizacion &civilizacion = civilizaciones[i];
            cout << i + 1 << ")";
            cout << civilizacion.getNombre() << endl;
        }
        cout << "0) Salir" << endl;
        size_t ops;
        cout << "Opcion: ";
        cin >> ops; cin.ignore();

        if(ops > civilizaciones.size()){
            cout << "Opcion incorrecta" << endl;
        }
        else if (ops != 0){
            Civilizacion &civilizacion = civilizaciones[ops-1];
            menu(civilizacion);
        }
    }
}

void VideoGame::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) 
    {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        archivo << c.getUbicacionX() << endl;
        archivo << c.getUbicacionY() << endl;
        archivo << c.getPuntuacion() << endl;
        c.respaldar_aldeanos();
    }
    archivo.close();

}


void VideoGame::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open())
    {
        string temp;
        int puntuacion;
        Civilizacion c;

        while(true)
        {
            getline(archivo, temp);
            if(archivo.eof())
            {
                break;
            }
            c.setNombre(temp);
            c.recuperar_aldeanos();

            getline(archivo, temp);
            c.setUbicacionX(temp);

            getline(archivo, temp);
            c.setUbicacionY(temp);

            getline(archivo, temp);
            puntuacion = stoi(temp);
            c.setPuntuacion(puntuacion);
            agregarcivilizacion(c);
            for (int cuenti=0; cuenti<=c.cuenta;cuenti++)
            {
                c.eliminar_inicio();
            }
        }
    }
    archivo.close();
}