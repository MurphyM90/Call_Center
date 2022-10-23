

#include<iostream>
#include<string>



using namespace std;

#include "nombre.hpp"
#include "fecha.hpp"
#include "cliente.hpp"

#include "ListaDoblementeLigada.cpp"

/*
bool menuPrincipal();
//void menuCRUD(int, ListaDoblementeLigada<Cliente> &, ListaDoblementeLigada<Agente> &);


*/

bool menuPrincipal();
void menuCRUD(int, ListaDoblementeLigada<Cliente> &);

// Metodos de Cliente
void crearCliente(ListaDoblementeLigada<Cliente> &listaClientes);
// Cliente &obtenerCliente(int id, Cliente, ListaDoblementeLigada<Cliente> &listaClientes); // --------------------------------------------------------------------------------------

void mostrarClientes(ListaDoblementeLigada<Cliente> &);

// Metodos de Agente

/*
int main(){
    bool mainFlag = true;
    while(mainFlag == true){
        if(mainFlag == false)
            break;
        else
            mainFlag = menuPrincipal();
    }
    cout << "Saliendo del programa Call Center." << endl << endl;
    system("pause");
    return 0;
}
*/

/*
int foo();

int main(){
    int a;
    a = foo();
    cout << a << endl;
    system("pause");
    return 0;
}

int foo(){
    int b = 99;
    return b;
}
*/


Cliente &obtenerCliente(int id, ListaDoblementeLigada<Cliente> &listaClientes){
    Cliente *cAux;
    listaClientes.irAPosicion(id);    //  Para obtener el primer elemento de la lista con el ir a posicion, debe ser 0, como un array vaya
    cAux = listaClientes.obtenerElemento();
    cout << cAux;
    cout << endl;
    return cAux;
}

int main(){
    ListaDoblementeLigada<Cliente> listaClientes;
    Nombre n1("Diego", "Ramos");
    Cliente c1(n1, 01.50, 1, "Esto es una diminuta prueba");
    listaClientes.ponAlFinal(c1);
    Cliente cliAux;
    cout << endl;
    cliAux = obtenerCliente(0, listaClientes);
    cout << cliAux << endl;
    cout << endl;
    system("pause");
    return 0;
}




bool menuPrincipal(){
    int opc = 0;
    bool flagOptions = true;

    ListaDoblementeLigada<Cliente> listaClientes;
    //ListaDoblementeLigada<Agente> listaAgentes;

    while(flagOptions == true){
        system("cls");
        cout << "Bienvenidos al programa Call Center, favor de seleccionar con que apartado quiere trabajar" << endl << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Agentes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccionar de manera numerica su opcion: ";
        
        cin >> opc;

        if(opc == 1){
            //menuCRUD(1, listaClientes, listaAgentes);
            menuCRUD(opc, listaClientes);
        }

        else if(opc == 2){
            //menuCRUD(2, listaClientes, listaAgentes);
            menuCRUD(opc, listaClientes);
        }

        else if(opc == 3){
            flagOptions = false;
            return false;
        }
        
        else{
            cout << "Favor de seleccionar otra opcion" << endl << endl;
            system("pause");
        }
    }
}

