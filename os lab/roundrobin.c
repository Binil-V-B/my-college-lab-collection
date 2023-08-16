#include<stdio.h>

struct process{
    int at,bt,ct,tat,wt,bt1,flag,pid;
};
typedef struct process pro;


void read(pro ar[],int n){
    printf("\nenter the details of the processes: \n");
    for (int i = 0; i < n; i++)
    {
    printf("enter the process id: ");
    scanf("%d",&ar[i].pid);
	printf("arrival time of process no %d:",i+1);
	scanf("%d",&ar[i].at);
    printf("burst time of process no %d:",i+1);
    scanf("%d",&ar[i].bt);
    ar[i].bt1 = ar[i].bt;
    ar[i].flag=0;
    printf("\n");
    }
}

void sort(pro ar[], int n){          //selection sort is implemented here
    int small;
    pro temp;
    for (int i = 0; i < n-1; i++)
    {
        small =i;
        for (int j = i; j < n ; j++)
        {
            if (ar[j].at < ar[small].at)
            {
                small = j;
            }    
        }
        if (small != i)
        {
            temp = ar[i];
            ar[i]=ar[small];
            ar[small] = temp;
        }  
    }    
}

int work(pro ar[],int n,int ts,int rq[]){
    int k;
    rq[0]=0;
    if (ar[0].bt<=ts)
    {
        ar[0].ct=ar[0].at+ar[0].bt;
        ar[0].bt1=0;
    }
    else{
        ar[0].ct=ar[0].at+ts;
        ar[0].bt1=ar[0].bt1-ts;
    }
    ar[0].flag=1;
    k=1;

    for (int i = 1; i < n; i++)      //loop to add new process to the ready queue
    {
        if (ar[i].at<=ar[0].ct && ar[i].flag==0)
        {
            rq[k++]=i;
            ar[i].flag=1;
        }
    }
    if (ar[0].bt1>0)
    {
        rq[k++]=0;
    }


    for (int j = 1; j < k; j++)
    {
        if (ar[rq[j]].bt1 <= ts)
        {
            ar[rq[j]].ct=ar[rq[j-1]].ct+ar[rq[j]].bt1;
            ar[rq[j]].bt1=0;
        }
        else{
            ar[rq[j]].bt1=ar[rq[j]].bt1-ts;
            ar[rq[j]].ct=ar[rq[j-1]].ct+ts;
        }

        for (int i = 0; i < n; i++)
        {
            if (ar[i].at<=ar[rq[j]].ct && ar[i].flag==0)
            {
                rq[k++]=i;
                ar[i].flag=1;
            }
        }

        if (ar[rq[j]].bt1>0)
        {
            rq[k++]=rq[j];
        }
    }
    return k;
}

void calc(pro ar[], int n,float *tat,float *wt){
    float avg_tat=0,avg_wt=0;
    for (int i = 0; i < n; i++)
    {
        ar[i].tat=ar[i].ct-ar[i].at;
        ar[i].wt = ar[i].tat-ar[i].bt;
        avg_tat+=ar[i].tat;
        avg_wt+=ar[i].wt;
    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    *tat = avg_tat;
    *wt = avg_wt;
}

void print(pro ar[],int n){
    printf("process\tat\tbt\tct\ttat\twt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt,ar[i].ct,ar[i].tat,ar[i].wt);
    }
    printf("\n");
    
}


void main(){
	int n,ts,rq[50],k;
    float avg_tat,avg_wt;
	printf("enter the no of process: ");
	scanf("%d",&n);
    printf("enter the time slice: ");
    scanf("%d",&ts);
	pro ar[n];
    read(ar,n);
    sort(ar,n);
    print(ar,n);
    k=work(ar,n,ts,rq);
    calc(ar,n,&avg_tat,&avg_wt);
    print(ar,n);
    printf("ready queue: \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ",rq[i]);
    }
    printf("\naverage turn around time=%f\naverage waiting time =%f\n",avg_tat,avg_wt);
}
