#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== LISTE ===== */
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

int search(Node*L,int v){
    while(L){
        if(L->val==v) return 1;
        L=L->next;
    }
    return 0;
}

void destroy(Node**L){
    Node*tmp;
    while(*L){
        tmp=*L;
        *L=(*L)->next;
        free(tmp);
    }
}

/* ===== PILE ===== */
typedef struct stack{
    int val;
    struct stack*next;
}Stack;

void push(Stack**s,int v){
    Stack*n=malloc(sizeof(Stack));
    n->val=v;
    n->next=*s;
    *s=n;
}

int pop(Stack**s){
    Stack*tmp=*s;
    int v=tmp->val;
    *s=tmp->next;
    free(tmp);
    return v;
}

/* ===== FILE ===== */
typedef struct q{
    char val;
    struct q*next;
}Q;

typedef struct{
    Q*first,*last;
}Queue;

void enqueue(Queue*q,char v){
    Q*n=malloc(sizeof(Q));
    n->val=v;
    n->next=NULL;

    if(!q->first)
        q->first=q->last=n;
    else{
        q->last->next=n;
        q->last=n;
    }
}

char dequeue(Queue*q){
    Q*tmp=q->first;
    char v=tmp->val;
    q->first=tmp->next;
    free(tmp);
    return v;
}

/* ===== PALINDROME ===== */
int palindrome(char str[]){
    Queue q={NULL,NULL};
    Stack*s=NULL;
    int n=strlen(str);

    for(int i=0;i<n;i++)
        enqueue(&q,str[i]);

    for(int i=0;i<n/2;i++){
        char c=dequeue(&q);
        push(&s,c);
    }

    if(n%2) dequeue(&q);

    for(int i=0;i<n/2;i++)
        if(dequeue(&q)!=pop(&s))
            return 0;

    return 1;
}

/* MAIN */
int main(){
    Node*L=NULL;

    insert(&L,5);
    insert(&L,2);
    insert(&L,8);

    display(L);
    printf("Recherche 2: %d\n",search(L,2));

    char s[]="radar";
    printf("Palindrome: %d\n",palindrome(s));

    destroy(&L);
    return 0;
}
