#include <iostream>
using namespace std;


struct persona{
        char pais[15];
        char capital[15];
        int habitantes;
        int prohabitantes;
};

int main(){	
    persona continente[5];
    for (int i = 0; i < 5; i++){
        cout <<"Escriba el Pais "<<i+1<<":";
        cin >> continente[i].pais;

        cout <<"\nEscriba la ciudad "<<i+1<<":";
 		cin >> continente[i].capital;      

        cout <<"\nEscriba el numero de habitantes "<<i+1<<":";
        cin >> continente[i].habitantes;

        cout <<"\nEscriba el promedio de las edades de los habitantes "<<i+1<<":";
        cin >> continente[i].prohabitantes;
        
        cout <<endl;
    }
int cont;
int total=0,prom=0,promedio=0;
    cout<<"El o los contientes al que pertenece los paises : \n\n";
	cin >> cont;
	cout <<endl;
    for (int i = 0; i < 5; i++){
        cout<<"\t"<<continente[i].pais;
        cout<<"\t"<<continente[i].capital;
        cout<<"\t"<<continente[i].habitantes;
        total+= continente[i].habitantes ;
        cout<<"\t"<<continente[i].prohabitantes<<"\n\n";
        prom+= continente[i].prohabitantes;
        promedio=prom/5;
   }
   
   cout << "la suma de los habitantes de los paises es: "<< total;
   cout <<endl; 
   cout << "el promedio de las edades de los paises es: "<< promedio;
   cout <<endl; 
   
   return 0;
}
