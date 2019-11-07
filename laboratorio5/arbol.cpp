#include <iostream>
using namespace std;

//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void recorrerPersonalizado(Arbol p){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nSe encuentra en el nodo " << p->info <<endl;
        cout << "\t1)Agregar nodo izquierda\n\t2)Agregar nodo derecha\n";
        cout << "\t3)Ir sub-arbol izquierdo\n\t4)Ir sub-arbol derecho\n";
        cout << "\t5)Regresar al nodo padre\n\tOpcion: ";
        cin >> opcion;
        switch(opcion){
            case 1: 
                if (p->izq == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarIzq(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol izquierdo" << endl;
                break;
            case 2: 
                if (p->der == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarDer(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol derecho" << endl;
                break;
            case 3: 
                if (p->izq != NULL)
                    recorrerPersonalizado(p->izq);
                else
                    cout << "Error: NO existe sub-arbol izquierdo" << endl;
                break;
            case 4:
                if (p->der != NULL)
                    recorrerPersonalizado(p->der);
                else
                    cout << "Error: NO existe sub-arbol derecho" << endl;
                break;
            case 5:
                continuar = false;
                break;
            default:
                cout << "Error: Opcion no valida" << endl;
                break;
        }
    }while(continuar);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}


int altura(Arbol a)
{
    int AltIzq, AltDer;

    if(a==NULL)
        return -1;
    else
    {
        AltIzq = altura(a->izq);
        AltDer = altura(a->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

 int NumeroNodo(Arbol a)
{
	if(a==NULL)
		return 0;
	
	else
		return 1+NumeroNodo(a->izq)+NumeroNodo(a->der);
}

int Sumanodos(Arbol a)
{
	if(a==NULL)
		return 0;

	return a->info + Sumanodos(a->der) + Sumanodos(a->izq);

}

int FE(Arbol a)
{
	if(a==NULL)
		return 0;
	
	else 
		return altura(a->der)-altura(a->izq);
}

int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;
    
    Arbol arbol = crearArbol(variable);
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu:\n\t1) Mostrar recorridos";
        cout << "\n\t2) Recorrer personalizado";
        cout << "\n\t3) Altura o profundidad ";
        cout << "\n\t4) Numero  de nodos ";
        cout << "\n\t5) Suma  de nodos ";
        cout << "\n\t6) Equilibrio ";
		cout << "\n\t7) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: recorrerArbol(arbol);
            break;
            case 2: recorrerPersonalizado(arbol);
            break;
            case 3: 
            int h;
                h = altura(arbol);
            	cout << " La altura es : "<< h << endl;
            break;
            case 4:
            int x;	
				x = NumeroNodo(arbol);
				cout << "Numero de Nodos es :"<< x << endl;
			break;
			case 5:
				int n;
				n = Sumanodos(arbol);
				cout << "La suma de nodos es: " << n << endl;
			break;
			case 6:
				int frecu;
				frecu=FE(arbol);
				printf("Factor de Equilibrio es %d \n", frecu);
				break;
            case 7: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
    
    return 0;
}
