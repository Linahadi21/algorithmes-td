#include <stdio.h>

int minIndex(int t[], int n) {
    int idx=0;
    for(int i=1;i<n;i++)
        if(t[i]<t[idx]) idx=i;
    return idx;
}

int puissance(int a,int n){
    if(n==0) return 1;
    return a*puissance(a,n-1);
}

int rec1(int n){
    if(n==0) return 1;
    return 2*rec1(n-1);
}

int main(){
    int t[]={5,2,4,1};
    printf("Min index=%d\n",minIndex(t,4));
}
