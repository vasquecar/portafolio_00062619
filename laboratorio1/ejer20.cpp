#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int x,y;
int inf=0;
cout<< "digite los valores que desee:" << endl;
int mat[5][5];
	for(int a=0;a<5;a++)
	for(int b=0;b<5;b++) {
cout<<"ingrese numero ["<< a <<"]["<< b <<"]";
cin >> mat[a][b];
}
cout<<endl;
cout<< setw(15) <<"matriz";
cout<<endl<<endl;
	for(int c=0;c<5;c++) {
	for(int d=0;d<5;d++) {
cout<<setw(5)<<mat[c][d]; }
cout<<endl; }
for(int e=0;e<5;e++)

for(int f=0;f<5;f++) {
if(e>f){
inf=inf+mat[e][f];} 
}
if(inf==0)
cout<<"la matriz si es una matriz triangular superior";
else
cout<<"la matriz no es una matriz triangular superior";
getch();
return 0;
}
