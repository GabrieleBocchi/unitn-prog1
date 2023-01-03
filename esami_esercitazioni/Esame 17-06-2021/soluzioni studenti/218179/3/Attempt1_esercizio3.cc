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
albero creaAlberoDiRicercaBinario(albero radice);
void stampaAlberoInOrdine(albero radice=0);
void deallocaAlbero(albero radice);
void crea(albero nuovo, albero radice);
void assegna(albero radice, nodo* nuovo);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    stampaAlberoInOrdine(alberoBinario);
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

// SB: ok, ma la funzione inserisce nell'albero anche numeri pari
albero creaAlberoDiRicercaBinario(albero radice){

	albero nuovo = new nodo{radice->value, NULL, NULL};
	crea(nuovo, radice);
	return nuovo;

}

void crea(albero nuovo, albero radice){

	if(radice==NULL) return;
	
	else{
		nodo* n = new nodo{radice->value, NULL, NULL};
		assegna(nuovo, n);
		crea(nuovo, radice->left);
		crea(nuovo, radice->right);
	}	 

}

void assegna(albero radice, nodo* nuovo){

	if(nuovo->value < radice->value){
		if(radice->left == NULL) radice->left = nuovo;
		else assegna(radice->left, nuovo);
	}

	else{
		if(radice->right == NULL) radice->right = nuovo;
		else assegna(radice->right, nuovo);
	}

}

// SB: ok
void stampaAlberoInOrdine(albero radice){

	if(radice != NULL){
		stampaAlberoInOrdine(radice->right); 	
		cout << radice->value << " ";
		stampaAlberoInOrdine(radice->left);
	}

}

// SB: ok
void deallocaAlbero(albero radice){

	if(radice != NULL){
		deallocaAlbero(radice->left);
		deallocaAlbero(radice->right);
		delete radice;
	}

}















