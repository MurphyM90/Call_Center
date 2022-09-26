#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// ------------------------------------------------------------- Interfaz e implementacion de la clase Computadoras

class Computadoras
{
    private:
        string numSerie;
        string marca;
        string ram;
        string procesador;
        string mac;
        string usuario;
        string contrasenia;

    public:
        Computadoras();
        Computadoras(string serie, string marca, string ram, string procesador, string mac, string usuario, string contrasenia);
        void setNumSerie(string);
        void setMarca(string);
        void setRam(string);
        void setProcesador(string);
        void setMac(string);
        void setUsuario(string);
        void setContrasenia(string);
        string getNumSerie();
        string getMarca();
        string getRam();
        string getProcesador();
        string getMac();
        string getUsuario();
        string getContrasenia();
        bool operator == (Computadoras &);
        bool operator != (Computadoras &);
        bool operator > (Computadoras &);
        bool operator < (Computadoras &);
        bool operator >= (Computadoras &);
        bool operator <= (Computadoras &);
        void mostrarComponentes();
};

Computadoras::Computadoras()
{
    numSerie = " ";
    marca = " ";
    ram = " ";
    procesador = " ";
    mac = " ";
    usuario = " ";
    contrasenia = " ";
}


Computadoras::Computadoras(string serie, string marca, string ram, string procesador, string mac, string usuario, string contrasenia)
{
    this -> numSerie = serie;
    this -> marca = marca;
    this -> ram = ram;
    this -> procesador = procesador;
    this -> mac = mac;
    this -> usuario = usuario;
    this -> contrasenia = contrasenia;
}

void Computadoras::setNumSerie(string serie)
{
    this->numSerie = serie;
}

void Computadoras::setMarca(string marca)
{
   this->marca = marca;
}

void Computadoras::setRam(string ram)
{
    this->ram = ram;
}
void Computadoras::setProcesador(string procesador)
{
    this->procesador = procesador;
}

void Computadoras::setMac(string mac)
{
    this->mac = mac;
}

void Computadoras::setUsuario(string usuario)
{
    this->usuario = usuario;
}

void Computadoras::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

string Computadoras::getNumSerie(void)
{
    return numSerie;
}

string Computadoras::getMarca(void)
{
    return marca;
}

string Computadoras::getRam(void)
{
    return ram;
}

string Computadoras::getProcesador(void)
{
    return procesador;
}

string Computadoras::getMac(void)
{
    return mac;
}

string Computadoras::getUsuario(void)
{
    return usuario;
}

string Computadoras::getContrasenia(void)
{
    return contrasenia;
}

bool Computadoras :: operator == (Computadoras &compu)
{
    return (numSerie == compu.getNumSerie());
}

bool Computadoras :: operator != (Computadoras &compu)
{
    return (numSerie != compu.getNumSerie());
}

bool Computadoras :: operator > (Computadoras &compu)
{
    return (numSerie > compu.getNumSerie());
}

bool Computadoras :: operator < (Computadoras &compu)
{
    return (numSerie < compu.getNumSerie());
}

bool Computadoras :: operator >= (Computadoras &compu)
{
    return (numSerie >= compu.getNumSerie());
}

bool Computadoras :: operator <= (Computadoras &compu)
{
    return (numSerie <= compu.getNumSerie());
}

void Computadoras :: mostrarComponentes()
{
    cout << "Numero de serie:   " << numSerie      << endl;
    cout << "Marca:             " << marca         << endl;
    cout << "RAM:               " << ram           << endl;
    cout << "Procesador:        " << procesador    << endl;
    cout << "MAC:               " << mac           << endl;
    cout << "Usuario:           " << usuario       << endl;
    cout << "Contrasenia:       " << contrasenia   << endl;
}


// ----------------------------------------------------------------- Interfaz e implementación de la clase Nodo

template <class T>
class Nodo
{
    public:
    T dato;
    Nodo *siguiente;
    Nodo *anterior;

