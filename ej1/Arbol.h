#include <iostream>
using namespace std;


class Arbol {
	public:
		Arbol();
		Nodo* crearNodo(int);
		Nodo* insertarNodo(Nodo *, int);
		void imprimirPreorden(Nodo *);
		void imprimirInorden(Nodo *);
		void imprimirPosorden(Nodo *);
		Nodo* eliminarNodo(Nodo *, int);
		Nodo* buscarMinimo(Nodo *);
		void reemplezar(Nodo *&, Nodo *&);
		int altura(Nodo *);
		int max(int, int );
		int getBalance(Nodo *);
		Nodo* rotacionDer(Nodo *);
		Nodo* rotacionIzq(Nodo *);
};

