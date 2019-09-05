#include <iostream>
#include <cmath>
using namespace std; 

   int main (){
   	int R, I;
   	float raiz;
   cout << "Introduzca la parte real del numero: " << endl;
   cin >> R;
   cout << "Introduzca la parte compleja del numero: " << endl;
   cin >> I;
   raiz = sqrt(pow(R,2)+pow(I,2));
 
  cout << "EL valor absoluto es: " << raiz << endl;
   
   return 0;
   }          

