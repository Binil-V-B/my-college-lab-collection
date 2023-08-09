/*
    create varibles to store:
        no of process -np
        no of resources -nr
        available -a[] --used to store the available resource 
        work -work[] --used to store the no of available resources, it is copied from available
        max[][] -used to store the max no of resouces required by each process
        allocation[][] -used to store the no of resouces that are currently allocated to each process
        ss[] --used to store safe sequence
        finish[] --used to store status of each process completed/not completed
    algorithm:
        read the np,nr,
        read the allocation matrix
        read the max matrix
        read the no of available of each resource and copy the available matrix to work matrix
        set the finish[] of all process to 0
        calculate the need matrix

        start a loop which iterates through the processes -i
        start another loop which iterates throught the processes -j
            set flag =0
            check if finish[j]=0,
                check if each resource needed by the process is available
                    if not available set flag =1
                if flag=0 
                    add the allocated resource to the work matrix
                    add to the safe sequence
                    increment k
                    set finish to 1
                
            increment j
            increment i
        
        check if any process is left unfinished
            if unfinished print unsafe
            else print the safe sequence
*/

#include<stdio.h>
void main(){
    int np,nr,flag,k=0;
    printf("enter the no of processes: ");
    scanf("%d",&np);
    printf("enter the no of resources: ");
    scanf("%d",&nr);
    int available[nr],work[nr],ss[np],finish[np];
    int max[np][nr],allocation[np][nr],need[np][nr];

    printf("enter the allocation matrix: ");
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
        
    }

    printf("enter the max matrix: ");
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            scanf("%d",&max[i][j]);
        }
        
    }

    printf("enter the available resources: ");
    for (int i = 0; i < nr; i++)
    {
        scanf("%d",&available[i]);
        work[i]=available[i];
    }

    for (int i = 0; i < np; i++)
    {
        finish[i]=0;
    }
    
    printf("need matrix: \n");
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
            printf("%d \t",need[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < np; j++)
        {
            flag=0;
            if (finish[j]==0)
            {
                for (int a = 0; a < nr; a++)
                {
                    if(need[j][a]>work[a]){
                        flag=1;
                        break;
                    }
                }
                if (flag==0)
                {
                    for (int a = 0; a < nr; a++)
                    {
                        work[a]+=need[j][a];
                    }
                    finish[j]=1;
                    ss[k]=j;
                    k++;
                    
                }
                
                
            }
            
        }
        
    }
    
    // for (int i = 0; i < np; i++)
    // {
    //     printf("%d\t",finish[i]);
    // }
    // printf("\n");

    flag=0;
    for (int i = 0; i < np; i++)
    {
        if(finish[i]==0){
            flag=1;
            break;
        }
    }
    if (flag==1)
    {
        printf("system is not safe\n");
    }
    else{
        printf("system is safe\nsafe sequence: ");
        for (int i = 0; i < np; i++)
        {
            printf(" %d ",ss[i]);
            if (i<np-1)
            {
                printf("->");
            }
            
        }
        printf("\n");
        
    }   
}