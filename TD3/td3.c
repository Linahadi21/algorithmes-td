#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

void insert(Node**L,int v){
    Node*n=malloc(sizeof(Node));
    n->val=v;
    n->next=*L;
    *L=n;
}

void display(Node*L){
    while(L){
        printf("%d -> ",L->val);
        L=L->next;
    }
    printf("NULL\n");
}

int main(){
    Node*L=NULL;
    insert(&L,5);
    insert(&L,2);
    insert(&L,8);
    display(L);
}
