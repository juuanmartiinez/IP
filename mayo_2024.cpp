
/*EJERCICIO DOS*/
/*LOS for(j) SE PODRIAN QUITAR, O ESO CREO*/

#include <iostream>

using namespace std;

const int COMUNIDADES = 19; // PARA CADA UNA DE LAS 19 CCAA.
const int FILA = 1; //SUPONEMOS QUE HAY 3 CANDIDATOS

struct Votaciones           // DEFINIMOS EL TIPO DE VOTACIONES POSIBLES
{
    int nulo;
    int abstencion;
    int blanco;
    int candidato1;
    int candidato2;
    int candidato3;
};


typedef Votaciones ResultadosElecciones[COMUNIDADES][FILA]; // DEFINIMOS LOS RESULTADOS

void generarResultados (ResultadosElecciones &r){    // GENERA UN NUMERO ALEATORIO PARA CADA OPCION DE VOTO

    int i,j;

    for(i = 0 ; i < COMUNIDADES ; i++){
        for(j = 0 ; j < FILA ; j++){
            r[i][j].nulo = rand() % (100 + 900);
            r[i][j].abstencion = rand() % (100 + 900);
            r[i][j].blanco = rand() % (100 + 900);
            r[i][j].candidato1 = rand() % (100 + 900);
            r[i][j].candidato2 = rand() % (100 + 900); 
            r[i][j].candidato3 = rand() % (100 + 900);
        }
    }
}

void imprimirResultados (ResultadosElecciones &r){   // IMPRIME LOS RESULTADOS DE LA ACCIÓN ANTERIOR POR PANTALLA

    int i,j;

    for(i = 0 ; i < COMUNIDADES ; i++){
        cout << "COMUNIDAD " << i + 1 << " |";
        for(j = 0 ; j < 1 ; j++){

            cout << "CANDIDATO 1: " << r[i][j].candidato1 << " ";
            cout << "CANDIDATO 2: " << r[i][j].candidato2 << " ";
            cout << "CANDIDATO 3: " << r[i][j].candidato3 << " ";
            cout << "NULO: " << r[i][j].nulo << " ";
            cout << "BLANCO: " << r[i][j].blanco << " ";
            cout << "ABSTENCIÓN: " << r[i][j].abstencion << " ";
        }
        cout << "|" << endl;
    }
}

bool hayGranAbstencion (ResultadosElecciones &r, int maxAbsComunidad ){     // ME DEVOLVERA TRUE SI EN UNA COMUNIDAD AUNTONOMA HAY MAS ABSTENCION QUE
                                                                            // VOTOS ENTRE LOS 3 CANDIDATOS.

    int i,j;
    int sumaCandidatos;

    for(i = 0 ; i < COMUNIDADES ; i++){
        sumaCandidatos = 0;                 // ACTUALIZO LA SUMA CADA COMUNIDAD QUE CALCULO PQ SI NO SE ACUMULA EN LA SUMA LAS DEMAS COMUNIDADES
        for(j = 0 ; j < FILA ; j++){
            sumaCandidatos = sumaCandidatos + r[i][j].candidato1 + 
                                r[i][j].candidato2 + r[i][j].candidato3;    
        }
        if(r[i][j].abstencion > sumaCandidatos){        // COMPRUEBO SI LA ABSTENCION ES MAYOR
            maxAbsComunidad = i;
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int candidaturaVencedora (ResultadosElecciones &r){   // CALCULO EL GANADOR DE LAS ELECCIONES

    int i,j;
    int sumaCandidato1, sumaCandidato2,sumaCandidato3;
    int candidatoVencedor;

    sumaCandidato1 = 0;
    sumaCandidato2 = 0;
    sumaCandidato3 = 0;  

    for(i = 0; i < COMUNIDADES ; i++){
        for(j = 0 ; j < FILA ; j++){
            sumaCandidato1 = sumaCandidato1 + r[i][j].candidato1;
            sumaCandidato2 = sumaCandidato2 + r[i][j].candidato2;
            sumaCandidato3 = sumaCandidato3 + r[i][j].candidato3;
        }
    }
        if(sumaCandidato1 > sumaCandidato2 && sumaCandidato2 > sumaCandidato3){
            candidatoVencedor = 1;
            cout << "El vencedor será el CANDIDATO 1, con " << sumaCandidato1 << " votos." << endl;
        }else if(sumaCandidato1 < sumaCandidato2 && sumaCandidato2 > sumaCandidato3){
            candidatoVencedor = 2;
            cout << "El vencedor será el CANDIDATO 2, con " << sumaCandidato2 << " votos." << endl;
        }else{
            candidatoVencedor = 3;
            cout << "El vencedor será el CANDIDATO 3, con " << sumaCandidato3 << " votos." << endl;
        }
    return candidatoVencedor;
}

int main (){

    ResultadosElecciones r;

    int maxAbsComunidad;
    
    maxAbsComunidad = 0;

    generarResultados(r);
    imprimirResultados(r);

    if(hayGranAbstencion(r,maxAbsComunidad)){
        cout << "Hay una comunidad en la que hay mas abstenciones que votos a candidatos: " << maxAbsComunidad + 1;
    }else{
        cout << "No hay ninguna comunidad en la que las abstenicones sean mayores que los votos a candidatos." << endl;
    }

    candidaturaVencedora(r);
    return 0;
}