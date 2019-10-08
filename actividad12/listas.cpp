#include <iostream>
#include <vector>
using namespace std;

struct Torden{
    string revueltas;
    string frijolconQueso;
    string queso;
};
typedef struct Torden orden;

orden solicitarorden(){
    orden p;
    cout << "Revueltas: "; cin >> p.revueltas;
    cout << "Frijol con Queso: ";   cin >> p.frijolconQueso;
    cout << "Queso: "; cin >> p.queso;
    return p;
}

void mostrarorden(orden p){
    cout << "Revueltas: " << p.revueltas << endl;
    cout << "Friol con Queso: " << p.frijolconQueso << endl;
    cout << "Queso: " << p.queso << endl;
    cout << endl;
}

vector<orden> lista;

void agregarorden(){
    orden p = solicitarorden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), p);
                continuar = false;
            break;
            case 2: lista.push_back(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++) 
        mostrarorden(lista[i]);
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Orden\n\t2) Ver orden"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarorden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
