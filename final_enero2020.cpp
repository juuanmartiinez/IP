#include <iostream>

using namespace std;

typedef int Producto[1][6];
typedef float Precio[1][6];
typedef int Tabla[5][6];

void imprimirTabla (Tabla &t){
    
    int i,j;

    for(i = 0 ; i < 5 ; i++){
        cout << " [";
        for(j = 0 ; j < 6 ; j++){
            cout << t[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

bool liquidado (Tabla &t , Producto &p){

    int i,j;

    for(i = 0 ; i < 5 ; i++){
        for(j = 0 ; j < 6 ; j++){
                
                if(t[i][j] == p[0][j]){
                return true;
                }  
        } 
    }
    return false;
}

float mejorDependiente (Tabla &t, Precio &p){

    int i,j;
    float precio;
    float suma;
    int max = -9999;
    int maxi = -1;

    for(i = 0 ; i < 5 ; i++){
        suma = 0;
        for(j = 0 ; j < 6 ; j++){
            precio = t[i][j] * p[0][j];
            suma += precio;
        }
        if(suma > max){
        max = suma;
        maxi = i;
        }else if(suma == max){
            maxi = i;
        }
        
    }
    cout << "El mejor dependiente sera el dependiente " << maxi + 1 << endl;
    return max;
}

int main (){

    Producto producto = {{40,60,35,80,50,25}};
    Precio precio = {{3.75,1.15,2.00,7.13,4.00,0.75}};
    Tabla tabla = {{12, 4, 0, 0, 4, 5},
                        {5, 12, 0, 0, 14, 1},
                        {6, 4, 35, 0, 24, 2},
                        {7, 3, 0, 36, 1, 7},
                        {2, 0, 0, 0, 6, 2} };

    imprimirTabla(tabla);
    mejorDependiente(tabla,precio);

    if(liquidado(tabla,producto)){
        cout << "Encontrado." << endl;
    }else{
        cout << "No encontrado." << endl;
    }

    return 0;

}
