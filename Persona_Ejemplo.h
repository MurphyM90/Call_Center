#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    private:
        int edad;
        string nombre;

    public:
        Persona();
        Persona(int edad, string nombre);
        void setEdad(int edad);
        int getEdad();
        void setNombre(string nombre);
        string getNombre();
        friend ostream& operator<<(ostream& os, const Persona& per);
};

ostream& operator<<(ostream& os, const Persona& per){
    os << per.nombre << std::endl;
    os << per.edad << std::endl;
    return os;
}

Persona::Persona(){
    this->edad = 0;
    this->nombre = "";
}

Persona::Persona(int edad, string nombre){
    this->edad = edad;
    this->nombre = nombre;
}

void Persona::setEdad(int edad){
    this->edad = edad;
}

void Persona::setNombre(string nombre){
    this->nombre = nombre;
}


int Persona::getEdad(){
    return this->edad;
}

string Persona::getNombre(){
    return this->nombre;
}

#endif
