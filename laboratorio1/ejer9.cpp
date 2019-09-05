#include <iostream>
#include <cmath>
using namespace std;

int suma(int n1, int num, int limsup){
	if(limsup==num){
		return pow(n1, num);
	}else{
		return pow(n1, num) + suma(n1, num+1, limsup);
	}
}

int main()
{
	 int n1,n2,p;

 cout << "Introduzca primer numero: ";
 cin >> n1;
 cout << "Introduzca segundo numero: ";
 cin >> n2;
p=suma(n1,0,n2);
 cout << "suma: " << p << endl;
	
}


