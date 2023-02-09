#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
}*root=NULL,*newnode,*ptr,*pre;




void inorder(struct tree* a){
    if(a==NULL)
        return;
    inorder(a->left);
    printf("%d\t",a->data);
    inorder(a->right);
}
void preoder(struct tree* a){
    if(a==NULL)
        return;
    printf("%d\t",a->data);
    preoder(a->left);
    preoder(a->right);
}
void postorder(struct tree* a){
    if(a==NULL)
        return;
    postorder(a->left);
    postorder(a->right);
    printf("%d\t",a->data);
}


void main(){
    int c;
    
    do{
        printf("\n1.Insert a node\n2.delete a node\nprint:\n3.inorder\n4.preorder\n5.postorder\n-->  ");
        scanf("%d",&c);
        switch (c)
        {
        case 1: insert();
            break;
        case 2: 
            break;
        case 3: inorder(root);
            break;
        case 4: preoder(root);
            break;
        case 5: postorder(root);
            break;
        
        default:printf("invalid input");
        }
    }while(1);
}