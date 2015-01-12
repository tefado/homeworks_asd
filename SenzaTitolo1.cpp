#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>  /* ora puoi usare le funzioni di allocazione dinamica della memoria */

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: il primo campo ha nome info ed è di tipo intero, il secondo campo ha nome sx (il puntatore al sottoalbero sinistro), il terzo campo ha nome dx (un puntatore al sottoalbero destro) */
typedef struct elem{
int info;
struct elem *sx;
struct elem *dx;
}nodo_albero;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_albero *albero;



/* scrivi qui eventuali funzioni di appoggio */

int search(albero a, int i){
if(a==NULL) return 0;
if(a-> info == i) return 1;
if(i< a->info) return search(a->sx , i);
     else return search(a->dx , i);
}
int cammino(albero a, int i){
if(a==NULL) return 0;
if(a->info == i) return 1;
if(i<a->info) return 1+cammino(a->sx , i);
   else return 1+cammino(a->dx,i);
}

void copy(albero a,int p[], int i,int j){
if(a->info == i) p[j]=a->info;
else{
p[j]= a->info;
j++;
if(i<a->info)
     copy(a->sx,p,i,j);
else 
     copy(a->dx,p,i,j);
}
}

/* INIZIO FUNZIONE */

int* albero_cammino(albero T, int v){
    
    /* Si consideri un albero binario di ricerca T e un intero v (si ricorda che rispetto ad ogni nodo, il figlio sinistro avrà un valore minore rispetto al padre, il figlio destro avrà un valore maggiore rispetto al padre): allocare dinamicamente un array A di interi contenente i valori info dei nodi del cammino dalla radice di T alla foglia di T contenente il valore v. Alla fine restituire l'array A così costruito. Se l'albero T è vuoto, oppure non esiste una foglia in T contenente il valore v allora restituire NULL. Se l'albero T non presenta alcuna foglia contenente v, ma presenta un nodo intermedio con il valore v, la funzione deve restituire NULL */
    
if(T){
   if(search(T, v)){
      int *pp=(int*)malloc(sizeof(int)*cammino(T,v));
      copy(T,pp,v,0); 

      free(pp);
}else return NULL;
}else return NULL;

}
