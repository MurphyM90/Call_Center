#ifndef LISTA_DINAMICA_HPP_INCLUDED
#define LISTA_DINAMICA_HPP_INCLUDED

#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;

template <typename E> class Eslabon
{
	public:
		E elemento;
		Eslabon *siguiente;
		Eslabon(const E& valorElemento, Eslabon* valorSiguiente = NULL);
		Eslabon(Eslabon* valorSiguiente=NULL);

}

template <typename E> class ListaLigada: public Lista<E>
{
	private:
		Eslabon <E>* cabeza;
		Eslabon <E>*cola;
		Eslabon <E>*actual;

		int tamanio;
		void inicializar(void);
		void eliminarTodo(void);

	public:
		ListaEstatica(void);
		~ListaEstatica(void);
		void vaciar(void);
		void insertar(const E &);
		void ponAlFinal(const E &);
		E eliminar(void);
		void irAlInicio(void);
		void irAlFinal(void);
		void anterior(void);
		void siguiente(void);

		int tamanio(void) const;
		int posicionActual(void) const;
		void irAPosicion(int);
		const E &obtenerElemento(void) const
};



#endif // LISTA_DINAMICA_HPP_INCLUDED
