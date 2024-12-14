#include <iostream>

using namespace std;

const int DIAS = 31;
const int ANOS = 10;

typedef float LluviaMurcia[ANOS][DIAS];

void generarLluviaMurcia (LluviaMurcia &l){

    int i,j;

    for(i = 0 ; i < ANOS ; i++){
        for(j = 0 ; j < DIAS ; j++){
            l[i][j] = rand() % (0 + 100);
        }
    }
}

void imprimirLuviaMurcia (LluviaMurcia &l){

    int i,j;

    for(i = 0 ; i < ANOS ; i ++){
        cout << i + 2016 << " [ ";
        for(j = 0 ; j < DIAS ; j++){
            if(l[i][j] < 10){
                cout << "0";
            }
            cout << l[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void DiaMasLluvia (LluviaMurcia &l, int &ano, int &dia){

    int i,j;
    int maxLluvia;
    dia = 0;
    ano = 0;
    maxLluvia = -999;

    for(i = 0 ; i < ANOS ; i++){
        for(j = 0 ; j  < DIAS ; j++){
            if(l[i][j] > maxLluvia){
                maxLluvia = l[i][j];
                dia = j;
                ano = i;
            }
        }
    }
}

bool llover (LluviaMurcia &l, int &ano){

    int i,j;

    for(i = 0; i < ANOS ; i++){
        for(j = 0; j < DIAS; j++){
            if(l[i][j] != 0){
                return false;
            }else{
                return true;
            }
        }

    }
    return false;
}

int AnoMasLluvioso (LluviaMurcia &l,int &anoMaxLluvia){

    int i,j;
    int sumaLluvia;
    int MaxLluvia;
    anoMaxLluvia = 0;
    MaxLluvia = -9999;
    for(i = 0; i < ANOS ; i++){
        sumaLluvia = 0;
        for(j = 0 ; j < DIAS ; j++){
            sumaLluvia += l[i][j];
        }
        if(sumaLluvia > MaxLluvia){
            MaxLluvia = sumaLluvia;
            anoMaxLluvia = i;
        }
        cout << i + 2016 << " : " << sumaLluvia << endl;
    }
    
    
    return anoMaxLluvia;
}

int main() {

    LluviaMurcia l;
    int ano,dia;
    int anoMaxLluvia;

    generarLluviaMurcia(l);
    imprimirLuviaMurcia(l);
    DiaMasLluvia(l,ano,dia);

    cout << "El dia mas lluvioso será el " << dia << " de enero del año " << ano + 2016 << endl;

    if(llover(l,ano)){
        cout << "Hay un año en el que no llueve ningun dia." << endl;
    }else{
        cout << "No hay ningun año en el que no llueva." << endl;
    }

    AnoMasLluvioso(l,anoMaxLluvia);

    cout << "El año mas lluvioso será el " << anoMaxLluvia + 2016;
}
