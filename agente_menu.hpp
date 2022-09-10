#ifndef AGENTE_MENU_HPP_INCLUDED
#define AGENTE_MENU_HPP_INCLUDED

class Agentemenu{
    private:
        ListaLigada listaAgentes;
    public:
        void crearAgente(Agente _agente);
        Agente leerAgente(string _nombreAgente);
        void leerAgentes(ListaLigada _listaAgentes);
        void actualizarAgente(Agente _agente);
        void eliminarAgente(Agente _agente);
};



#endif // AGENTE_MENU_HPP_INCLUDED
