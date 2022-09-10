#ifndef CALLCENTER_HPP_INCLUDED
#define CALLCENTER_HPP_INCLUDED

class Callcenter{
    private:
        ListaLigada listaAgentes;
        ListaLigada listaClientes;
    public:
        Callcenter();
        Callcenter(ListaLigada _listaAgentes, ListaLigada _listaClientes);

};



#endif // CALLCENTER_HPP_INCLUDED
