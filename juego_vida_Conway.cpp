#include <iostream>

using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;

typedef int Cuadricula[FILAS][COLUMNAS];

void generarCuadricula (Cuadricula &c){

    int i,j;

    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ; j++){
            c[i][j] = rand() % (1 + 1);
        }
    }
}

void imprimirCuadricula (Cuadricula &c){

    int i,j;

    for(i = 0 ; i < FILAS ; i++){
        cout << "[";
        for(j = 0 ; j < COLUMNAS ; j++){
            cout << c[i][j] << " "; 
        }
        cout << "]" << endl;
    }
}

int contarVecinasVivas (Cuadricula &c, int x, int y){

    int i,j;
    int cont;
    cont = 0;

    for(i = -1 ; i <= 1 ; i++){
        for(j = -1 ; j <= 1 ; j++){
            if(c[i][j] == 0) continue;
            int fila = x + i;
            int columna = y + j;
            if(fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS){
                cont += c[fila][columna];
            }
        }
    }
    return cont;
}

void actualizarCuadricula (Cuadricula &c){

    int i,j;

    int nuevaCuadricula[FILAS][COLUMNAS] = {0};

    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ; j++){
            int vecinasVivas;
            vecinasVivas = contarVecinasVivas(c,i,j);

            if(c[i][j] == 1){
                if(vecinasVivas == 2 || vecinasVivas == 3){
                    nuevaCuadricula[i][j] = 1;
                }else{
                    nuevaCuadricula[i][j] = 0;
                }
            }else{
                if(vecinasVivas == 3){
                    nuevaCuadricula[i][j] = 1;
                }
            }
        }
    }

    for(i = 0 ; i < FILAS ; i++){
        for(j = 0 ; j < COLUMNAS ;j++){
            c[i][j] = nuevaCuadricula[i][j];
        }
    }
}

int main(){

    Cuadricula c;

    cout << "GENERACIÓN 0." << endl;
    generarCuadricula(c);
    imprimirCuadricula(c);

    int generaciones;
    int g;

    cout << "Cuantas generaciones quieres obtener: ";
    cin >> generaciones;

    for(g = 1 ; g < generaciones ; g++){
        actualizarCuadricula(c);
        cout << "Generacion" << g << ": " << endl;
        imprimirCuadricula(c);
    }

    return 0;
}
