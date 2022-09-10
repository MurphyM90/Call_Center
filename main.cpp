/*
#include<iostream>
#include<string>
*/
using namespace std;


#include "nombre.hpp"

#include "fecha.hpp"


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
*/
int main(int argc, char *argv[])
{
    int dia_aux, anio_aux, mes_aux;
    Fecha diaA(20,4,2006), diaB(1,1,0);

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
