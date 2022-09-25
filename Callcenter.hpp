#ifndef CALLCENTER_HPP_INCLUDED
#define CALLCENTER_HPP_INCLUDED

#include "ListaDoblementeLigada.cpp"
#include "cliente.hpp"
#include "agente.hpp"


class Callcenter{
    private:
        ListaDoblementeLigada<Agente> listaAgentes;
        ListaDoblementeLigada<Cliente> listaClientes;
    public:
        Callcenter();
        Callcenter(ListaDoblementeLigada _listaAgentes, ListaDoblementeLigada _listaClientes);

};



#endif // CALLCENTER_HPP_INCLUDED
