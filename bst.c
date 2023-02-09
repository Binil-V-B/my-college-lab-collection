#include<stdio.h>
#include<stdlib.h>

void insert();
struct tree* createnode (int);
void inorder(struct tree*);
void preoder(struct tree*);
void postorder(struct tree*);

struct tree{
    int data;
    struct tree *left,*right;
}*root=NULL,*newnode,*ptr,*pre;


void insert(){
    int a;
    printf("enter the value to insert: ");
    scanf("%d",&a);
    newnode=create_node(a);
    if(root==NULL){
        root=newnode;
    }
    else{
         
    }

}

struct tree* search(int value){
    ptr=root;
    if(root==NULL)
        return NULL;
    while (ptr!=NULL)
    {
        if(value<ptr->data)
            ptr=ptr->left;
        else if(value>ptr->data)
            ptr=ptr->right;
        else
    }
    
}


struct tree* create_node (int value){
    newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}


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