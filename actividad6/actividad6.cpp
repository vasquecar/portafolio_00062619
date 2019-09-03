#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int busquedaBinaria(const int[], int, int); 
void orArreglo(int[], int); 
void inter(int&, int&); 
int main(void) {
  int clave =0;
  const int tamano = 8;
  int arreglo[tamano] = {1,3,4,5,17,18,31,33};
  cout << "digite el numero que desee y se le devolvera su indice " << endl;
  cin >> clave;
  cout<< "Su valor se encuentra en arreglo  ["<<busquedaBinaria(arreglo,tamano,clave)<<"]" << endl;
  return 0;
}
int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int arriba = tamano-1;
  int abajo = 0;
  int centro;
  while (abajo <= arriba)
    {
      centro = (arriba + abajo)/2;
      if (arreglo[centro] == clave)
 return centro;
      else
 if (clave < arreglo[centro])
   arriba=centro-1;
 else
   abajo=centro+1;
    }
  return -1;
}
void orArreglo(int arreglo[], int tamano)
{
  for (int i = 0; i< tamano -1 ; i++)
    for (int j = 0; j< tamano -1 ; j++)
      if (arreglo[j] > arreglo[j+1])
 inter(arreglo[j],arreglo[j+1]);
}
void inter(int &a, int &b)
{
  int tmp = b;
  b = a;
  a = tmp;
}
