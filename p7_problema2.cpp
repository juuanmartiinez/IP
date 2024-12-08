#include <iostream>

using namespace std;

typedef int Existencias[10][30];

void imprimirTabla (Existencias &e){

    int i,j;

    for(i = 0;i < 10 ; i++){
        cout << "[ ";
        for(j = 0; j < 30 ; j++){
            cout << e[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void generarTabla (Existencias &e){

    int i,j;

    for(i = 0; i < 10 ; i++){
        for(j =0; j < 30; j++){
            e[i][j] = rand() % (1 + 1);
        }
    }
}

void imprimirExistencias (Existencias &e){

    int i,j;

    for(i = 0; i < 10; i++){
        int suma = 0;
        for(j = 0; j < 30 ; j++){
            suma += e[i][j];
        }
        cout << "Existencias en el consesionario " << i + 1 << " : " << suma << endl;
    }
}

int detectarConcesionario (Existencias &e,int vehiculo){

    int i,j;
    int concesionario;

    for(i = 0; i < 10 ; i++){
        if(e[i][vehiculo] != 0){
            concesionario = i;
            cout << "Concesionario: " << concesionario + 1 << endl;    
        }
    }
    return concesionario;
}

int main (){

    Existencias e;
    int vehiculo;


    generarTabla(e);
    imprimirTabla(e);
    imprimirExistencias(e);

        cout << "Introduce el vehiculo que quieres encontrar: ";
        cin >> vehiculo;

    detectarConcesionario(e, vehiculo);

    return 0;
}