void menuCRUD(int opcMenu, ListaDoblementeLigada<Cliente> &listaClientes){
    int opcCRUD = 0;
    bool flagCRUD = true;
    while(flagCRUD == true){
        
        if(flagCRUD == false)
            break;
        
        system("cls");
        if(opcMenu == 1)
            cout << "Menu Cliente - Estas son las opciones que puede realizar con el menu" << endl << endl;
        else if(opcMenu == 2)
            cout << "Menu Agente - Estas son las opciones que puede realizar con el menu" << endl << endl;
        cout << "1. Crear" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Mostrar todos" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Eliminar" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccionar de manera numerica su opcion: ";
        
        cin >> opcCRUD;

        if(opcCRUD == 1){
            if(opcMenu == 1){
                Cliente cAux;                               // Creamos un auxiliar de cliente
                crearCliente(listaClientes);                // Pondremos el crear cliente y lo agregamos a la lista cliente
                system("pause");
            }
            else if(opcMenu == 2){
                // Creamos un auxiliar de AGENTE
                // Pondremos el crear AGENTE
                // Lo agregamos a la lista AGENTE
            }
        }

        else if(opcCRUD == 2){
            if(opcMenu == 1){
                if(listaClientes.isEmpty() == true){
                    cout << endl << "La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    //  Mostrar Cliente
                    int id = 0;
                    Cliente cAux;
                    cout << "Mostrar Cliente por su ID" << endl << endl;
                    cout << "Escriba el ID del cliente que desea buscar: ";
                    cin >> id;
                    // cAux = obtenerCliente(id, cAux, listaClientes); -------------------------------------------------------------------------------------------------------------
                    cout << "El cliente es el siguiente: " << endl << endl;
                    cout << cAux << endl;
                    system("pause");
                }
            }

            else if(opcMenu == 2){
                /*
                if(listaClientes.isEmpty() == true){
                    cout << "La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    //  Mostrar Agente
                }
                */
            }
        }

        else if(opcCRUD == 3){
            if(opcMenu == 1){
                if(listaClientes.isEmpty() == true){
                    cout << endl << "La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    //  Mostrar Clientes
                    mostrarClientes(listaClientes);
                    system("pause");
                }
            }

            else if(opcMenu == 2){
                /*
                if(listaClientes.isEmpty() == true){
                    cout << "La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    //  Mostrar Agente
                }
                */
            }
        }

        else if(opcCRUD == 4){
            if(opcMenu == 1){
                if(listaClientes.isEmpty() == true){
                    cout << endl << "La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    
                    system("pause");
                }
            }

            else if(opcMenu == 2){
                /*
                if(listaClientes.isEmpty() == true){
                    
                    system("pause");
                }
                else{
                    
                    system("pause");
                }
                */
            }
        }

        else if(opcCRUD == 5){
            if(opcMenu == 1){
                if(listaClientes.isEmpty() == true){
                    cout << endl <<"La lista esta vacia, por favor, agregue un elemento" << endl;
                    system("pause");
                }
                else{
                    
                    system("pause");
                }
            }

            else if(opcMenu == 2){
                /*
                if(listaClientes.isEmpty() == true){
                    
                    system("pause");
                }
                else{
                    
                    system("pause");
                }
                */
            }
        }

        else if(opcCRUD == 6){
            flagCRUD = false;
        }
        
        else{
            cout << "Favor de seleccionar otra opcion" << endl << endl;
            system("pause");
        }
    }
    cout << "Saliendo del menu CRUD (Create, Read, Update, Delete)." << endl << endl;
    system("pause");
}


void crearCliente(ListaDoblementeLigada<Cliente> &listaClientes){
    cout << endl << endl << "Creacion de Cliente" << endl << endl;
    Cliente cAux;
    cin >> cAux;
    cout << "La informacion que se agregara a la lista sera la siguiente:" << endl << endl;
    cout << cAux;
    listaClientes.ponAlFinal(cAux);
    cout << endl;
}

/*
Cliente &obtenerCliente(int id, Cliente cAux, ListaDoblementeLigada<Cliente> &listaClientes){ // --------------------------------------------------------------------------- FIX THIS, Position
    listaClientes.irAPosicion(id);
    cAux = listaClientes.obtenerElemento();
    return cAux;
}
*/



void mostrarClientes(ListaDoblementeLigada<Cliente> &listaClientes){
    int tamanio = listaClientes.obtenerTamanio() + 1;
    cout << endl << endl << "Mostrar todos los clientes" << endl << endl;
    for(int i = 1; i < tamanio; i++){
        Cliente cAux;
        //cAux = obtenerCliente(i, cAux, listaClientes);
        cout << cAux << endl;
    }
    cout << endl;
}




//void menuCRUD(int opc, ListaDoblementeLigada<Cliente> &listaClientes, ListaDoblementeLigada<Agente> &listaAgentes){



/*
int main(){
    //Cliente c1();
    cout<<"prueba git\n";
    Nombre n1("Diego", "Ramos");
    cout << n1 << endl << endl;
    Cliente c1(n1, 01.50, 1, "Esto es una diminuta prueba");
    cout << c1 << endl << endl;

    Nombre n2("Michael", "Edgar");
    cout << n2 << endl << endl;
    Cliente c2(n2, 02.70, 2, "This is an example");
    cout << c2 << endl << endl;

    Nombre n3("Paul", "GOD");
    cout << n3 << endl << endl;
    Cliente c3(n3, 01.50, 2, "Esto es una diminuta prueba");
    cout << c3 << endl << endl;

    Nombre n4("Kevin", "Herniudo");
    cout << n4 << endl << endl;
    Cliente c4(n4, 01.50, 1, "Esto es una diminuta prueba");
    cout << c4 << endl << endl;

    Nombre n5;

    cin >> n5;

    cout << endl << n5 << endl << endl;

    cout << "Prueba de Istream con Cliente" << endl;    

    Cliente c5;

    cin >> c5;

    cout << endl << endl << "Mostrar el cliente creado" << endl << c5;


    cout << "Usar operadores sobrecargados" << endl << endl;
    if(c1 == c2){
        cout << "Cliente 1 es igual Cliente 2" << endl << endl;
    }

    if(c2 != c1){
        cout << "Cliente 2 es distinto que Cliente 1" << endl << endl;
    }

    if(c2 != c3){
        cout << "Cliente 2 es distinto que Cliente 3" << endl << endl;
    }

    if(c3 == c2){
        cout << "Cliente 3 es igual que Cliente 2" << endl << endl;
    }

    if(c4 == c1){
        cout << "Cliente 4 es igual a Cliente 1" << endl << endl;
    }

    
    system("pause");
    return 0;
}

*/

