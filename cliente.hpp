#ifndef CLIENTE_HPP_INCLUDED
#define CLIENTE_HPP_INCLUDED

#include "nombre.hpp"

class Cliente{
    private:
        Nombre nombre;
        float dLL;//duracion llamada
        long int cC;//Codigo de cliente
        string motivo;
    public:
        Cliente();
        Cliente(Nombre _nombre, float _dLL, long int _cC, string _motivo);
        void setNombre(Nombre _nombre);
        void setdLL(float _dLL);
        void setcC(long int _cC);
        void setMotivo(string _motivo);
        Nombre getnombre();
        float getdLL();
        long int getcC();
        string getmotivo();
        string toString();

        Cliente& operator = (const Cliente&);

        bool operator == (const Cliente&) const; //== de comparacion
        bool operator != (const Cliente&) const;
        bool operator < (const Cliente&) const;
        bool operator <= (const Cliente&) const;
        bool operator > (const Cliente&) const;
        bool operator >= (const Cliente&) const;

        friend ostream& operator<<(ostream& os, const Cliente& _cliente);
        friend istream& operator>>(istream& is, const Cliente& _cliente);
};

Cliente::Cliente(){
    nombre.setNombre("");
    nombre.setApellido("");
    dLL = 0.0;
    cC = 0;
    motivo = "Sin Motivo";
}

Cliente::Cliente(Nombre _nombre, float _dLL, long int _cC, string _motivo){
    nombre = _nombre;
    dLL = _dLL;
    cC = _cC;
    motivo = _motivo;
}

void Cliente::setNombre(Nombre _nombre){
    nombre = _nombre;
}
void Cliente::setdLL(float _dLL){
    dLL = _dLL;
}
void Cliente::setcC(long int _cC){
    cC = _cC;
}
void Cliente::setMotivo(string _motivo){
    motivo = _motivo;
}
Nombre Cliente::getnombre(){
    return nombre;
}
float Cliente::getdLL(){
    return dLL;
}
long int Cliente::getcC(){
    return cC;
}
string Cliente::getmotivo(){
    return motivo;
}
string Cliente::toString(){
    cout << nombre;
    cout << "Duracion de la llamada: " << dLL << endl;  // Duracion llamada
    cout << "Codigo del Cliente: " << cC << endl;       // Codigo de cliente
    cout << "Motivo del Cliente: " << motivo << endl;
}


#endif // CLIENTE_HPP_INCLUDED
