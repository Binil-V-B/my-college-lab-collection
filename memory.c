#include<stdio.h>

struct memory{
    int size;
    int available;
};
struct task{
    int size;
    int memory_used;
    int balance;
};


void main(){
    int a,b;
    printf("enter the no of memory blocks: ");
    scanf("%d",&a);

    struct memory mem[a];

    printf("enter the size of each memory block: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d",&mem[i].size);
        mem[i].available=1;
    }
    printf("enter the no of tasks to execute: ");
    scanf("%d",&b);

    struct task ta[b];

    printf("enter the size of each tasks: ");
    for (int i = 0; i < b; i++)
    {
        scanf("%d",&ta[i].size);
    }
    

    //first fit
    for (int  i = 0; i < b; i++)
    {
        for (int  j = 0; j < a; j++)
        {
            if(ta[i].size<=mem[j].size && mem[j].available){
                ta[i].memory_used=mem[j].size;
                ta[i].balance=(mem[j].size)-(ta[i].size);
                mem[j].available=0;
                break;
            }
            else{
                ta[i].memory_used=-1;
            }
        }    
    }

    //best fit


    //worst fit

        

    //printing
    printf("\ntask\tmemory choosen\tbalance\n");
    for (int i = 0; i < b; i++)
    {
        if(ta[i].memory_used!=-1)
            printf("%d\t%d\t\t%d\n",ta[i].size,ta[i].memory_used,ta[i].balance);
        else    
            printf("%d\tnot allocated\n",ta[i].size);
    }

    
}
