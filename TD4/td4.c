#include <stdio.h>
#include <stdlib.h>

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

void inorder(Node*r){
    if(r){
        inorder(r->left);
        printf("%d ",r->val);
        inorder(r->right);
    }
}

int main(){
    Node*r=NULL;
    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,8);

    inorder(r);
}
