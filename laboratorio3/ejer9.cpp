#include <iostream>
#include <vector>
using namespace std;

struct Tpersona{
    string carnet;
    string nombre;
    string apellido;
    string edad;
    string telefono;
    string email;
};
typedef struct Tpersona persona;

persona solicitarpersona(){
    persona p;
    cout << "Carnet: "; cin >> p.carnet;
    cout << "Nombre: ";   cin >> p.nombre;
    cout << "Apellidos: "; cin >> p.apellido;
    cout << "Edad: "; cin >> p.edad;
    cout << "Telefono: "; cin >> p.telefono;
    cout << "Correo electronico: "; cin >> p.email;
    return p;
}

void mostrarpersona(persona p){
    cout << "Carnet : " << p.carnet << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Telefono: " << p.telefono << endl;
    cout << "Correo electronico: " << p.email << endl;
    cout << endl;
}


vector<persona> lista;

void agregarpersona(){
    persona p = solicitarpersona();
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
        mostrarpersona(lista[i]);
}

 void eliminarpersona() {
// no pude eliminar la persona
//dejo espacio para poder hacerlo mas adelante o preguntar el dia de mañana.
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar persona\n\t2) Ver personas"
            << "\n\t3) Eliminar Persona \n\t4) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarpersona();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: cout << "Eliminando..." << endl;
                eliminarpersona();
            break;
            case 4: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
