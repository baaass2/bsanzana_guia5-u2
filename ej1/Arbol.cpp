#include <iostream>
#include "Grafo.h"
#include "Arbol.h"

Arbol::Arbol(){
}

Nodo* Arbol::crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->fe = 0;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

void Arbol::insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
	}else{
		int valorRaiz = arbol->dato;
		
		if(n < valorRaiz){
			insertarNodo(arbol->izq, n);
		}
		else if(n > valorRaiz){
			insertarNodo(arbol->der, n);		
		}else{
			cout<< "ERROR: DATO REPETIDO" <<endl;
		}
			
	}
}
void Arbol::imprimirPreorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		cout<< arbol->dato << "-";
		imprimirPreorden(arbol->izq);
		imprimirPreorden(arbol->der);
	}
}
void Arbol::imprimirInorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirInorden(arbol->izq);
		cout<< arbol->dato << "-";
		imprimirInorden(arbol->der);
	}
}
void Arbol::imprimirPosorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirPosorden(arbol->izq);
		imprimirPosorden(arbol->der);
		cout<< arbol->dato << "-";
	}
}
Nodo* Arbol::buscarMinimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq != NULL){
		return buscarMinimo(arbol->izq);
	}else{
		return arbol;
	}
}
void Arbol::eliminarNodo(Nodo *&nEliminar, int n){
	
	Nodo* nOtro = NULL;
	Nodo* nAux_der = NULL;
	Nodo* nAux_derMax = NULL;
	
	if(nEliminar != NULL){
		if(n < nEliminar->dato){
			eliminarNodo(nEliminar->izq, n);
		}
		else if(n > nEliminar->dato){
			eliminarNodo(nEliminar->der, n);
		}else{
			nOtro = nEliminar;
			if(nOtro->der == NULL){
				nEliminar = nOtro->izq;
			}
			else if(nOtro->izq == NULL){
				nEliminar = nOtro->der;
			}
			else{
				reemplezar(nEliminar->izq, nOtro);
			}
		}
	}
	else{
		cout<< "No se ha encontrado nodo." <<endl;
	}
}

void Arbol::reemplezar(Nodo *&nEliminar, Nodo *&nOtro){
	
	if(nEliminar->der == NULL){
		nOtro->dato = nEliminar->dato;
		nOtro = nEliminar;
		nEliminar = nOtro->izq; 
	}else{
		reemplezar(nEliminar->der, nOtro);
	}
}

Nodo* Arbol::busqueda(Nodo *nEliminar, int n){
	
	if(nEliminar == NULL){
		cout<< "No se ha encontrado nodo." <<endl;
	}
	else if(n < nEliminar->dato){	
		busqueda(nEliminar->izq, n);
	}
	else if(n > nEliminar->dato){
		busqueda(nEliminar->der, n);
	}else{
		return nEliminar;
	}
}

		
