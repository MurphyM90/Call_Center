#ifndef AGENTE_HPP_INCLUDED
#define AGENTE_HPP_INCLUDED

#include "nombre.hpp"
#include "area.hpp"
#include "horario.hpp"
#include "cliente.hpp"

#include<iostream>
#include<string>

using namespace std;

class Agente{
    private:
        string codigo;
        Nombre nombre;
        long int extension;
        Cliente cliente;
        Horario horario;
        Area area;
    public:
        Agente();
        Agente(string _codigo, Nombre _nombre, long int _extension, Cliente _cliente, Horario _horario, Area _area);
        void setCodigo(string _codigo);
        void setNombre(Nombre _nombre);
        void setExtension(long int _extension);
        void setCliente(Cliente _cliente);
        void setHorario(Horario _horario);
        void setArea(Area _area);
        string getCodigo();
        Nombre getNombre();
        long int getExtension();
        Cliente getCliente();
        Horario getHorario();
        Area getArea();

        string toString();

        Agente& operator = (const Agente&);

        bool operator == (const Agente&) const; //== de comparacion
        bool operator != (const Agente&) const;
        bool operator < (const Agente&) const;
        bool operator <= (const Agente&) const;
        bool operator > (const Agente&) const;
        bool operator >= (const Agente&) const;

        friend ostream& operator<<(ostream& os, const Agente& _agente);
        friend istream& operator>>(istream& is, const Agente& _agente);

};



#endif // AGENTE_HPP_INCLUDED
