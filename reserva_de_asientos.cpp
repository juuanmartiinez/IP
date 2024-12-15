#include <iostream>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 5;

typedef int Teatro[FILAS][COLUMNAS];

void generarTeatro (Teatro &t){

    int i,j;

    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ; j++){
            t[i][j] = rand() % (1 + 1);
        }
    }
}

void imprimirTeatro (Teatro &t){

    int i,j;

    for(i = 0 ; i < FILAS ; i++){
        cout << "|";
        for(j = 0 ; j < COLUMNAS ; j++){
            cout << t[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

void reservarAsiento (Teatro &t, int fila, int columna){

    int i,j;
    bool asientoEncontrado;
    asientoEncontrado = false;
    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ; j++){
            if(i == fila && j == columna){
                asientoEncontrado = true;
                if(t[i][j] == 0){
                    cout << "Reserva realizada." << endl;
                }else{
                    cout << "El asiento ya esta reservado." << endl;
                }
                break;
            }
        }
        if(asientoEncontrado){
            break;
        }
        
    }
    if(!asientoEncontrado){
        cout << "Asiento invalido." << endl;
    }
}

void cancelarReserva(Teatro &t, int fila, int columna){

    int i,j;
    bool asientoEncontrado;
    asientoEncontrado = false;
    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ; j++){
            if(i == fila && j == columna){
                asientoEncontrado = true;
                if(t[i][j] == 1){
                    cout << "Cancelacion realizada con exito." << endl;
                }else{
                    cout << "El asiento no esta reservado" << endl;
                }
                break;
            }
        }
        if(asientoEncontrado){
            break;
        }
    }
    if(!asientoEncontrado){
        cout << "Asiento invalido." << endl;
    }
}

int main (){
    
    Teatro t;
    int opcion;

    while(opcion != 4){

        cout << "Sistema de Reserva de Asientos." << endl;
        cout << "1. Mostrar plano de asientos." << endl;
        cout << "2. Reservar asientos." << endl;
        cout << "3. Cancelar reserva." << endl;
        cout << "4. Salir." << endl;
        cout << "SELECCIONE UNA OPCIÓN:";
        cin >> opcion;

        if(opcion == 1){

            cout << "TEATRO." << endl;
            generarTeatro(t);
            imprimirTeatro(t);
        }else if(opcion == 2){
            int fila, columna;
            cout << "Introduce una fila: ";
            cin >> fila;
            cout << "Introduce una columna: ";
            cin >> columna;

            reservarAsiento(t,fila - 1,columna -1);
        }else if(opcion == 3){
            int fila, columna;
            cout << "Introduce una fila: ";
            cin >> fila;
            cout << "Introduce una columna: ";
            cin >> columna;
            cancelarReserva(t,fila - 1,columna - 1);
        }else if(opcion != 4){
            cout << "Opcion no válida." << endl;
        }
    }
    return 0;
}