/*
int main(){

    cout << "Agregar a las listas" << endl << endl;

    ListaDoblementeLigada<Cliente> listaCliente;
    listaCliente.ponAlFinal(c1);
    listaCliente.ponAlFinal(c2);
    listaCliente.irAlInicio();

    int tamanio = listaCliente.obtenerTamanio();
    cout << "El tamanio es: " << tamanio << endl;
    int posicion = listaCliente.posicionActual();
    cout << "La posicion es: " << posicion << endl;
    Cliente cAux = listaCliente.obtenerElemento();
    cout << "El cliente auxiliar es el siguiente:" << endl << endl;
    cout << cAux << endl << endl;

    listaCliente.siguiente();
    posicion = listaCliente.posicionActual();
    cout << "La posicion es: " << posicion << endl;
    cAux = listaCliente.obtenerElemento();
    cout << "El cliente auxiliar 2 es el siguiente:" << endl << endl;
    cout << cAux << endl << endl;
    


    if(listaCliente.isEmpty() == true)
        cout << "La lista esta vacia" << endl << endl;
    else{
        cout << "La lista NO esta vacia" << endl << endl;
    }

    system("pause");
    return 0;
}
*/


/*
 int main(){

     Nombre n1 = Nombre("Paul", "Ramos");
     cout<<"Hola mi nombre es: " << n1.getNombre() << " " << n1.getApellido() <<endl;

    return 0;
 }


int main()
{
   Hora h;  // instancia el objeto t de la clase Hora

   cout << "La hora militar inicial es "<<endl;
   h.imprimeMilitar();
   cout << "\nLa hora estandar inicial es "<<endl;
   h.imprimeEstandar();

   h.estableceHora( 21, 00, 6 );
   cout << "\nLa hora militar despues de estableceHora es "<<endl;
   h.imprimeMilitar();
   cout << "\nLa hora estandar despues de estableceHora es "<<endl;
   h.imprimeEstandar();

   h.estableceHora( 99, 99, 99 );  // intenta establecer valores invalidos
   cout << "\nDespues de intentar establecer valores invalidos:"
        << "\nHora militar: "<<endl;
   h.imprimeMilitar();
   cout << "\nHora estandar: "<<endl;
   h.imprimeEstandar();
   cout << endl;
   return 0;
} // fin de la funcion main

int main(int argc, char *argv[])
{
    int dia_aux, anio_aux, mes_aux;
    //Fecha diaA(20,4,2006), diaB(1,1,0);
    Fecha diaA(27,4,2022), diaB(1,1,0);

    cout<< "dia: " << diaA.damedia()<< endl;
    cout<< "mes: " << diaA.damemes()<< endl;
    cout<< "anio: " << diaA.dameanio()<< endl;

    cout<<"Fecha completa: ";
    diaA.imprimefecha();

    cout <<endl<< "Introduzca dia: ";
    cin >> dia_aux;
    cout <<endl<< "Introduzca mes: ";
    cin >> mes_aux;
    cout <<endl<< "Introduzca anio: ";
    cin >> anio_aux;
    diaA.guardarfecha(dia_aux,mes_aux,anio_aux);
    cout<<"Fecha introducida: ";
    diaA.imprimefecha();

    cout <<endl<< "Introduzca fecha completa (dd-mm-aaaa): ";
    diaA.scanfecha();
    cout<<"Fecha introducida: ";
    diaA.imprimefecha();

    cout<< endl << endl <<"Demo diferencia en dias. Intro una fecha: ";
    diaA.scanfecha();
    cout<< endl <<"Intro una fecha posterior: ";
    diaB.scanfecha();
    cout << endl << "Diferencia en dias=> " <<dif_dias (diaA,diaB) << endl;


    cout << "La hora militar inicial es "<<endl;
    diaA.imprimeMilitar();
    cout << "\nLa hora estandar inicial es "<<endl;
    diaA.imprimeEstandar();

    diaA.estableceHora( 21, 00, 6 );
    cout << "\nLa hora militar despues de estableceHora es "<<endl;
    diaA.imprimeMilitar();
    cout << "\nLa hora estandar despues de estableceHora es "<<endl;
    diaA.imprimeEstandar();

    diaA.estableceHora( 99, 99, 99 );  // intenta establecer valores invalidos
    cout << "\nDespues de intentar establecer valores invalidos:"
    << "\nHora militar: "<<endl;
    diaA.imprimeMilitar();
    cout << "\nHora estandar: "<<endl;
    diaA.imprimeEstandar();
    cout << endl;


    cin.get();
    return EXIT_SUCCESS;

}
*/
