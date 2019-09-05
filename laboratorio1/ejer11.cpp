#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
 using namespace std;
int main(void) {
	float maximo[5], max=0;
	int x=0;
	cout <<"Ingrese 5 valores para determinar el numero maximo" << endl;
	for (int i = 1; i <= 5; i++){
		cout << "valor "<<i << ":";
		scanf("%f",&maximo[i]);
		if(maximo[i] > max){
			max = maximo[i];
		}
	}
	cout << "El numero maximo es :" <<max;
	return 0;
}
