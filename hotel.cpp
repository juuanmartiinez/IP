#include <iostream>

using namespace std;

const int PISOS = 10;
const int HABITACIONES = 10;
typedef int Hotel[PISOS][HABITACIONES];

typedef float Precio[1][4];

void generarHotel (Hotel &h){

    int i,j;

    for(i = 0 ; i < PISOS ; i++){
        for(j = 0 ; j < HABITACIONES ; j++){
            h[i][j] = rand() % (1 + 4);
        }
    }
}

void imprimirHotel (Hotel &h){

    int i,j;

    for(i = 0 ; i < PISOS ; i++){
        cout << i  << " " << "[ ";
        for(j = 0 ; j < HABITACIONES ; j++){
            cout << h[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void habitaciones (Hotel &h){

    int i,j;
    int conthab,contlib;
    conthab = 0;
    contlib = 0;
    
    for(i = 0; i < PISOS ; i++){
        for(j = 0 ; j < HABITACIONES ; j++){
            if(!(h[i][j] == 0)){
                conthab++;
            }else{
                contlib++;
            }
        }
    }
    cout << "Habitaciones Libres: " << conthab << endl;
    cout << "Habitaciones Ocupadas: " << contlib << endl;
}

int maxHabitaciones (Hotel &h){

    int i,j;
    int maxHab,maxPiso;
    int sumahab;
    sumahab = 0;
    maxHab = -999;
    for(i = 0 ; i < PISOS ; i++){
        sumahab = 0;
        for(j = 0 ; j < HABITACIONES ; j++){
            if(!(h[i][j] == 0)){
                sumahab++;
            }
            if(sumahab > maxHab){
                maxHab = sumahab;
                maxPiso = i;
            }
        }
    }
    cout << "El piso con más habitaciones ocupadas será el piso " << maxPiso  <<  " con " << maxHab << " habitaciones ocupadas." << endl;;
    return maxHab;
}

bool pisoVacio (Hotel &h){

    int i,j;

    for(i = 0; i < PISOS ; i++){
        for(j = 0; j < HABITACIONES ; j++){
            if(h[i][j] == 0){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

float dineroPorPiso (Hotel &h , Precio &p){

    int i,j;
    int Piso;
    float sumaPiso;
    float cuenta;
    float maxPiso;
    maxPiso = -9999;
    sumaPiso = 0;
    cuenta = 0;
    for(i = 0; i < PISOS ; i++){
        sumaPiso = 0;
        cuenta = 0;
        for(j = 0 ; j < HABITACIONES ; j++){
            if(h[i][j] == 0){
                sumaPiso = 0;
            }else{
                if(h[i][j] == 1){
                    cuenta = p[0][0];
                    sumaPiso += cuenta;
                }else if(h[i][j] == 2){
                    cuenta = p[0][1];
                    sumaPiso += cuenta;
                }else if(h[i][j] == 3){
                    cuenta = p[0][2];
                    sumaPiso += cuenta;
                }else if(h[i][j] == 4){
                    cuenta = p[0][3];
                    sumaPiso += cuenta;
                }
            }
        }
        if(sumaPiso > maxPiso){
            maxPiso = sumaPiso;
            Piso = i;
        }
    }
    cout << "El piso que genera mas dinero será el " << Piso << " que genera " << maxPiso << endl;
    return Piso;
}

int main () {

    Hotel h;
    Precio p = {{37.5,56.75,77.5,110.5}};

    generarHotel(h);
    imprimirHotel(h);
    habitaciones(h);
    maxHabitaciones(h);

    if(pisoVacio(h)){
        cout << "Hay un piso vacio." << endl;
    }else{
        cout << "Ningun piso esta vacio." << endl;
    }

    dineroPorPiso(h,p);

    return 0;
}
