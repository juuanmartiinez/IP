/*UN HOSPITAL, REALIZAR UN ALGORITMO QUE ME DIGA EL NUMERO DE HABITACIONES LIBRES Y SUS POSICIONES*/

#include <iostream>
#include <fstream>

using namespace std;

const int  N_HAB = 5;
const int N_PISOS = 3;

typedef int Hospital[N_PISOS][N_HAB];

/*void cargarFichero (Hospital &h,string nombre){

    ifstream f;

    int i,j;

    f.open(nombre);

    if(!f){
        cout << "Error de apertura.";
    }else{
        for(i = 0; i < N_PISOS ; i++){
            for(j = 0; j < N_HAB ; j++){
               f >> h[i][j];
            }
        }
    }

}
*/

void imprimirHospital (Hospital &h){

    int i,j;

    for(i = 0; i < N_PISOS ; i++){
        cout << " [ ";
        for(j = 0; j < N_HAB ; j++){
            cout << h[i][j] << " ";
        }
        cout << "]" << endl;
    }

}

void generadorHospital (Hospital &h){

    int i,j;

    for(i = 0 ; i < N_PISOS ; i++){       
        for(j = 0 ; j < N_HAB ; j++){
             h[i][j] = rand() % (0 + 2);
        }
    }
}

void identificador (Hospital &h){

    int i,j;
    int contx,conty;
    contx = 0;
    conty = 0;

    for(i = 0 ; i < N_PISOS ; i++){
        for(j = 0 ; j < N_HAB ; j++){
            if(h[i][j] == 0){
                cout << "La habitacion [" << i + 1 << "|" << j + 1 << "] esta libre." << endl;
                contx++;
            }else{
                cout << "La habitacion [" << i + 1 << "|" << j + 1 << "] esta ocupada." << endl;
                conty++;
            }
        }
        
    }
		cout << "El numero de habitaciones ocupadas sera de " << conty << " habitaciones." << endl;
        cout << "El numero de habitaciones sin ocupar sera de " << contx << " habitaciones." << endl;
}

int main (){

    Hospital h;
    
    generadorHospital(h);
    imprimirHospital(h);
    identificador(h);

    return 0;
}
