
//ejercicio 7 

#include <iostream>

using namespace std;

int main()
{
    int num, fin;
cout <<"ingrese el primer numero " << endl;
cin >> num;
cout << "ingrese un valor mayor al primero " << endl;
cin >> fin;
    for (int i=num+1;i<=fin-1;i++)
    { 

        num=i%1;

        if (num==0) { 
            printf("%d   ", i);  
        }
    }
    
    return 0;
}

