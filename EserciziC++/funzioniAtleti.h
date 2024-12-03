/*- stampare i tempi degli atleti;
- stampare il tempo medio degli atleti;
- stampare il tempo del vincitore;
- copiare in un altro array i tempi inferiori al valore medio e stampare il atleti;
- stampare il numero di atleti che hanno corso in un tempo inferiore ad un tempo passato come parametro;
*/
#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED 
#include <ctime> 
#include <iostream>
#include <fstream> 

using namespace std;

struct atleta{
    string nome;
    string cognome;
    int numerogara;
    char sesso;
    int eta;
    float tempo;
};
//funzione per stampare dati atleti su file
void stampaFile(atleta atleti [], int dim){
    ofstream file;
    file.open("dati.txt");
    for(int i=0; i<dim; i++){
        file<<atleti[i].cognome<<" "<<atleti[i].numerogara<<" "<<endl;
    }
    file.close();
}



//stampo i tempi degli atleti
void tempo_atleti(atleta atleti [], int dim){
    srand (time(NULL)); // srand Ã¨ una funzione che inizializza il generatore di numeri casuali
    int tempo;
    for(int i=0; i<dim;i++){
        tempo=rand()  % 400+200;//60 sono 6 ore
        atleti[i].tempo=tempo;
    }
}

void stampa_tempo(atleta atleti [], int dim){
    for(int i=0; i<dim; i++){
        cout<<"tempo atleta: "<<atleti[i].tempo<<" minuti"<<endl;
    }
}

//stampo il tempo medio degli atleti
float calcolaMedia(atleta atleti [], int dim){
    float somma=0;
    for(int i=0; i<dim; i++){
        somma=somma+atleti[i].tempo;
    }
    return somma/dim; //restituisce la media
}

float numeroMin(atleta atleti[], int dim){
    float min=atleti[0].tempo;
    for(int i=0; i<dim; i++){
        if(atleti[i].tempo<min){
            min=atleti[i].tempo;
        }
    }
    return min;
}

//copiare in un altro array i tempi inferiori al valore medio e stampare il atleti;
void sottoVettore(atleta atleti[], int dim){
    int cont=0;
    float media=calcolaMedia(atleti,dim);
    for(int i=0; i<dim; i++){
        if(atleti[i].tempo<media){
            cont++;
        }    
    }

    int sposta=0;
    atleta sottovettore[cont];
    for(int i=0; i<dim; i++){
        if(atleti[i].tempo<media){
            sottovettore[sposta].tempo=atleti[i].tempo;
            sposta++;
        }
    }

    stampa_tempo(sottovettore,cont);
}

//stampare il numero di atleti che hanno corso in un tempo inferiore ad un tempo passato come parametro;
int tempoInferiore(atleta atleti[], int dim, float tempo){
    int cont=0;
    for(int i=0; i<dim; i++){
        if(atleti[i].tempo<tempo){
            cont++;
        }
    }
    return cont;
}

void ordina_per_tempo(atleta atleti[], int n){
    /*bool scambio;
    atleta a;

    do{
        scambio=false;
        for(int i=0; i<n; i++){

            if(classifica[i].tempo>classifica[i+1].tempo){
                a=classifica[i];
                classifica[i]=classifica[i+1];
                classifica[i+1]=a;
                scambio=true;
            }
        }
    }while(scambio);*/
    atleta scambio;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(atleti[j].tempo>atleti[j+1].tempo){
                scambio=atleti[j];
                atleti[j]=atleti[j+1];
                atleti[j+1]=scambio;
            }
        }
    }
}

void stampa_atleti(atleta atleti[],int n){
    for (int i = 0; i < n; i++) {
        cout << "\nAtleta " << i+1 << ":" << endl;
        cout<<"Nome: "<<atleti[i].nome<<endl;
        cout<<"Cognome: "<<atleti[i].cognome<<endl;
        cout<<"Eta': "<<atleti[i].eta<<endl;
        cout<<"Numero concorrente: "<<atleti[i].numerogara<<endl;
        cout<<"Sesso: "<<atleti[i].sesso<<endl;
        cout<<"Tempo: "<<atleti[i].tempo<<endl;
    }
}

#endif //FUNZIONI_H_INCLUDED