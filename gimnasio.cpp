/*PROGRAMA QUE CALCULE EL AFORO DE UN GIMNASIO DURANTE LAS HORAS QUE ESTE ABIERTO, TENIENDO EN CUENTA CUANDO ALGUIEN ENTRA 0 SE VA.*/

#include <iostream>

using namespace std;

const int HORAS = 8; //HORAS EN LAS QUE EL GIMNASIO ABRE
const int AFORO = 20; // AFORO TOTAL QUE PUEDE TENER EL GIMNASIO EN UNA MISMA HORA.

typedef int Gimnasio[HORAS][AFORO];


void imprimirGimnasio (Gimnasio &g){

    int i,j;

    for(i = 0 ; i < HORAS ; i++){
        cout << "[ ";
        for(j = 0 ; j < AFORO ; j++){
            cout << g[i][j] << " ";
        }
        cout << "]"<< endl;
    }
}

void generarGimnasio (Gimnasio &g){

    int i,j;

    for(i = 0 ; i < HORAS ; i++){
        for(j = 0 ; j < AFORO ; j++){
            g[i][j] = rand() % (1 + 1);
        }
    }
}

void recuentoAforo (Gimnasio &g){

    int i,j;
    int contAforo;


    for(i = 0; i < HORAS ; i++){
        contAforo = 0;
        for(j = 0 ; j < AFORO ; j++){
            if(g[i][j] == 1){
                contAforo++;
                
            }
            if(g[i][j] == 0){
                contAforo--;
            }
        }
        if(contAforo < 0){
            cout << "Error en el conteo." << endl;
        }
        if(contAforo > 0){ 
            cout << "El aforo durante la hora " << i + 1 << " es de " << contAforo << endl;
        }
        if(contAforo == 0){
            cout << "El gimnasio esta vacio." << endl;
        }
    }
}

void mejorHora (Gimnasio &g){

    int i,j;
    int contAforo;
    int maxAforo = -9999;

    for(i = 0 ; i < HORAS ; i++){
        contAforo = 0;
        for(j = 0 ; j < AFORO ; j++){
            if(g[i][j] == 1){
                contAforo++;
                
            }
            if(g[i][j] == 0){
                contAforo--;
            }
            if(contAforo > maxAforo){
                maxAforo = contAforo;
            }
        }
    }
        cout << "El aforo maximo obtenido ha sido de " << maxAforo << " durante la hora " << i << endl;
}

int main () {

    Gimnasio g;

    generarGimnasio(g);
    imprimirGimnasio(g);
    recuentoAforo(g);
    mejorHora(g);

    return 0;
}