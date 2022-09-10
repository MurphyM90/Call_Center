#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

#include "fecha.hpp"

class Horario{
    private:
        int dT; //diasTrabajados
        int dNT; //diasNotrabajados
        Fecha hE;//Hora entrada
        Fecha hS;//Hora salida
        int hEx;//Horas extra
    public:
        Horario();
        Horario(Fecha _hE, Fecha _hS, int _dT, int _dNT, int _hEx);
        void setdT(int _dT);
        void setdNT(int _dNT);
        void sethE(Fecha _hE);
        void sethS(Fecha _hS);
        void sethEx(int _hEx);
        int getdT();
        int getdNT();
        Fecha gethE();
        Fecha gethS();
        int gethEx();
        string toString();

        Horario& operator = (const Horario&);

        bool operator == (const Horario&) const; //== de comparacion
        bool operator != (const Horario&) const;
        bool operator < (const Horario&) const;
        bool operator <= (const Horario&) const;
        bool operator > (const Horario&) const;
        bool operator >= (const Horario&) const;

        friend ostream& operator<<(ostream& os, const Horario& _horario);
        friend istream& operator>>(istream& is, const Horario& _horario);
};




#endif // HORARIO_HPP_INCLUDED
