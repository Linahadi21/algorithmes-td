#include <stdio.h>

/* Min index */
int minIndex(int t[], int n){
    int idx=0;
    for(int i=1;i<n;i++)
        if(t[i]<t[idx]) idx=i;
    return idx;
}

/* MiniMax */
int minimax(int tab[3][3]){
    int minimax;

    for(int i=0;i<3;i++){
        int max=tab[i][0];
        for(int j=1;j<3;j++)
            if(tab[i][j]>max) max=tab[i][j];

        if(i==0 || max<minimax)
            minimax=max;
    }
    return minimax;
}

/* Puissance simple */
int puissance(int a,int n){
    if(n==0) return 1;
    return a*puissance(a,n-1);
}

/* Exponentiation rapide */
int expRapide(int a,int n){
    if(n==0) return 1;
    if(n%2==0){
        int x=expRapide(a,n/2);
        return x*x;
    }
    return a*expRapide(a,n-1);
}

/* Somme */
int somme(int a,int n){
    if(n==0) return 1;
    return puissance(a,n)+somme(a,n-1);
}

/* Fonctions rec */
int rec1(int n){
    if(n==0) return 1;
    return 2*rec1(n-1);
}

int rec2(int n){
    if(n==0) return 1;
    return rec2(n-1)+rec2(n-1);
}

/* MAIN */
int main(){
    int t[]={5,2,4,1};
    printf("Index min=%d\n",minIndex(t,4));

    int m[3][3]={{2,3,4},{5,6,7},{8,9,1}};
    printf("MiniMax=%d\n",minimax(m));

    printf("2^5=%d\n",puissance(2,5));
    printf("Rapide 2^5=%d\n",expRapide(2,5));

    printf("rec1(4)=%d\n",rec1(4));
    printf("rec2(4)=%d\n",rec2(4));

    return 0;
}
