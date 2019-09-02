#include <iostream>
#include<stdio.h>
using namespace std;

int main(void){
//el calculo se hace con unicamente con 5 datos esto puede variar.
  int i,j, aux, a[5];
  for(i = 0; i < 5; i++){
    cout <<"Ingresa un numero: ";
    scanf("%d", &a[i]);
  } 

  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
        if(a[j] > a[j + 1]){
            aux = a[j];
            a[j] = a[j + 1];
            a[j + 1] = aux;
        }
    }
  }
  cout<<"La mediana es:" << a[2]<<endl;
return 0;
}
