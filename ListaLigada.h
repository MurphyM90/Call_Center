#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H
#include "ListaAbstracta.h"


#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;

void Assert(bool val, string s){
	if(!val){
		cout << "\nFallo: " << s << '\n';
		exit(-1);
	}
}



template <typename E>
class Eslabon
{
	public:
		E elemento;
		Eslabon *siguiente;
		Eslabon(const E& item, Eslabon* siguiente = NULL){
			this -> elemento = item;
	 		this -> siguiente = siguiente;
		}
		Eslabon(Eslabon* siguiente = NULL){
			this -> siguiente = siguiente;
		}
};

/*
template <typename E> Eslabon<E>::Eslabon(const E& item, Eslabon* siguiente = NULL)
{
	 this -> elemento = item;
	 this -> siguiente = siguiente;
}


template <typename E> Eslabon<E>::Eslabon(Eslabon* siguiente = NULL)
{
	this -> siguiente = siguiente;
}

*/


template <typename E> class ListaLigada: public Lista<E>
{
	private:
		Eslabon <E>* cabeza;
		Eslabon <E>* cola;
		Eslabon <E>* actual;

		int tamanio;
		void inicializar(void);
		void eliminarTodo(void);

	public:
		ListaLigada(void);
		~ListaLigada(void);
		void vaciar(void);
		void insertar(const E &);
		void ponAlFinal(const E &);
		E eliminar(void);
		void irAlInicio(void);
		void irAlFinal(void);
		void anterior(void);
		void siguiente(void);
		int obtenerTamanio(void) const;
		int posicionActual(void) const;
		void irAPosicion(int);
		const E &obtenerElemento(void) const;
};

#endif
