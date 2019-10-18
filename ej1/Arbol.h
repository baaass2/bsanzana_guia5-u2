#include <iostream>
using namespace std;


class Arbol {
	public:
		Arbol();
		Nodo *crearNodo(int);
		void insertarNodo(Nodo *&, int);
		void imprimirPreorden(Nodo *);
		void imprimirInorden(Nodo *);
		void imprimirPosorden(Nodo *);
		Nodo *busqueda(Nodo *, int);
		void eliminarNodo(Nodo *&, int);
		Nodo *buscarMinimo(Nodo *);
		void reemplezar(Nodo *&, Nodo *&);
      
};

