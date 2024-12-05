/*5. (0.5 p) Realice un algoritmo principal, que haga uso de los apartados anteriores y muestre la informaciÛn
calculada por cada uno de ellos.*/

#include <iostream>

using namespace std;

const int DIAS_AGOSTO = 31;
const int N_ANOS = 10;

typedef float Temperaturas[N_ANOS][DIAS_AGOSTO];

void diaMasCaluroso(Temperaturas t, int &ano, int &dia){

    int i,j;
    int tempmax;
    ano = 0;
    dia = 0;
    tempmax = -9999;

    for(i = 0;i<=N_ANOS;i++){
        for(j=0;j<=DIAS_AGOSTO;j++){
            if (t[i][j] > tempmax){
                t[i][j] = tempmax;
                ano = i;
                dia = j;
            }
        }
        cout << "El dia mas caluroso será el " << dia << " de agosto de " << ano << endl;
    }
}

bool superar40grados (Temperaturas t){
    for(int i = 0; i < N_ANOS;i++){
        for(int j = 0; j < DIAS_AGOSTO ; j++){
            if(t[i][j] > 40.0){
                return true;
            }
        }
    }
    return false;
}

bool olaDeCalor (Temperaturas t, int ano){
    int j;
    int diasCalidos;

    diasCalidos = 0;
    j = 0;

    while((j < DIAS_AGOSTO - 1) && !(diasCalidos == 3 && t[ano][j] > 37 )){
        if(t[ano][j] > 37){
            diasCalidos++;
        }else{
            diasCalidos = 0;
        }
        j++;
    }
    
}

void generarTabla (Temperaturas &t){
    
    int i,j;

    for(i = 0 ; i < N_ANOS ; i++){
        for(j = 0 ; j < DIAS_AGOSTO ; j++){
            t[i][j] = rand() % 20 + 25;
        }
    }
}

int main (){

    Temperaturas tempsMurcia;
    int a,d;

    generarTabla(tempsMurcia);
    diaMasCaluroso (tempsMurcia, a, d);
    
    cout << "El día más cálido es el " << d << " de agosto del año " << a << endl;
    cout << "(año del índice a, vamos)" << endl;

    if(superar40grados(tempsMurcia)){
        cout << "Hay un dia que supera los 40º."<< endl;
    }else{
        cout << "No hay ningun dia que supere los 40º." << endl;
    }

    cout << "Dime un valor entre 0 y " << N_ANOS << ": ";
    cin >> a;

    if(olaDeCalor(tempsMurcia,a)){
        cout << "Murcia sufre una ola de calor." << endl;
    }else{
        cout << "Murcia no sufre una ola de calor." << endl;
    }

    return 0;

}

