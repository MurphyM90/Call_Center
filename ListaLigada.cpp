#include <string>
#include <iostream>
#include <cstdlib>

#include "ListaLigada.h"


template <typename E>
void ListaLigada<E>::inicializar(void)
{
	actual = cola = cabeza = new Eslabon <E>;
	tamanio = 0;
}

template <typename E>
void ListaLigada<E>::eliminarTodo(void)
{
	while(cabeza != NULL)
	{
		actual = cabeza;
		cabeza = cabeza -> siguiente;
		delete actual;
	}
	tamanio =  0;
}

template <typename E> ListaLigada<E>::ListaLigada()
{
	inicializar();
}

template <typename E> ListaLigada<E>::~ListaLigada()
{
	eliminarTodo();
}

template <typename E> void ListaLigada<E>::vaciar()
{
	eliminarTodo();
	inicializar();
}

template <typename E> void ListaLigada<E>:: insertar(const E &item)
{
	actual -> siguiente = new Eslabon<E>(item, actual -> siguiente);
	if(cola == actual)
	{
		cola = actual -> siguiente;
	}
	tamanio++;
}

template <typename E> void ListaLigada<E>:: ponAlFinal(const E &item)
{
	cola = cola -> siguiente = new Eslabon<E>(item, NULL);
	tamanio++;
}

template <typename E> E ListaLigada<E>::eliminar(void)
{
	Assert(actual -> siguiente != NULL, "Lista vacia");

	E item = actual -> siguiente -> elemento;
	Eslabon<E> *temporal = actual -> siguiente;
	if(cola == actual -> siguiente)
	{
		cola = actual;
	}
	actual -> siguiente = actual -> siguiente -> siguiente;
	delete temporal;
	tamanio--;
	return item;
}

template <typename E> void ListaLigada<E>::irAlInicio()
{
	actual = cabeza;
}

template <typename E> void ListaLigada<E>::irAlFinal()
{
	actual = cola;
	anterior();
}

template <typename E> void ListaLigada<E>:: anterior()
{
	if(actual == cabeza)
	{
		return;
	}

	Eslabon<E> *temporal = cabeza;
	while(temporal -> siguiente != actual)
	{
		temporal = temporal -> siguiente;
	}

	actual = temporal;
}

template <typename E> void ListaLigada<E>:: siguiente()
{
	if(actual -> siguiente != cola)
	{
		actual = actual -> siguiente;
	}
}

template <typename E> int ListaLigada<E>::obtenerTamanio() const
{
	return tamanio;
}

template <typename E> int ListaLigada<E>::posicionActual() const
{
	int cont = 0;

	Eslabon<E> *temporal = cabeza;
	while(temporal != actual)
	{
		temporal = temporal -> siguiente;
		cont++;
	}

	return cont;
}

template <typename E> void ListaLigada<E>::irAPosicion(int posicion)
{
	Assert((posicion >= 0 ) && (posicion < tamanio), "Posicion fuera de rango");
	actual = cabeza;
	for(int i = 0; i < posicion; i++)
	{
		actual = actual -> siguiente;
	}
}

template <typename E>
const E& ListaLigada<E>::obtenerElemento(void) const
{
	Assert(tamanio != 0, "No hay elemento.");
	return actual -> siguiente -> elemento;
}