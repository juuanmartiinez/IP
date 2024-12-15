#include <iostream>

using namespace std;

typedef int Matriz[10][10];
typedef int Producto[10][10];

void leerMatriz1 (Matriz &m1, int &filasA, int &columnasA){

    int i,j;
    cout << "LEEMOS MATRIZ 1" << endl;
    for(i = 0 ; i < filasA ; i++){
        for(j = 0 ; j < columnasA ; j++){
            cout << "Dame el elemento [" << i << "," << j << "]: ";
            cin >> m1[i][j];
        }
    }
}

void leerMatriz2 (Matriz &m2, int &filasB, int &columnasB){

    int i,j;
    cout << "LEEMOS MATRIZ 2" << endl;
    for(i = 0 ; i < filasB ; i++){
        for(j = 0 ; j < columnasB ; j++){
            cout << "Dame el elemento [" << i << "," << j << "]: ";
            cin >> m2[i][j];
        }
    }
}

void imprimirMatriz1 (Matriz &m1, int &filasA, int &columnasA){

    int i,j;
    cout << "MATRIZ 1" << endl;;
    for(i = 0; i < filasA ; i++){
        cout << " [";
        for(j = 0 ; j < columnasA ; j++){
            cout << m1[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void imprimirMatriz2 (Matriz &m2, int &filasB, int &columnasB){

    int i,j;
    cout << "MATRIZ 2" << endl;
    for(i = 0; i < filasB ; i++){
        cout << " [";
        for(j = 0 ; j < columnasB ; j++){
            cout << m2[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void productoMatrices (Matriz &m1, Matriz &m2, Producto &p, int &filasA, int &columnasA, int &filasB, int &columnasB){

    int i,j,k;

    for(i = 0 ; i < filasA ; i++){
        for(j = 0 ; j < columnasB; j++){
            for(k = 0 ; k < columnasA ; k++){
                p[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void imprimirResultado (Producto &p, int &filasA, int &columnasB){

    int i,j;
    cout << "RESULTADO" << endl;
    for(i = 0; i < filasA ; i++){
        cout << " [";
        for(j = 0 ; j < columnasB ; j++){
            cout << p[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main (){

    Matriz m1;
    Matriz m2;
    Producto p;

    int filasA, filasB;
    int columnasA,columnasB;

    cout << "Introduce las filas de la MATRIZ 1: ";
    cin >> filasA;
    cout << "Introduce las columnas de la MATRIZ 1: ";
    cin >> columnasA;

    cout << "Introduce las filas de la MATRIZ 2: ";
    cin >> filasB;
    cout << "Introduce las columnas de la MATRIZ 2: ";
    cin >> columnasB;

    if(columnasA == filasB){
        leerMatriz1(m1,filasA,columnasA);
        leerMatriz2(m2,filasB,columnasB);

        imprimirMatriz1(m1,filasA,columnasA);
        imprimirMatriz2(m2,filasB,columnasB);

        productoMatrices(m1,m2,p,filasA,filasB,columnasA,columnasB);
        imprimirResultado(p,filasA,columnasB);
    }else{
        cout << "LA MATRIZ NO SE PUEDE CALCULAR." << endl;
    }

    return 0;
}
