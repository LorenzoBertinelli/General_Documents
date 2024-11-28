#include <iostream>
#include <string>
#include <windows.h>
#include "funzioniAtleti.h"

using namespace std;

int main (){
    
    int scelta;
    int n;
    float tempo;
    int atleti_inseriti = 0;
    cout<<"quanti atleti partecipano alla maratona? ";
    cin>>n;
    atleta atleti[n];

    //menu
    do{
        cout<<"Scegli:\n1) Assegna i tempi;\n2) Calcola la media;\n3) Stampa i tempi degli atleti;\n4) Per sapere il tempo minore;\n5) Per vedere i numeri sotto la media;\n6) Per sapere quanti numeri sono inferiori al parametro inserito;\n7) Per inserire le informazioni dell'atleta;\n8) Stampa atleti; \n9) Per vedere la classifica; \n0) Per uscire;\nOperazione: ";
        cin>>scelta;

        switch(scelta){
            case 1:
                cout << "inserimento tempi atleti..." << endl;
                tempo_atleti(atleti,atleti_inseriti);
                stampaFile(atleti,atleti_inseriti);
                cout << "inserimento completato." << endl;
                break;
            case 2:
                cout<<"la media e': "<<calcolaMedia(atleti, atleti_inseriti)<<" minuti"<<endl;
                break;
            case 3:
                stampa_tempo(atleti, atleti_inseriti);
                break;
            case 4:
                cout<<"il tempo minore e': "<<numeroMin(atleti, atleti_inseriti)<<" minuti"<<endl;
                break;
            case 5:
                sottoVettore(atleti, atleti_inseriti);
                break;
            case 6:
                cout<<"inserisci un tempo: ";
                cin>>tempo;
                cout<< tempoInferiore(atleti, atleti_inseriti, tempo)<<endl;
                break;
            case 7:

                if (atleti_inseriti >= n){
                    cout << "Non e' possibile aggiungere ulteriori atleti. Numero massimo raggiunto.\n";
                    break;
                }

                cout<<"Inserisci il nome della persona: ";
                cin>>atleti[atleti_inseriti].nome;
                cout<<"Inserisci il cognome della persona: ";
                cin>>atleti[atleti_inseriti].cognome;
                cout<<"Inserisci il numero di gara della persona: ";
                cin>>atleti[atleti_inseriti].numerogara;
                cout<<"Inserisci l'eta' della persona: ";
                cin>>atleti[atleti_inseriti].eta;
                cout<<"Inserisci il sesso della persona (M o F): ";
                cin>>atleti[atleti_inseriti].sesso;

                atleti_inseriti++;

                break;
            case 8:
                stampa_atleti(atleti,atleti_inseriti);
                break;
            case 9:
                ordina_per_tempo(atleti,atleti_inseriti);
                stampa_atleti(atleti,atleti_inseriti);                
                break;
            default:
                cout<<"scelta non possibile"<<endl;
            
        }
        
        system("pause");//premi un tasto per continuare
        system("cls");//pulisce lo schermo

    } while(scelta!=0);//esce se si preme il tasto 0
    return 0;
}