/*CALCULADOR DE MATRICES 3X3*/

#include <iostream>

using namespace std;

const int FILAS = 3;
const int COLUMNAS = 3;

typedef int Matriz[FILAS][COLUMNAS];
typedef int Producto[FILAS][COLUMNAS];
typedef int Suma[FILAS][COLUMNAS];

void LeerMatriz1 (Matriz &m1, int &filas, int &columnas){

    int i,j;
    cout << "LEEMOS LA PRIMERA MATRIZ." << endl;
    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            cout << "Dame el elemento [" << i << "," << j << "] : ";
            cin >> m1[i][j];
        }
    }
}

void LeerMatriz2 (Matriz &m2, int &filas, int &columnas){

    int i,j;
    cout << "LEEMOS LA SEGUNDA MATRIZ." << endl;
    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            cout << "Dame el elemento [" << i << "," << j << "] : ";
            cin >> m2[i][j];
        }
    }
}

void imprimirMatriz1(Matriz &m1, int &filas, int& columnas){

    int i,j;
    cout << "MATRIZ 1." << endl;
    for(i = 0 ; i < filas ; i++){
        cout << "[ ";
        for(j = 0 ; j < columnas ; j++){
            cout << m1[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void imprimirMatriz2(Matriz &m2,int &filas, int &columnas){

    int i,j;
    cout << "MATRIZ 2." << endl;
    for(i = 0 ; i < filas ; i++){
        cout << "[ ";
        for(j = 0 ; j < columnas ; j++){
            cout << m2[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void productoMatrices2X2 (Matriz &m1, Matriz &m2,Producto &p,int &filas, int &columnas){

    p[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]);
    p[0][1] = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]);
    p[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]);
    p[1][1] = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]);

    
}

void productoMatrices3X3 (Matriz &m1, Matriz &m2,Producto &p,int &filas, int &columnas){

    p[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
    p[0][1] = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]);
    p[0][2] = (m1[0][0] * m2[2][0]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]);
    p[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
    p[1][1] = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]);
    p[1][2] = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]);
    p[2][0] = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
    p[2][1] = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]);
    p[2][2] = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]);

}

void sumaMatrices (Matriz &m1, Matriz &m2,Suma &s, int &filas, int &columnas){

    int i,j;

    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            s[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void imprimirSuma (Suma &s,int &filas, int &columnas){

    int i,j;
    cout << "RESULTADO" << endl;
    for(i = 0 ; i < filas ; i++){
        cout << "[ ";
        for(j = 0 ; j < columnas ; j++){
            cout << s[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void imprimirProducto (Producto &p, int &filas, int &columnas){

    int i,j;
    cout << "RESULTADO" << endl;
    for(i = 0 ; i < filas ; i++){
        cout << "[ ";
        for(j = 0 ; j  < columnas ; j++){
        cout << p[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main(){

    Matriz m1;
    Matriz m2;
    Producto p;
    Suma s;
    
    int filas,columnas;
    int TipoOperacion;

    cout << "Que tipo de operación quieres realizar (1 : SUMA ; 2 = PRODUCTO): ";
    cin >> TipoOperacion;

    cout << "Introduce el nº de filas: ";
    cin >> filas;
    cout << "Introduce el nº de columnas: ";
    cin >> columnas;

    
    
    if(TipoOperacion == 2){
        if((filas == 2 && columnas == 2) || (filas == 3 && columnas == 3)){
        
            LeerMatriz1(m1,filas,columnas);
            LeerMatriz2(m2,filas,columnas);
            imprimirMatriz1(m1,filas,columnas);
            imprimirMatriz2(m2,filas,columnas);

            if((filas == 3) && (columnas == 3)){
            productoMatrices3X3(m1,m2,p,filas,columnas);
            imprimirProducto(p,filas,columnas);
            }else if((filas == 2) && (columnas == 2)){
            productoMatrices2X2(m1,m2,p,filas,columnas);
            imprimirProducto(p,filas,columnas);
            }

        }else{
        cout << "MATRIZ NO VÁLIDA." << endl;
        }
    }else if(TipoOperacion == 1){

            LeerMatriz1(m1,filas,columnas);
            LeerMatriz2(m2,filas,columnas);
            imprimirMatriz1(m1,filas,columnas);
            imprimirMatriz2(m2,filas,columnas);
            sumaMatrices(m1,m2,s,filas,columnas);
            imprimirSuma(s,filas,columnas);
    }else{
        cout << "OPERACIÓN NO VÁLIDA." << endl;
    }
    
    
    
    return 0;
}

