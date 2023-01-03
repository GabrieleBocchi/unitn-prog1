#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);
void deallocaAlbero(albero a);

void StampaAlberoInOrdine(albero a);
albero creaAlberoDiRicercaBinario(albero a);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    StampaAlberoInOrdine(alberoBinario);

    
    cout << endl;

    deallocaAlbero(alberoIniziale);
    deallocaAlbero(alberoBinario);

    return 0;
}


albero generaAlbero(int numeroDiNodi) {
    
    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo* nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i<numeroDiNodi; i++) {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2*i + 1)<numeroDiNodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < numeroDiNodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }

    return nodi[0];
}

void stampaAlbero(albero radice, int spazio) {

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}


/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */

// SB: ok
void deallocaAlbero(albero a){
    deallocaAlbero(a->left);
    deallocaAlbero(a->right);
    delete a;
}

// SB: bisogna aggiungere la condizione "if (a != NULL)"
void StampaAlberoInOrdine(albero a){
    StampaAlberoInOrdine(a->left);
    cout<<a->value;
    StampaAlberoInOrdine(a->right);
}

// SB: commenti in linea
albero creaAlberoDiRicercaBinario(albero a){
    albero ris = NULL;
    if(a != NULL){
        if(a->value %2 == 0){
            // SB: dereferenziamento di un puntatore nullo
            ris->value = a->value;
            // SB: manca il passo ricorsivo
        }else{
            // SB: il valore di "ris" viene sempre sovrascritto
            ris = creaAlberoDiRicercaBinario(a->left);
            ris = creaAlberoDiRicercaBinario(a->right);
        }
    }
    return ris;
}