    Nodo(T dato, Nodo *sg = NULL,Nodo *ant = NULL)
    {
        this -> dato = dato;
        siguiente = sg;
        anterior = ant;
    }

    Nodo(Nodo *sg = NULL, Nodo *ant = NULL)
    {
        siguiente = sg;
        anterior = ant;
    }

    ~Nodo(){};
};

// --------------------------------------------------------------------- Interfaz e implementación de la clase Lista

template <class T>
class Lista
{
    private:
        Nodo<T> *eslabon;
        Nodo<T> *aux;
        int tamanio;
    public:
        Lista (void);
        ~Lista (void){};
        int vacia(void);
        T& get(int posicion);
        int getTamanio(void);
        void ingresarAlPrincipio (T &dato);
        void ingresarAlFinal (T &dato);
        void ingresarEnPosicion(T &dato, int posicion);
        void eliminarAlInicio();
        void eliminarAlFinal();
        void eliminarEnPosicion(int posicion);
};


template <class T> Lista<T>::Lista(void)
{
    eslabon = new Nodo<T>;
    tamanio = 0;
}

template <class T> int Lista <T> ::vacia(void)
{
    if(eslabon -> siguiente == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

template <class T> T &Lista <T> :: get(int posicion)
{
    if(posicion < 0 || posicion >= getTamanio())
    {
        cout << "Error en el elemento " << posicion << " en una lista de " << getTamanio() << "\n";
        system("pause");
        exit(-1);
    }

    aux = eslabon -> siguiente;
    int i = 0;
    while (i++ != posicion)
    {
        aux = aux -> siguiente;
    }

    return aux -> dato;
}

template <class T> int Lista <T> :: getTamanio(void)
{
    return tamanio;
}


template <class T> void Lista <T> :: ingresarAlPrincipio(T &dato)
{
    if (vacia())
    {
        eslabon -> siguiente = eslabon -> anterior = new Nodo<T>(dato, eslabon, eslabon);
    }

    else
    {
        eslabon -> siguiente = new Nodo<T>(dato, eslabon -> siguiente, eslabon);
        eslabon -> siguiente -> siguiente -> anterior = eslabon -> siguiente;
    }
    tamanio++;
}


template <class T> void Lista <T> :: ingresarAlFinal(T &dato)
{
    if (vacia())
    {
        eslabon -> siguiente = eslabon -> anterior = new Nodo<T>(dato, eslabon, eslabon);
    }

    else
    {
        eslabon -> anterior = new Nodo<T>(dato, eslabon, eslabon -> anterior);
        eslabon -> anterior -> anterior -> siguiente = eslabon -> anterior;
    }
    tamanio++;
}


template <class T> void Lista <T> :: ingresarEnPosicion(T &dato, int posicion)
{
    if(posicion == 0 || vacia())
    {
        ingresarAlPrincipio(dato);
        return;
    }

    if(posicion >= getTamanio()) // --------------------------------- Revisar esta parte
    {
        ingresarAlFinal(dato);
        return;
    }

    else
    {
        int i = 1;
        aux = eslabon -> siguiente;
        while(i++ != posicion)
        {
            aux = aux->siguiente;
        }

        aux = new Nodo<T>(dato, aux -> siguiente, aux);
        aux -> anterior -> siguiente = aux;
        aux -> siguiente -> anterior = aux;
    }
    tamanio++;
}


template <class T> void Lista <T> :: eliminarAlInicio()
{
    if(vacia())
    {
        return;
    }

    aux = eslabon -> siguiente;
    eslabon -> siguiente = eslabon -> siguiente -> siguiente;
    eslabon -> siguiente -> anterior = eslabon;
    delete aux;
    tamanio--;
}

template <class T> void Lista <T> :: eliminarAlFinal()
{
    if(vacia())
    {
        return;
    }

    aux = eslabon -> anterior;
    eslabon -> anterior = eslabon -> anterior -> anterior;
    eslabon -> anterior -> siguiente = eslabon;
    delete aux;
    tamanio--;
}

template <class T> void Lista <T> :: eliminarEnPosicion(int posicion)
{
    if(vacia()) {
        return;
    }

    if(posicion == 0)
    {
        eliminarAlInicio();
        return;
    }

    if(posicion == getTamanio() - 1)     // ------------------------------------------------ Se cambiara el > por un =
    {
        eliminarAlFinal();
        return;
    }

    aux = eslabon -> siguiente -> siguiente;

    int i = 1;
    while(i++ != posicion)
    {
        aux = aux -> siguiente;
    }

    aux -> anterior -> siguiente = aux -> siguiente;
    aux -> siguiente -> anterior = aux -> anterior;
    tamanio--;

    delete aux;
}


// -------------------------------------------------------------------------------------------------- Funcion main



int division(Lista<Computadoras> &lista, int comienzo, int final)
{
    int izq;
    int der;
    Computadoras pivote;
    Computadoras temporal;

    pivote = lista.get(comienzo);
    izq = comienzo;
    der = final;

    while (izq < der)
    {
        while (lista.get(der) > pivote)
        {
            der--;
        }

        while ((izq < der) && (lista.get(izq) <= pivote))
        {
            izq++;
        }

        if (izq < der)
        {
            Computadoras auxiliar;
            temporal = lista.get(der);
            auxiliar = lista.get(izq);
            lista.eliminarEnPosicion(izq);
            lista.ingresarEnPosicion(temporal, izq);
            lista.eliminarEnPosicion(der);
            lista.ingresarEnPosicion(auxiliar, der);
        }
    }

    Computadoras auxiliar;

    temporal = lista.get(comienzo);
    auxiliar = lista.get(der);
    lista.eliminarEnPosicion(der);
    lista.ingresarEnPosicion(temporal, der);
    lista.eliminarEnPosicion(comienzo);
    lista.ingresarEnPosicion(auxiliar, comienzo);

    return der;
}

void ordenamientoQuicksort(Lista<Computadoras> &lista, int comienzo, int final)
{
    int pivote;
    if (comienzo < final)
    {
        pivote = division(lista, comienzo, final);
        ordenamientoQuicksort(lista, comienzo, pivote - 1);
        ordenamientoQuicksort(lista, pivote + 1, final);
    }
}


int busquedaBinaria(Lista<Computadoras> &lista, string serie, int min, int max)
{
    int medio = (min+max)/2;

    if(max < min)
    {
        return -1;
    }

    if(serie == lista.get(medio).getNumSerie())
    {
        return medio;
    }

    else
    {
        if(serie < lista.get(medio).getNumSerie())
        {
            return busquedaBinaria(lista, serie, min, medio-1);
        }

        else
        {
            return busquedaBinaria(lista, serie, medio + 1, max);
        }
    }
}


void mostrarPcs(Lista<Computadoras> lista)
{
    int i = 0;
    while(i < lista.getTamanio())
    {
        cout << "Computadora " << i+1 << endl;
        lista.get(i).mostrarComponentes(); cout << endl;
        i++;
    }

    if(lista.vacia())
    {
        cout << "No hay computadoras" << endl;
    }
}


int main()
{
    Lista <Computadoras> lista;
    Computadoras compu1, compu2, compu3, compu4;

    string serie, marca, ram, proc, mac, user, pass, stringSerie;
    char menuPrin, menuIngre, menuModif, menuMostrar, menuBuscar, menuEliminar;
    int flagPrin = 1, flagIngre = 1, flagModif = 1, flagMostrar = 1, flagBuscar = 1, flagEliminar = 1, posicion, posicionMod;

    do
    {
        Computadoras compu;
        system("cls");
        cout << "Registro de computadoras." << endl << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Editar componentes" << endl;
        cout << "3. Mostrar" << endl; // Todas
        cout << "4. Buscar" << endl; // Solo una
        cout << "5. Ordenar" << endl;
        cout << "6. Eliminar" << endl;
        cout << "7. Salir." << endl << endl;
        cout << "Decision: "; cin >> menuPrin;

// -------------------------------------------------------------------------------------------------------------------------------------- Editado
            switch(menuPrin)
            {
                case '1':

                    system("cls");
                    cout << endl << "Menu Ingresar" << endl << endl;

                    cout << endl << endl << "Que opcion desea elegir para ingresar la computadora?" << endl;
                    cout << "1. Ingresar al principio" << endl;
                    cout << "2. Ingresar al final" << endl;
                    cout << "3. Ingresar por posicion" << endl;
                    cout << "4. Salir" << endl << endl;
                    cout << "Decision: "; cin >> menuIngre;



                    switch(menuIngre)
                    {
                        case'1':
                        cout << endl << "Ingresar datos de una computadora" << endl << endl;
                        cout << "Numero de serie:   "; cin >> serie;    compu.setNumSerie(serie);    cout << endl;
                        cout << "Marca:             "; cin >> marca;    compu.setMarca(marca);       cout << endl;
                        cout << "RAM:               "; cin >> ram;      compu.setRam(ram);           cout << endl;
                        cout << "Procesador:        "; cin >> proc;     compu.setProcesador(proc);   cout << endl;
                        cout << "MAC:               "; cin >> mac;      compu.setMac(mac);           cout << endl;
                        cout << "Usuario:           "; cin >> user;     compu.setUsuario(user);      cout << endl;
                        cout << "Contrasenia:       "; cin >> pass;     compu.setContrasenia(pass);  cout << endl;


                        lista.ingresarAlPrincipio(compu);
                        cout << endl << endl << "Registro finalizado, regresara al menu de Ingresar" << endl << endl;
                        system("pause");
                        // ------------------------------------- Aqui va el quicksort
                        break;

                        case '2':
                        cout << endl << "Ingresar datos de una computadora" << endl << endl;
                        cout << "Numero de serie:   "; cin >> serie;    compu.setNumSerie(serie);    cout << endl;
                        cout << "Marca:             "; cin >> marca;    compu.setMarca(marca);       cout << endl;
                        cout << "RAM:               "; cin >> ram;      compu.setRam(ram);           cout << endl;
                        cout << "Procesador:        "; cin >> proc;     compu.setProcesador(proc);   cout << endl;
                        cout << "MAC:               "; cin >> mac;      compu.setMac(mac);           cout << endl;
                        cout << "Usuario:           "; cin >> user;     compu.setUsuario(user);      cout << endl;
                        cout << "Contrasenia:       "; cin >> pass;     compu.setContrasenia(pass);  cout << endl;

                        lista.ingresarAlFinal(compu);
                        cout << endl << endl << "Registro finalizado, regresara al menu de Ingresar" << endl << endl;
                        system("pause");
                        // ------------------------------------- Aqui va el quicksort
                        break;

                        case '3':
                        cout << endl << endl << "Que posicion desea agregar la computadora? : "; cin >> posicionMod;
                        /*

                        if(posicionMod < 1 || posicionMod > lista.getTamanio())
                        {
                            cout << "Numero no valido\n";
                            system("pause");
                            break;
                        }

*/
                        cout << endl << "Ingresar datos de una computadora" << endl << endl;
                        cout << "Numero de serie:   "; cin >> serie;    compu.setNumSerie(serie);    cout << endl;
                        cout << "Marca:             "; cin >> marca;    compu.setMarca(marca);       cout << endl;
                        cout << "RAM:               "; cin >> ram;      compu.setRam(ram);           cout << endl;
                        cout << "Procesador:        "; cin >> proc;     compu.setProcesador(proc);   cout << endl;
                        cout << "MAC:               "; cin >> mac;      compu.setMac(mac);           cout << endl;
                        cout << "Usuario:           "; cin >> user;     compu.setUsuario(user);      cout << endl;
                        cout << "Contrasenia:       "; cin >> pass;     compu.setContrasenia(pass);  cout << endl;
                        lista.ingresarEnPosicion(compu, posicionMod);
                        cout << endl << endl << "Registro finalizado, regresara al menu de Ingresar" << endl << endl;
                        system("pause");
                        break;

                        case '4':
                        break;

                        default:
                        cout << endl << endl << "Opcion invalida" << endl << endl;
                        system("pause");
                        break;
                    }

                break;

// ---------------------------------------------------------------------------------------------------------------------------------------- Editado
                case '2':



                    if(lista.vacia() || lista.getTamanio() == 0)
                    {
                        cout << endl << "No se ha agregado ninguna computadora, regrese a esta opcion cuando haya agregado por lo menos una" << endl << endl;
                        system("pause");
                        break;
                    }

                    else
                    {
                        system("cls");
                        int desicion1;
                        cout << endl << "Menu para editar componentes" << endl << endl;
                        cout << "Escriba el numero de la computadora: "; cin >> desicion1;

                        if(desicion1 < 1 || desicion1 > lista.getTamanio())
                        {
                            cout << "Numero no valido\n";
                            system("pause");
                            break;
                        }


                        do
                        {
                            flagModif = 1;
                            system("cls");
                            cout << "Computadora No. " << desicion1 << endl;
                            lista.get(desicion1 - 1).mostrarComponentes();
                            cout << endl << endl << "Que componente desea agregar/modificar?" << endl << endl;
                            cout << "1. Numero de serie" << endl;
                            cout << "2. Marca" << endl;
                            cout << "3. RAM" << endl;
                            cout << "4. Procesador" << endl;
                            cout << "5. MAC" << endl;
                            cout << "6. Usuario" << endl;
                            cout << "7. Contrasenia" << endl;
                            cout << "8. Salir" << endl << endl;
                            cout << "Decision: "; cin >> menuModif;

                            cout << endl << endl;
                            switch(menuModif)
                            {

                                case '1':
                                cout << "Numero de serie:   "; cin >> serie;    lista.get(desicion1 - 1).setNumSerie(serie);    cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '2':
                                cout << "Marca:             "; cin >> marca;    lista.get(desicion1 - 1).setMarca(marca);       cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '3':
                                cout << "RAM:               "; cin >> ram;      lista.get(desicion1 -1).setRam(ram);           cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '4':
                                cout << "Procesador:        "; cin >> proc;     lista.get(desicion1 - 1).setProcesador(proc);   cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '5':
                                cout << "MAC:               "; cin >> mac;      lista.get(desicion1 - 1).setMac(mac);           cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '6':
                                cout << "Usuario:           "; cin >> user;     lista.get(desicion1 - 1).setUsuario(user);      cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;


                                case '7':
                                cout << "Contrasenia:       "; cin >> pass;     lista.get(desicion1 - 1).setContrasenia(pass);  cout << endl;
                                cout << endl << endl << "Registro finalizado, regresara al menu de agregar/modificar" << endl;
                                system("pause");
                                // ------------------------------------- Aqui va el quicksort
                                break;

                                case '8':
                                flagModif = 0;
                                break;

                                default:
                                cout << endl << endl << "Opcion invalida" << endl << endl;
                                system("pause");
                                break;
                            }

                        }while(flagModif);
                    }
                break;

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------- Terminado

                case '3':

                if(lista.vacia() || lista.getTamanio() == 0)
                {
                    cout << endl << "No se ha agregado ninguna computadora, regrese a esta opcion cuando haya agregado por lo menos una" << endl << endl;
                    system("pause");
                    break;
                }

                else
                {
                    system("cls");
                    cout << endl << "Menu mostrar" << endl << endl;
                    mostrarPcs(lista);
                    cout << endl << endl << "Todas las computadoras se han impreso" << endl << endl;
                    system("pause");
                    break;
                }

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------- Editado


                case '4':
//                {
                    if(lista.vacia() || lista.getTamanio() == 0)
                    {
                        cout << endl << "No se ha agregado ninguna computadora, regrese a esta opcion cuando haya agregado por lo menos una" << endl << endl;
                        system("pause");
                        break;
                    }

                    else
                    {
                        system("cls");
                        string busqueda;
                        cout << endl << "Menu buscar" << endl << endl;
                        cout << "Escriba el numero de serie del computador: ";
                        fflush(stdin);
                        getline(cin, busqueda);
                        cout << endl << endl;
                        int x = busquedaBinaria(lista, busqueda, 0, lista.getTamanio()-1);

                        if(x != -1)
                        {
                            cout << "   Computadora " << x+1 << '\n';
                            lista.get(x).mostrarComponentes(); //------------------------------------------ Revisar esto
                        }

                        else
                        {
                            cout << "No se encontro la computadora\n";
                        }

                        system("pause");
                        break;
                    }
//                }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

                case '5':

                if(lista.vacia() || lista.getTamanio() == 0)
                {
                    cout << endl << "No se ha agregado ninguna computadora, regrese a esta opcion cuando haya agregado por lo menos una" << endl << endl;
                    system("pause");
                    break;
                }

                else
                {
                    system("cls");
                    cout << endl << "Menu Ordenar" << endl << endl;
                    ordenamientoQuicksort(lista, 0, lista.getTamanio()-1);
                    cout << "Las computadoras se han ordenado, regresando al menu principal" << endl;
                    system("pause");
                    break;
                }

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------- Editado


                case '6':
                
                if(lista.vacia() || lista.getTamanio() == 0)
                {
                    cout << endl << "No se ha agregado ninguna computadora, regrese a esta opcion cuando haya agregado por lo menos una" << endl << endl;
                    system("pause");
                    break;
                }

                else
                {

                    int posicionEliminar;
                    cout << endl << "Menu eliminar" << endl << endl;

                    cout << "1. Eliminar al principio" << endl;
                    cout << "2. Eliminar al final" << endl;
                    cout << "3. Eliminar por posicion" << endl;
                    cout << "4. Salir" << endl << endl;
                    cout << "Decision: "; cin >> menuEliminar;

                    switch(menuEliminar)
                    {
                        case '1':
                        cout << endl << endl << "Eliminar al principio." << endl;
                        lista.eliminarAlInicio();
                        cout << endl << endl << "La eliminacion ha finalizado, regresara al menu de eliminar." << endl << endl;
                        system("pause");
                        break;

//  lista.eliminarAlFinal();
                        case '2':
                        cout << endl << endl << "Eliminar al final." << endl;
                        lista.eliminarAlFinal();
                        cout << endl << endl << "La eliminacion ha finalizado, regresara al menu de eliminar." << endl << endl;
                        system("pause");
                        break;

                        case '3':
                        cout << endl << endl << "Eliminar por posicion." << endl;
                        cout << "Que posicion desea eliminar?" << endl;
                        cout << "Decision: "; cin >> posicionEliminar;

                        if(posicionEliminar < 1 || posicionEliminar > lista.getTamanio())
                        {
                            cout << "Numero no valido\n";
                            system("pause");
                            break;
                        }

                        lista.eliminarEnPosicion(posicionEliminar);
                        cout << endl << endl << "La eliminacion ha finalizado, regresara al menu de eliminar." << endl << endl;
                        system("pause");
                        break;

                        case '4':
                        break;

                        default:
                        cout << endl << endl << "Opcion invalida" << endl << endl;
                        system("pause");
                        break;
                    }
                break;
                }


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------- Terminado



                case '7':
                cout << endl << "Gracias por usar el programa" << endl;
                flagPrin = 0;
                break;


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------- Terminado


                default:
                cout << endl << endl << "Opcion invalida" << endl << endl;
                system("pause");
                break;
            }
        //}

    }while(flagPrin);


    return 0;
}
