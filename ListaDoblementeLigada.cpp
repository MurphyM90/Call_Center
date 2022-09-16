#include "ListaDoblementeLigada.h"
#include <string>
#include <iostream>
#include <cstdlib>

template <typename E> void ListaDoblementeLigada<E> :: inicializar() 
{
	cabeza = new Eslabon<E>;
	actual = cabeza->siguiente = cabeza->anterior = cola = new Eslabon<E>(cabeza, cabeza);
	tamanio = 0;
}

template <typename E> void ListaDoblementeLigada<E> :: eliminarTodo() 
{
	while(cabeza != cola) 
	{
		actual = cabeza;
		cabeza = cabeza->siguiente;
		delete actual;
	}
	actual = cabeza;
	delete actual;
}

template <typename E> ListaDoblementeLigada<E> :: ListaDoblementeLigada() 
{
	inicializar();
}

template <typename E> ListaDoblementeLigada<E> :: ~ListaDoblementeLigada() 
{
	eliminarTodo();
}

template <typename E> void ListaDoblementeLigada<E> :: vaciar() 
{
	eliminarTodo();
	inicializar();
}

template <typename E> void ListaDoblementeLigada<E> :: insertar(const E & item) 
{
	actual = actual->anterior = actual->anterior->siguiente = new Eslabon<E>(item, actual->anterior, actual);
	tamanio++;
}

template <typename E> void ListaDoblementeLigada<E> :: ponAlFinal(const E& item) 
{
	cola->anterior = cola->anterior->siguiente = new Eslabon<E>(item, cola->anterior, cola);
	tamanio++;
}

template <typename E> E ListaDoblementeLigada<E> :: eliminar(void) 
{
	E item = actual->elemento;
	Eslabon<E> *temporal = actual;
	actual->siguiente->anterior = actual->anterior;
	actual->anterior->siguiente = actual->siguiente;
	delete temporal;
	tamanio--;
	return item;
}

template <typename E> void ListaDoblementeLigada<E> :: irAlInicio() 
{
	actual = cabeza->siguiente;
}

template <typename E> void ListaDoblementeLigada<E> :: irAlFinal() 
{
	if(cola->anterior != cabeza)
		actual = cola->anterior;
}

template <typename E> void ListaDoblementeLigada<E> :: anterior() 
{
	if(tamanio == 0)
		return;
	if(actual->anterior != cabeza and tamanio != 0) // No se si es valido el and en c++
		actual = actual->anterior;
	else
		actual = cola->anterior;
}

template <typename E> void ListaDoblementeLigada<E> :: siguiente() 
{
	if(tamanio == 0)
		return;
	if(actual->siguiente != cola)
		actual = actual->siguiente;
	else
		actual = cabeza->siguiente;
}

template <typename E> int ListaDoblementeLigada<E> :: obtenerTamanio() const 
{
	return tamanio;
}

template <typename E> int ListaDoblementeLigada<E> :: posicionActual() const 
{
	Eslabon<E> *aux = cabeza;

	int i;
	for(i = 0; aux != actual; i++)
		aux = aux->siguiente;

	return i;
}

template <typename E> void ListaDoblementeLigada<E> :: irAPosicion(int posicion) 
{
	if(posicion < 0 && posicion > tamanio-1)
		exit(-1);
	actual = cabeza->siguiente;
	for(int i = 0; i < posicion; i++)
		actual = actual->siguiente;
}

template <typename E> const E & ListaDoblementeLigada<E> :: obtenerElemento(void) const 
{
	if(tamanio == 0)
		exit(-1);
	return actual->elemento;
}

