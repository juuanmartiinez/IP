#include <iostream>

using namespace std;

const int ESTUDIANTES = 3;
const int MATERIAS = 4;

typedef int Clase[ESTUDIANTES][MATERIAS];

void generarNotas (Clase &c){

    int i,j;

    for(i = 0 ; i < ESTUDIANTES ; i++){
        for(j = 0 ; j < MATERIAS ; j++){
            c[i][j] = rand() % (1 + 10);
        }
    }
}

void imprimirClase (Clase &c){

    int i,j;
    cout << "NOTAS CLASE" << endl;
    for(i = 0 ; i < ESTUDIANTES ; i++){
        cout << "Estudiante " << i + 1 << " |";
        for(j = 0 ; j < MATERIAS ; j++){
            cout << c[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

void mejorMedia (Clase &c){

    int i,j;
    int suma;
    int mejorEstudiante;
    float media;
    float mediaMax;
    mediaMax = -999;

    for(i = 0 ; i < ESTUDIANTES ; i++){
        suma  = 0;
        for(j = 0 ; j < MATERIAS ; j++){
            suma += c[i][j];
        }
        media = suma / j;
        if(media > mediaMax){
            mediaMax = media;
            mejorEstudiante = i;
        }
    }
    cout << "El mejor estudiante será el estudiante " << mejorEstudiante + 1 << endl;
}

bool todoSuspendo (Clase &c){

    int i,j;

    for(i = 0 ; i < ESTUDIANTES ; i++){
        for(j = 0 ; j < MATERIAS ; j++){
            if(c[i][j] >= 5){
                return false;
            }
        }
    }
    return true;
}

void asignaturaMasSuspendida (Clase &c){

    int i,j;
    int contSuspensos;
    int maxSuspensos;
    int maxSuspendida;
    contSuspensos = 0;
    maxSuspensos = -999;
    
    for(j = 0 ; j < MATERIAS ; j++){
        contSuspensos = 0;
        for(i = 0 ; i < ESTUDIANTES ; i++){
            if(c[i][j] < 5){
                contSuspensos++;
            }
        }
        if(contSuspensos > maxSuspensos){
            maxSuspensos = contSuspensos;
            maxSuspendida = j;
        }
    }
    cout << "La asignatura mas suspendida ha sido la asignatura " << maxSuspendida + 1 << endl;
}

int main (){

    Clase c;
    int opcion;

    while(opcion != 5){
        
        cout << "CLASE." << endl;
        cout << "1. Mostrar notas de la clase." << endl;
        cout << "2. Cual es el mejor estudiante." << endl;
        cout << "3. Alguno lo tiene todo suspenso." << endl;
        cout << "4. Asignatura mas suspendida." << endl;
        cout << "5. Salir." << endl;
        cout << "INTRODUCE UNA OPCION: ";
        cin >> opcion;

        if(opcion == 1){
            generarNotas(c);
            imprimirClase(c);
        }else if(opcion == 2){
            mejorMedia(c);
        }else if(opcion == 3){
            if(todoSuspendo(c)){
                cout << "Si, hay un estudiante que ha suspendido todas." << endl;
            }else{
                cout << "No, no hay ningun estudiante que haya suspendido todas." << endl;
            }
        }else if(opcion == 4){
            asignaturaMasSuspendida(c);
        }
    }
    return 0;
}