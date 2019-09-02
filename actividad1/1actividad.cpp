#include <iostream>
using namespace std;

void calculos(int num, int *doble, int *triple) {
	*doble = 2 * num;
	*triple = 3 * num;
}	

int main(){
	int numero = 2, doble = 0, triple = 0;
	
	calculos(numero, &doble, &triple);
	cout << "El doble de 2 es " << doble << endl;
	cout << "El triple de 2 es " << triple<< endl;
	cout << "direccion de Numero " << &numero << endl;
	cout << "direccion de doble " << &doble << endl; 
	cout << "direccion de triple " << &triple << endl;

	return 0;
}
