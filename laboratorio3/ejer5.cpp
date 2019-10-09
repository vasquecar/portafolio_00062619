#include <iostream>

using namespace std;

struct Nodo{
  int dato;
  Nodo * sig;
};

void insert(Nodo * &list,int d){
  Nodo * newNodo=new Nodo();
  newNodo->dato=d;
  newNodo->sig=0;

  if(list==0){

    list=newNodo;
    return;

  }

  newNodo->sig=list;
  list=newNodo;
}

void print(Nodo * list){
  Nodo * temp=list;

  while(temp!=0){

    cout<< temp->dato<<endl;
    temp=temp->sig;
  }
}

Nodo * reverse(Nodo * list){
  Nodo* ptr = list;

  if(list->sig!=0){
    ptr = reverse(list->sig);

    (list->sig)->sig=list;
    list->sig=0;
  }

  return ptr;
}

int main(){
  Nodo * l = 0; //creo la cabeza de la lista

  insert(l,3);// cargo 3 valores
  insert(l,2);
  insert(l,1);

  l=reverse(l); // la cabeza de la lista apunta al ultimo elemento retornado por reverse()

  print(l);

  system("PAUSE");
  return 0;
}
