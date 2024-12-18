#include <iostream>

using namespace std;

const int PLANTAS = 6;
const int HABITACIONES = 10;

struct Habitacion
{
    int numero;
    int libre;
    int espacio;
};

typedef Habitacion Hotel[PLANTAS][HABITACIONES];

void generarHotel (Hotel &h){

    int i,j;

    for(i = 0 ; i < PLANTAS ; i++){
        for(j = 0 ; j < HABITACIONES ; j++){
            h[i][j].numero = (i + 1) * 100 + (j + 1);
            h[i][j].espacio = rand() % (1 + 5);
            h[i][j].libre = rand() % (0 + 2);        // 1 SERÁ OCUPADA, 0 SERÁ QUE LA HABITACIÓN ESTA LIBRE
        }
    }
}

void imprimirHotel (Hotel &h){

    int i,j;

    for(i = 0 ; i < PLANTAS ; i++){
        cout << "PLANTA " << i + 1 << " | ";
        for(j = 0 ; j < HABITACIONES ; j++){
            cout << "[ " << h[i][j].numero << " ";
            cout << h[i][j].espacio << " ";
            cout << h[i][j].libre << " ";
            cout << " ]";
        }
        cout << " |" << endl;
    }
}

int buscarHabitacion (Hotel h, int clientes){

    int i,j;
    int habitacionEncontrada;
    for(i = 0 ; i < PLANTAS  ; i++){
        for(j = 0 ; j < HABITACIONES ; j++){
            if(clientes == h[i][j].espacio && h[i][j].libre == 0){
                habitacionEncontrada = h[i][j].numero;
            }
        }
    }
    return habitacionEncontrada;
}

int main (){

    Hotel h;
    int clientes;

    generarHotel(h);
    imprimirHotel(h);

    cout << "Introduce el número de personas para una habitación: ";
    cin >> clientes;

    cout << "Habitacion: " << buscarHabitacion(h,clientes) << endl;

    return 0;
}
