#ifndef LISTA_H
#define LISTA_H

template <typename E> class Lista {
private:
	void operator = (const Lista &){};
	Lista(const Lista &){};
public:
	Lista(void){}
	virtual ~Lista(void){};
	virtual void vaciar(void)=0;
	virtual void insertar(const E &)=0;
	virtual void ponAlFinal(const E &)=0;
	virtual E eliminar(void)=0;
	virtual void irAlInicio(void)=0;
	virtual void irAlFinal(void)=0;
	virtual void anterior(void)=0;
	virtual void siguiente(void)=0;
	virtual int obtenerTamanio(void) const=0;
	virtual int posicionActual(void) const=0;
	virtual void irAPosicion(int pos)=0;
	virtual const E &obtenerElemento(void) const=0;

	virtual bool isEmpty(void) = 0;
	/*
	
	virtual void toString(void) = 0;
	virtual void insertOrder(const E &) const = 0;
	virtual const E &search(const E &) const = 0;
	virtual void searchAllCoindicences(const E &) const = 0;
	virtual void modificarElemento(const E &) const = 0;
	*/
};

#endif

