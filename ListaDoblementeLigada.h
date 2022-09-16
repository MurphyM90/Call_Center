#ifndef LISTA_DOBLEMENTE_LIGADA_H
#define LISTA_DOBLEMENTE_LIGADA_H
#include "ListaAbstracta.h"


template <typename E>
class Eslabon
{
	public:
		E elemento;
		Eslabon *siguiente;
		Eslabon *anterior;
		Eslabon(const E&, Eslabon *anterior = NULL, Eslabon *siguiente = NULL);
		Eslabon(Eslabon *anterior = NULL, Eslabon *siguiente = NULL);
};


template <typename E> Eslabon<E>::Eslabon(const E& item, Eslabon *anterior, Eslabon *siguiente)
{
	this -> elemento = item;
	this -> anterior = anterior;
	this -> siguiente = siguiente;
}

template <typename E> Eslabon<E>::Eslabon(Eslabon *anterior, Eslabon *siguiente)
{
	this -> anterior = anterior;
	this -> siguiente = siguiente;
}


template <typename E> class ListaDoblementeLigada: public Lista<E>
{
	private:
		Eslabon <E>*cabeza;
		Eslabon <E>*cola;
		Eslabon <E>*actual;

		int tamanio;
		void inicializar(void);
		void eliminarTodo(void);

	public:
		ListaDoblementeLigada(void);
		~ListaDoblementeLigada(void);
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

