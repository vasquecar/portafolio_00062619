#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
void orden(Arbol, void (*func)(int*));
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void Mostrar(int *d);

int main(void){
   Arbol ArbolInt=NULL;
   int altura;
   int nnodos;
   Insertar(&ArbolInt, 10);
   Insertar(&ArbolInt, 5);
   Insertar(&ArbolInt, 12);
   Insertar(&ArbolInt, 4);
   Insertar(&ArbolInt, 7);
   Insertar(&ArbolInt, 3);
   Insertar(&ArbolInt, 6);
   Insertar(&ArbolInt, 9);
   Insertar(&ArbolInt, 8);
   Insertar(&ArbolInt, 11);
   Insertar(&ArbolInt, 14);
   Insertar(&ArbolInt, 13);
   Insertar(&ArbolInt, 2);
   Insertar(&ArbolInt, 1);
   Insertar(&ArbolInt, 15);
   Insertar(&ArbolInt, 10);
   Insertar(&ArbolInt, 17);
   Insertar(&ArbolInt, 18);
   Insertar(&ArbolInt, 16);

   printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));
   printf("InOrden: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("PreOrden: ");
   PreOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("PostOrden: ");
   PostOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("Orden de mayor a menor: "); 
   orden(ArbolInt, Mostrar);
   printf("\n");
   printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
   Borrar(&ArbolInt, 5);
   printf("Borrar 5: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   Borrar(&ArbolInt, 8);
   printf("Borrar 8: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   Borrar(&ArbolInt, 15);
   printf("Borrar 15: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   Borrar(&ArbolInt, 245);
   printf("Borrar 245: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   Borrar(&ArbolInt, 4);
   printf("Borrar 4: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   Borrar(&ArbolInt, 17);
   printf("Borrar 17: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");

   printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
//   printf("Altura de 1 %d\n", Altura(ArbolInt, 1));
//   printf("Altura de 10 %d\n", Altura(ArbolInt, 10));
   printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));

   Podar(&ArbolInt);
   system("PAUSE");
   return 0;
}

void Podar(Arbol *a)
{
   if(*a) {
      Podar(&(*a)->izquierdo); /* Podar izquierdo */
      Podar(&(*a)->derecho);   /* Podar derecho */
      free(*a);                
      *a = NULL;
   }
}

void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }
   if(!Vacio(actual)) return;
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   while(!Vacio(actual)) {
      if(dat == actual->dato) { 
         if(EsHoja(actual)) { 
            if(padre) 
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); 
            actual = NULL;
            return;
         }
         else { 
            padre = actual;
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else {
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

void orden(Arbol a, void (*func)(int*))
{
   if(a->derecho) orden(a->derecho, func);
   func(&(a->dato));
   if(a->izquierdo) orden(a->izquierdo, func);
}

void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}


void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; 
      else if(dat < actual->dato) actual = actual->izquierdo; 
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; 
}

int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; 
      else {
         altura++; 
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; 
}

int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); 
   return *contador;
}

void auxContador(Arbol nodo, int *c)
{
   (*c)++; 
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); 
   return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura)
{
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(Arbol r)
{
   return r==NULL;
}

int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

void Mostrar(int *d)
{
   printf("%d, ", *d);
}

