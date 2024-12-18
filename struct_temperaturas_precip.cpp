#include <iostream>

using namespace std;

const int FILAS = 10;    // AÑOS Y DATOS POR AÑO


struct Clima
{   
    int precipitaciones;
    int temperaturas;
};

typedef Clima Tabla[FILAS];

void generarTabla (Tabla &t){

    int i;

    for(i = 0 ; i < FILAS ; i++){
        
            t[i].temperaturas = rand() % (25 + 20);
            t[i].precipitaciones = rand() % (0 + 100);
    }
}

void imprimirTabla (Tabla &t){

    int i;

    for(i = 0 ; i < FILAS ; i++){
        cout << i + 2015 << " |";
        
            cout << "PRECIPITACIONES: " << t[i].precipitaciones << " ";
            cout << "TEMPERATURAS: " << t[i].temperaturas << " ";
       
        cout << "|" << endl;
    }
}

bool noLlueve (Tabla &t, int Llueve){

    int i;
    
    for(i = 0 ; i < FILAS ; i++){
        if(t[i].precipitaciones == 0){
            Llueve = i;
            return true;
        }
    }
    return false;
}

int maxTemperatura (Tabla &t){

    int i;
    int maxTemp;
    int anoMaxTemp;
    maxTemp = -1;

    for(i = 0 ; i < FILAS ; i++){
        if(t[i].temperaturas > maxTemp){
            maxTemp = t[i].temperaturas;
            anoMaxTemp = i;
        }
    }
    return anoMaxTemp + 2015;
}

int maxPrecipitaciones (Tabla &t){

    int i;
    int maxPrep;
    int anoMaxPrep;
    maxPrep = -1;

    for(i = 0 ; i < FILAS ; i++){
        if(t[i].precipitaciones > maxPrep){
            maxPrep = t[i].precipitaciones;
            anoMaxPrep = i;
        }
    }
    return anoMaxPrep + 2015;
}

int main () {

    Tabla t;
    int Llueve;
	Llueve = 0;
    generarTabla(t);
    imprimirTabla(t);

    if(noLlueve(t,Llueve)){
        cout << "No llueve en el año " << Llueve + 2015 << endl;
    }else{
        cout << "Llueve en todos los años que estamos analizando." << endl;
    }

    cout << "El año más cálido será el " << maxTemperatura(t) << endl;
    cout << "El año con más precipitaciones será el " << maxPrecipitaciones(t) << endl;

    return 0;
}
