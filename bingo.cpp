#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int Numeros = 15;
const int Bingo = 90;
typedef int BINGO[Bingo];
typedef int Carton[Numeros];

void generarNumeroBingo (BINGO &b){

    int i; 
    int num;
    bool generados[Bingo];
    generados[Bingo] = false;

    cout << "NUMEROS GENERADOS POR EL BINGO" << endl;

    while(i < Bingo){           //  HACE QUE NO SE REPITAN LOS NÚMEROS QUE GENERA.
        num = rand() % 90 + 1; 
        if(!generados[num -1]){
            b[i] = num;
            generados[num - 1] = true;
            cout << b[i] << " ";
            i++;
        }
    }
    cout << endl;
}

bool comprobarCarton (Carton &C,BINGO &b){

    int i,j;
    int cont;
    cont = 0;

    for(i = 0 ; i < Numeros ; i++){
        for(j = 0 ; j < Bingo ; j++){
            if(C[i] == b[j]){
                cont++;
                break;
            }
        }
    }
    return (cont == Numeros);
}

int main (){

    srand(time(0));

    BINGO b;
    Carton C1 = {1,4,7,10,15,33,38,45,49,58,60,66,74,79,88};
    Carton C2 = {3,6,9,13,17,34,37,42,46,48,55,58,62,78,82};

    generarNumeroBingo(b);

    if( comprobarCarton(C1,b)){
        cout << "GANA EL CARTON 1." << endl;
    }else if (comprobarCarton(C2,b)){
        cout << "GANA EL CARTON 2." << endl;
    }else{
        cout << "No gana ninguno de los dos." << endl;
    }

    return 0;

}
