#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;
    string name;
    size_t edad;
    string genero;
    size_t salud;

    cout << "Nombre: ";
    getline(cin, name);
    a.setName(name);

    cout << "Edad: ";
    cin >> edad;
    a.setEdad(edad);

    cout << "Salud: ";
    cin >> salud; cin.ignore();
    a.setSalud(salud);

    cout << "Genero: ";
    getline(cin, genero);
    a.setGenero(genero);

    return a;
}

void menu(Civilizacion &c)
{
    Civilizacion aldeanos;
    string op;
    string ops;
    size_t puntos;

    while (true)
    {
        system("cls");
        cout << "----------MENU ALDEANOS----------" << endl;
        cout << c.getPuntaje() << endl;
        cout << "1) Agregar Aldeano" << endl;
        cout << "2) Eliminar Aldeano" << endl;
        cout << "3) Clasificar Aldeanos" << endl;
        cout << "4) Buscar Aldeano" << endl;
        cout << "5) Modificar Aldeano" << endl;
        cout << "6) Mostrar Aldeano" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        getline(cin, op);

        if(op == "1"){
            while (true)
            {
                system("cls");
                cout << "----------MENU AGREGAR----------" << endl;
                cout << "1) Agregar Inicio" << endl;
                cout << "2) Agregar Final" << endl;
                cout << "0) Regresar" << endl;
                cout << "Opcion: ";
                getline(cin, ops);

                if(ops == "1"){
                    //Inicio
                    //Por cada aldeano agregado, agregar a la variable `puntaje` 100 puntos.
                    c.agregarInicio(capturar());
                    c.puntajemas();
                    puntos = c.getPuntaje() + c.getPuntuacion();
                    c.setPuntuacion(puntos);
                }
                else if(ops == "2"){
                    //Final
                    //Por cada aldeano agregado, agregar a la variable `puntaje` 100 puntos.
                    c.agregarFinal(capturar());
                    c.puntajemas();
                    puntos = c.getPuntaje() + c.getPuntuacion();
                    c.setPuntuacion(puntos);
                }
                else if(ops == "0"){
                    break;
                }
            system("PAUSE");
            }
        }
        else if(op == "2"){
            while (true)
            {
                system("cls");
                cout << "----------MENU ELIMINAR----------" << endl;
                cout << "1) Eliminar por Nombre" << endl;
                cout << "2) Eliminar por Salud < x" << endl;
                cout << "3) Eliminar por Edad >=60" << endl;
                cout << "0) Regresar" << endl;
                cout << "Opcion: ";
                getline(cin, ops);

                if(ops == "1"){
                    //Nombre
                    string nombre;

                    cout << "Nombre: ";
                    getline(cin, nombre);
                    c.eliminarName(nombre);                
                }
                else if(ops == "2"){
                    //Salud
                    size_t salud;

                    cout << "Edad: ";
                    cin >> salud; cin.ignore();
                    c.eliminarSalud(salud);
                }
                else if(ops == "3"){
                    //Edad
                    c.eliminarEdad();
                }
                else if(ops == "0"){
                    break;
                }
            system("PAUSE");
            }
        }else if(op == "3"){
            //Clasificar
            while (true)
            {
                system("cls");
                cout << "----------MENU CLASIFICAR----------" << endl;
                cout << "1) Clasificar por Nombre(Ascendente)" << endl;
                cout << "2) Clasificar por Edad(Descendente)" << endl;
                cout << "3) Clasificar por Salud(Descendente)" << endl;
                cout << "0) Regresar" << endl;
                cout << "Opcion: ";
                getline(cin, ops);

                if(ops == "1"){
                    //Nombre
                    c.ordenarName();                
                }
                else if(ops == "2"){
                    //Edad
                    c.ordenarEdad();
                }
                else if(ops == "3"){
                    //Salud
                    c.ordenarSalud();
                }
                else if(ops == "0"){
                    break;
                }
            system("PAUSE");
            }
        }else if(op == "4"){
            //Buscar
            //Mostrar
            string nombre;

            cout << "Nombre: ";
            getline(cin, nombre);
            c.search(nombre);
        }else if(op == "5"){
            //Modificar
            string name;
            cout<<"Nombre del Aldeano: ";
            getline(cin, name);
            cout<< endl;
            c.modific(name);
            
        }else if(op == "6"){
            //Mostrar
            //Tabla
            cout << endl;
            cout << "----------------------------------------"<<endl;
            cout << left;
            cout<< setw(10)<< "NOMBRE";
            cout<< setw(5)<< "EDAD";
            cout<< setw(7)<< "GENERO";
            cout<< setw(6)<< "SALUD";
            cout<<endl;
            c.print();
        }else if(op == "0"){
            break;
        }
        else{
            cout << "Opcion no valida";
        }
    system("PAUSE");
    }
}

/*void menu(Civilizacion &c)
{
    string op;

    while (true)
    {
        cout << "1) Agregar Inicio" << endl;
        cout << "2) Agregar Final" << endl;
        cout << "3) Mostrar" << endl;
        cout << "4) Ordenar Nombre" << endl;
        cout << "5) Ordenar Edad" << endl;
        cout << "6) Ordenar Salud" << endl;
        cout << "7) Eliminar Nombre" << endl;
        cout << "8) Eliminar Edad" << endl;
        cout << "9) Eliminar Edad = e" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1"){
            c.agregarInicio(capturar());
        }else if (op == "2"){
            c.agregarFinal(capturar());
        }else if (op == "3"){
            c.print();
        }else if (op == "4"){
            c.ordenarName();
        }else if (op == "5"){
            c.ordenarEdad();
        }else if (op == "6"){
            c.ordenarSalud();
        }else if (op == "7"){
            string nombre;

            cout << "Nombre: ";
            getline(cin, nombre);
            c.eliminarName(nombre);
        }else if (op == "8"){
            c.eliminarEdad();
        }else if (op == "9"){
            size_t edad;

            cout << "Edad: ";
            cin >> edad; cin.ignore();
            c.eliminarEdad(edad);
        }else if (op == "0"){
            break;
        }
    }
}*/