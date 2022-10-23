#ifndef NOMBRE_HPP_INCLUDED
#define NOMBRE_HPP_INCLUDED

#include<iostream>
#include<string>

//using namespace std;

class Nombre{
    private: //atributos
    string nombre;
    string apellido;

    public:
        Nombre();
        Nombre(string _nombre, string _apellido);
        void setNombre(string _nombre);//Se pone void en set porque no retorna ningun valor pero si agregas.
        string getNombre();//Aqui solo se pone el tipo de dato correspondiente pues el get solo obtiene el valor
        void setApellido(string _apellido);
        string getApellido();

        string toString();

        // deberia estar un return
        // https://www.youtube.com/watch?v=p9DDn5FSOoY      Sobrecarga del operador= en C++
        
        void operator = (Nombre);

        bool operator == (const Nombre&) const; //== de comparacion
        bool operator != (const Nombre&) const;
        bool operator < (const Nombre&) const;
        bool operator <= (const Nombre&) const;
        bool operator > (const Nombre&) const;
        bool operator >= (const Nombre&) const;

        friend ostream& operator<<(ostream& os, const Nombre& _nombre);
        friend istream& operator>>(istream& is, Nombre& _nombre);
        //friend istream & operator>>(istream& is, Cliente& _cliente);

};

void Nombre::operator = (Nombre nombreParam){
    this->nombre = nombreParam.getNombre();
    this->apellido = nombreParam.getApellido();
}

ostream& operator << (ostream& os, const Nombre& _nombre){
    os << "Nombre: " << _nombre.nombre << std::endl;
    os << "Apellido: " << _nombre.apellido << std::endl;
    return os;
}


istream& operator>>(istream& is, Nombre& _nombre){
    cout << "Nombre: ";
    is >> _nombre.nombre;
    cout << "Apellido: ";
    is >> _nombre.apellido;
    return is;
}


string Nombre::toString(){
    cout << "Nombre: " << nombre << std::endl;
    cout << "Apellido: " << apellido << std::endl;
}

Nombre::Nombre(){//Este se utiliza para no guardar basura en el buffer
    nombre = "";
    apellido = "";
}

Nombre::Nombre(string _nombre, string _apellido){// el constructor se inicializa normal
    nombre = _nombre;
    apellido = _apellido;
}


void Nombre::setNombre(string _nombre){//inicilizando el set
    nombre = _nombre;
}

void Nombre::setApellido(string _apellido){//inicilizando el set
     apellido = _apellido;
}

string Nombre::getNombre(){//Asi se inicializa un get
    return nombre;
}

string Nombre::getApellido(){//Asi se inicializa un get
    return apellido;
}

#endif // NOMBRE_HPP_INCLUDED
