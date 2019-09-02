
#include <iostream>
using namespace std;

int multi(int n1, int num){
	if(num==1){
		cout << "n=" << num << " caso base" << endl;
		return n1;
	}else{
		int x = num - 1;
		int y = multi(n1,x);
		cout << "n=" << n1 << " x=" << x <<
			" y=" << y << endl;
		return n1 + y;
	}
}

int main()
{
	 int n1,n2,p;

 cout << "Introduzca primer numero: ";
 cin >> n1;
 cout << "Introduzca segundo numero: ";
 cin >> n2;
p=multi(n1,n2);
 cout << "producto: " << p << endl;
	
}

