#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef nodo *ptrPila; 

void initialize(ptrPila *s){
    *s = NULL;
}
bool empty (ptrPila *s){
	return *s==NULL;
}

void push( ptrPila &p, int valor ){
     ptrPila aux;
     aux = (struct nodo*)malloc(sizeof(struct nodo));  
     aux->nro = valor;
     aux->sgte = p ;
     p = aux ;
}

float pop(ptrPila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        float e = (*s)->nro;
        *s = (*s)->sgte;
        delete(unNodo);
        return e;
    }
    else{
        cout << "Underflow!" << endl;
        return -1;
    }
}
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;    
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }    
}
 

void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
 
void menu()
{
    cout<<"Escoge una de las siguientes opciones" << endl;
    cout<<" 1. Apilar                                "<<endl;
    cout<<" 2. Desapilar                             "<<endl;
    cout<<" 3. Mostrar pila                          "<<endl;
    cout<<" 4. Destruir pila                         "<<endl;
    cout<<" 5. Salir                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

int main()
{
    ptrPila p = NULL;  
    int dato;
    int op;
    int x ; 
    
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A APILAR: "; cin>> dato;
                 push( p, dato );
                 cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
            break;
 
 
            case 2:
 
                 x = pop( &p );
                 cout<<"\n\n\t\tNumero "<< x <<" desapilado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p!=NULL)
                    mostrar_pila( p );
                 else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;
 
 
            case 4:
 
                 destruir_pila( p );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}
