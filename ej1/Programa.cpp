#include <iostream>
#include "Grafo.h"
#include "Arbol.h"
using namespace std;

void menu(Arbol a){
	
	int opc = 0;
	int dato = 0;
	int datoNuevo = 0;
	Nodo *arbol = NULL;
	
	
	cout<< "MENU" <<endl;
	
	while(opc != 6){
		opc = 0;
		cout<< "" <<endl;
		cout<< "[1] Insertar nodo." <<endl;
		cout<< "[2] Eliminar nodo." <<endl;
		cout<< "[3] Modificar nodo." <<endl;
		cout<< "[4] Imprimir Preorden, Inorden y Posorden." <<endl;
		cout<< "[5] Generar Grafo." <<endl;
		cout<< "[6] Salir.        " <<endl;
		cout<< "Eliga una opción: "; 
		cin >> opc;
		
		if(opc == 1){
			cout<< "Digite un numero: "; 
			cin >> dato;
			arbol = a.insertarNodo(arbol,dato);
		}
		else if(opc == 2){
			cout<< "Digite nodo a eliminar: "; 
			cin >> dato;
			arbol = a.eliminarNodo(arbol, dato);
		}
		else if(opc==3){
			cout<< "Digite nodo a modificar: "; 
			cin >> dato;
			cout << "" <<endl;
			arbol = a.eliminarNodo(arbol, dato);
			cout<< "Digite valor del nodo nuevo: "; 
			cin >> datoNuevo;
			arbol = a.insertarNodo(arbol, datoNuevo);	
		}
		else if(opc==4){
			cout<< "PREORDEN"<<endl;
			a.imprimirPreorden(arbol);
			cout<< "" <<endl;
			cout<< "INORDEN"<<endl;
			a.imprimirInorden(arbol);
			cout<< "" <<endl;
			cout<< "POSORDEN"<<endl;
			a.imprimirPosorden(arbol);		
		}
		else if(opc==5){
			Grafo *grap = new Grafo(arbol);
			grap->crearGrafo();
		}
	}
}

int main (void) {
	Arbol a = Arbol();
	menu(a);
	
    return 0;
}
