#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
}*root=NULL,*newnode,*ptr,*pre;


void insert(){
    int a;
    printf("Enter the value to insert: ");
    scanf("%d",&a);

    newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=a;
    newnode->left=newnode->right=NULL;    

    if (root==NULL)
    {
        root=newnode;
    }
    else{
        ptr=root;
        while (ptr!=NULL)
        {
            pre=ptr;
            if (a>ptr->data)
            {
                ptr=ptr->right;
            }
            else{
                ptr=ptr->left;
            }   
        }
        if(a>pre->data)
            pre->right=newnode;
        else
            pre->left=newnode;        
    }
    
}

void delete(){

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
        printf("\n1.Insert\n2.print\n-->  ");
        scanf("%d",&c);
        switch (c)
        {
        case 1: insert();
            break;
        case 2: inorder(root);
            break;
        
        default:printf("invalid input");
        }
    }while(1);
}