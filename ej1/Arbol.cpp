#include <iostream>
#include "Grafo.h"
#include "Arbol.h"

Arbol::Arbol(){
}

int Arbol::altura(Nodo *N) { 
	if (N == NULL){ 
		return 0;
	} 
	return N->fe; 
}

int Arbol::max(int a, int b) { 
	return (a > b)? a : b; 
}

int Arbol::getBalance(Nodo *N) { 
	if (N == NULL){ 
		return 0; 
	}
	return altura(N->izq) - altura(N->der); 
} 

Nodo* Arbol::rotacionDer(Nodo *y) { 
	Nodo *x = y->izq; 
	Nodo *T2 = x->der; 

	x->der = y; 
	y->izq = T2; 

	y->fe = max(altura(y->izq), 
					altura(y->der)) + 1; 
	x->fe = max(altura(x->izq), 
					altura(x->der)) + 1;  
	return x; 
} 

Nodo* Arbol::rotacionIzq(Nodo *x) { 
	Nodo *y = x->der; 
	Nodo *T2 = y->izq; 

	y->izq = x; 
	x->der = T2; 
	
	x->fe = max(altura(x->izq),	 
					altura(x->der)) + 1; 
	y->fe = max(altura(y->izq), 
					altura(y->der)) + 1;
	return y; 
}  

Nodo* Arbol::crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->fe = 1;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

Nodo* Arbol::insertarNodo(Nodo *node, int dato){
	if (node == NULL) {
		return crearNodo(dato);
	} 

	if (dato < node->dato){ 
		node->izq = insertarNodo(node->izq, dato);
	} 
	else if (dato > node->dato){ 
		node->der = insertarNodo(node->der, dato);
	} 
	else{
		cout<< "ERROR DATO REPETIDO" <<endl;
		return node;
	}

	node->fe = 1 + max(altura(node->izq), 
						altura(node->der));
	int balance = getBalance(node); 

	// CASO II
	if (balance > 1 && dato < node->izq->dato){ 
		return rotacionDer(node); 
	}

	// CASO DD
	if (balance < -1 && dato > node->der->dato){ 
		return rotacionIzq(node); 
	}

	// CASO ID 
	if (balance > 1 && dato > node->izq->dato){  
		node->izq = rotacionIzq(node->izq); 
		return rotacionDer(node); 
	} 

	// CASO DI 
	if (balance < -1 && dato < node->der->dato) { 
		node->der = rotacionDer(node->der); 
		return rotacionIzq(node); 
	} 
	return node; 	
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
	while(arbol->izq != NULL){
		arbol = arbol->izq;
	}
	return arbol;
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
Nodo* Arbol::eliminarNodo(Nodo *nEliminar, int dato){ 
    
    if (nEliminar == NULL){  
        cout<< "No se ha encontrado el dato." <<endl;
        return nEliminar;
	}
	
    if(dato < nEliminar->dato){  
        nEliminar->izq = eliminarNodo(nEliminar->izq, dato);
	} 
    else if(dato > nEliminar->dato){  
        nEliminar->der = eliminarNodo(nEliminar->der, dato);
	}
    else{  
        if((nEliminar->izq == NULL) || (nEliminar->der == NULL)){  
            Nodo *temp = nEliminar->izq ?  
                         nEliminar->izq :  
                         nEliminar->der;  
            if(temp == NULL){  
                temp = nEliminar;  
                nEliminar = NULL;  
            }  
            else{  
				*nEliminar = *temp; 
				free(temp);
			}  
        }  
        else{  
            Nodo* temp = buscarMinimo(nEliminar->der);  
            nEliminar->dato = temp->dato;  
            nEliminar->der = eliminarNodo(nEliminar->der, temp->dato);  
        }  
    }  
    if(nEliminar == NULL){  
		return nEliminar;
	}  
    nEliminar->fe = 1 + max(altura(nEliminar->izq),altura(nEliminar->der));  
    
    int balance = getBalance(nEliminar);  
    
  
    // CASO II 
    if (balance > 1 &&  
        getBalance(nEliminar->izq) >= 0) {  
        return rotacionDer(nEliminar);
	}  
  
    // CASO ID 
    if (balance > 1 &&  
        getBalance(nEliminar->izq) < 0) {  
        nEliminar->izq = rotacionIzq(nEliminar->izq);  
        return rotacionDer(nEliminar);  
    }  
  
    // CASO DD  
    if (balance < -1 &&  
        getBalance(nEliminar->der) <= 0) {  
        return rotacionIzq(nEliminar);
	}  
  
    // CASO DI  
    if (balance < -1 &&  
        getBalance(nEliminar->der) > 0) {  
        nEliminar->der = rotacionDer(nEliminar->der);  
        return rotacionIzq(nEliminar);  
    }  
  
    return nEliminar;  
}

		
