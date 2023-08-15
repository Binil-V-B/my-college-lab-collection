#include<stdio.h>

struct process{
    int pid,at,bt,wt,tat,ct;
};

void read(int n,struct process ar[]){
    printf("enter the details of the processes: \n");
    for (int i = 0; i < n; i++)
    {
        printf(" ..[ %d ].. \n",i+1);
        printf("ente the pid of the process: ");
        scanf("%d",&ar[i].pid);
        printf("enter the arrival time: ");
        scanf("%d",&ar[i].at);
        printf("enter the burst time: ");
        scanf("%d",&ar[i].bt);
    }
    
}


void sort(int n, struct process ar[]){
    struct process Temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (ar[j].at>ar[j+1].at)
            {
                Temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=Temp;
            }
            
        }
        
    }
    
}

void print(int n, struct process ar[]){
    printf("---------------------------------------\npid\tat\tbt\tct\twt\ttat\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt,ar[i].ct,ar[i].wt,ar[i].tat);
    }
}

void work1(int n,struct process ar[]){
    int a;
    ar[0].ct=ar[0].bt;
    ar[0].tat=ar[0].ct-ar[0].at;
    ar[0].wt=ar[0].tat-ar[0].bt;
    for (int i = 1; i < n; i++)
    {
        if (ar[i].at<=ar[i-1].ct)
        {
            ar[i].ct=ar[i].bt+ar[i-1].ct;
        }
        else{
            a=ar[i].at-ar[i-1].ct;
            ar[i].ct=ar[i].bt+ar[i-1].ct+a;
        }
        ar[i].tat=ar[i].ct-ar[i].at;
        ar[i].wt=ar[i].tat-ar[i].bt;
    }
    
}

void main(){
    int n;
    printf("enter the no of processes: ");
    scanf("%d",&n);
    struct process ar[n];
    read(n,ar);
    sort(n,ar);
    work1(n,ar);
    print(n,ar);
    
}