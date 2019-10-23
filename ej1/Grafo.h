#include <iostream>
#include <fstream>

using namespace std;

/* Archivo .h con todas las cabeceras */
typedef struct _Nodo {
    int dato,fe;
    struct _Nodo *izq;
    struct _Nodo *der;
} Nodo;

class Grafo {
    private:
        Nodo *arbol = NULL;

    public:
        /* constructor*/
        Grafo(Nodo *arbol);
        
        /* Métodos de la clase Grafo */
        void crearGrafo();
        void recorrerArbol (Nodo *, ofstream &);
        
};
