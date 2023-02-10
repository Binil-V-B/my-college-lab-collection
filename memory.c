#include<stdio.h>

struct process{
    int size;  // used to store the size of each process
    int allocated; // to check whether a process was allocated or not and also stores the block size to which the process was allocatted
};


void main(){
    int nb,np;
    printf("enter the no of memory blocks: ");
    scanf("%d",&nb);
    int block[nb];
    printf("enter the size of each memory blocks: ");
    for (int i = 0; i < nb; i++)
    {
        scanf("%d",&block[i]);
    }
    printf("enter the no of processes: ");
    scanf("%d",&np);
    struct process pro[np];
    for (int i = 0; i < np; i++)
    {
        scanf("%d",pro[i].size);
        pro[i].allocated=-1;
    }

    for (int  i = 0; i < np; i++)
    {
        for (int  j = 0; j < nb; j++)
        {
            if(pro[i].size<=block[j]){
                pro[i].allocated=block[j];
                block[j]=block[j]-pro[i].size;
                break;
            }
        }   
    }
    
    
    
    
}
