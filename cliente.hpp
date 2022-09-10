#ifndef CLIENTE_HPP_INCLUDED
#define CLIENTE_HPP_INCLUDED

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


#endif // CLIENTE_HPP_INCLUDED
