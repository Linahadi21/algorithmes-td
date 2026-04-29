#include <stdio.h>
#include <stdlib.h>

/* ===== ARBRE ===== */
typedef struct node{
    int val;
    struct node*left,*right;
}Node;

Node* insert(Node*r,int v){
    if(!r){
        Node*n=malloc(sizeof(Node));
        n->val=v;
        n->left=n->right=NULL;
        return n;
    }
    if(v<r->val) r->left=insert(r->left,v);
    else r->right=insert(r->right,v);
    return r;
}

int search(Node*r,int v){
    if(!r) return 0;
    if(r->val==v) return 1;
    if(v<r->val) return search(r->left,v);
    return search(r->right,v);
}

void inorder(Node*r){
    if(r){
        inorder(r->left);
        printf("%d ",r->val);
        inorder(r->right);
    }
}

int count(Node*r,int v){
    if(!r) return 0;
    return (r->val==v)+count(r->left,v)+count(r->right,v);
}

int min(Node*r){
    while(r->left) r=r->left;
    return r->val;
}

/* MAIN */
int main(){
    Node*r=NULL;

    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,8);
    r=insert(r,2);

    printf("Infixe: ");
    inorder(r);

    printf("\nRecherche 2: %d\n",search(r,2));
    printf("Occurrences de 2: %d\n",count(r,2));
    printf("Min: %d\n",min(r));

    return 0;
}
