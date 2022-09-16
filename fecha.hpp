#ifndef FECHA_HPP_INCLUDED
#define FECHA_HPP_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

class Fecha {
    private:

    int dia, mes, anio;
    int hora, minuto, segundo;
    bool fechavalida(int ndia, int nmes, int nanio){
        if(ndia<1 || ndia>31) return false;
        else if (nmes<1 || nmes>12) return false;
        else switch(nmes)
        {
            case 4: case 6: case 9: case 11:
                if(ndia>30) return false;
                break;
            case 2:
                if (ndia>28)return false;
                break;
        }
        return true;
    }

    public:
        // Metodos de Fecha
        Fecha (int, int, int);
        int damedia(void);
        int damemes(void);
        int dameanio(void);
        void imprimefecha(void);
        void guardarfecha(int, int, int);
        void scanfecha();

        // declaraci�n de funcio�n externa amiga:
        friend int dif_dias (Fecha A, Fecha B);

        // Metodos de Hora
        void estableceHora( int, int, int ); // establece hora, minuto, segundo
        void imprimeMilitar();          // imprime la hora en formato militar
        void imprimeEstandar();          // imprime la hora en formato estandar
        string toString();

        Fecha& operator = (const Fecha&);

        bool operator == (const Fecha&) const; //== de comparacion
        bool operator != (const Fecha&) const;
        bool operator < (const Fecha&) const;
        bool operator <= (const Fecha&) const;
        bool operator > (const Fecha&) const;
        bool operator >= (const Fecha&) const;

        friend ostream& operator<<(ostream& os, const Fecha& _fecha);
        friend istream& operator>>(istream& is, const Fecha& _fecha);
};

Fecha::Fecha(int d=0, int m=0, int a=0) {
    // Constructor de fecha
    if(fechavalida(d,m,a)){
        dia=d; mes=m; anio=a;
    } else {
        cout<<"ERROR: Se trato de introducir fecha incorrecta"<<endl;
    }
    // hora
    hora = minuto = segundo = 0;
}

int Fecha::damedia(void){
    return dia;
}

int Fecha::damemes(void){
    return mes;
}

int Fecha::dameanio(void){
    return anio;
}

void Fecha::imprimefecha(void){
    cout<<damedia()<< "-" << damemes()<<"-" << dameanio()<< endl;
}

void Fecha::guardarfecha(int d=0, int m=0, int a=0){
    if(fechavalida(d,m,a)) {
        dia=d; mes=m; anio=a;
    } else {
        cout<<"ERROR: Introducir fecha incorrecta"<<endl;
    }
}

void Fecha::scanfecha(){
    int d, m, a;
    if (scanf("%d-%d-%d",&d,&m,&a)!=3)
    {
        cout << "Error en lectura de fecha.";
    }
    else if(fechavalida(d,m,a)) {
        dia=d; mes=m; anio=a;
    }
}


// Establece un nuevo valor de Hora por medio de la hora militar. Realiza verificaciones
// de validacion de los valores de los datos. Establece en cero a los valores invalidos.
void Fecha::estableceHora( int h, int m, int s )
{
   hora = ( h >= 0 && h < 24 ) ? h : 0;
   minuto = ( m >= 0 && m < 60 ) ? m : 0;
   segundo = ( s >= 0 && s < 60 ) ? s : 0;
} // fin de la funcion estableceHora

// Imprime Hora en formato militar
void Fecha::imprimeMilitar()
{
   cout << ( hora < 10 ? "0" : "" ) << hora << ":"
        << ( minuto < 10 ? "0" : "" ) << minuto;
} // fin de la funcion imprimeMilitar

// Imprime Hora en formato estandar
void Fecha::imprimeEstandar()
{
   cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
        << ":" << ( minuto < 10 ? "0" : "" ) << minuto
        << ":" << ( segundo < 10 ? "0" : "" ) << segundo
        << ( hora < 12 ? " AM" : " PM" );
} // fin de la funcion imprimeEstandar




//Definici�n de la funci�n amiga (diferencia en dias):
int dif_dias (Fecha A, Fecha B){
    int d,m,a, dif=0;

    // Si estan al reves suspendemos el c�lculo:
    if(A.anio > B.anio) return -1;
    else if(A.anio == B.anio && A.mes > B.mes) return -1;
    else if(A.anio == B.anio && A.mes == B.mes && A.dia > B.dia) return -1;

    // Si son fechas del mismo a�o:
    if(A.anio == B.anio) {
        if(A.mes == B.mes) return B.dia-A.dia;
        // Dias por meses completos:
        for(a=A.mes+1; a<B.mes  ; a++)
        {
            switch(a) {
                case 4: case 6: case 9: case 11:
                     dif+=30;
                     break;
                case 2:
                     dif+=28;
                     break;
                default:
                     dif+= 31;
            }
        }

         // Dias que faltan para terminar el mes de A:
        switch(A.mes) {
           case 4: case 6: case 9: case 11:
                dif+=30-A.dia;
                break;
           case 2:
                dif+=28-A.dia;
                break;
           default:
                dif+= 31-A.dia;
        }
        // Dias del mes de B:
        dif+=B.dia;

        return dif;
    }
    // Si son dias de a�os distintos:
    // A�os completos de diferencia:
    else dif = (B.anio - (A.anio+1)) * 365;
    // Ahora los meses hasta fin del a�o de A:
    for(a=A.mes+1; a<=12  ; a++)
    {
        switch(a) {
            case 4: case 6: case 9: case 11:
                 dif+=30;
                 break;
            case 2:
                 dif+=28;
                 break;
            default:
                 dif+= 31;
        }
    }

    // Y los meses desde ppio del a�o de B:
    for(a=1; a<B.mes  ; a++)
    {
        switch(a) {
            case 4: case 6: case 9: case 11:
                 dif+=30;
                 break;
            case 2:
                 dif+=28;
                 break;
            default:
                 dif+= 31;
        }
    }
    // Dias que faltan para terminar el mes de A:
    switch(a) {
        case 4: case 6: case 9: case 11:
            dif+=30-A.dia;
            break;
        case 2:
            dif+=28-A.dia;
            break;
        default:
            dif+= 31-A.dia;
    }
    // Dias del mes de B:
    dif+=B.dia;

    return dif;
}




#endif // FECHA_HPP_INCLUDED
