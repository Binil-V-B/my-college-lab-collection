/*
create a structer with structure variables
read the no of processes to be allocated
read all the details of the process to be allocated
arrange the processes in the ascending order of arrival time
    create a variable current_time 
    take the first process and set current_time = arrival time + burst time of first process
    set ct = current_time
    set ar[1].check=1
    print [pid]
    find the next process
        search for the highest priority(take the lowest number as high priority) process from arrival time of first process to current_time and ar[i].check==0
        set ct = bt+ current_time
        set ar[i].check=1
        print [pid]

    calculate wt,tat
        
*/


#include<stdio.h>

struct process{
    int pid,at,bt,ct,wt,tat,pr,check;
};

void read(struct process ar[],int n){
	for(int i=0;i<n;i++){
		printf("Enter the arrival time of p%d: ",i+1);
		scanf("%d",&ar[i].at);
		printf("Enter the burst time of p%d: ",i+1);
		scanf("%d",&ar[i].bt);
        printf("Enter the priority: ");
        scanf("%d",&ar[i].pr);
		ar[i].pid = i+1;
        ar[i].check=0;
	}
}

void sort(struct process ar[],int n){
    struct process temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n-1; i++)
        {
            if(ar[j+1].at<ar[j].at){
                temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp; 
            }
        }   
    }
}

void work(struct process ar[],int n){
    int current_time,high;
    current_time = ar[0].at + ar[0].bt;
    ar[0].ct = current_time;
    ar[0].check =1;
    printf("\nGantt chart:\t[ %d ]",ar[0].pid);
    for (int i = 1; i < n; i++)
    {
        high=-1;
        for (int j = 1; j < n; j++)
        {
            if (ar[j].at<=current_time && ar[j].check==0)
            {
                if (high==-1)
                {
                    high=j;
                }
                else{
                    if (ar[j].pr > ar[high].pr)
                    {
                        high=j;
                    }
                    
                }   
            } 
        }
        ar[high].ct=ar[high].bt+current_time;
        current_time+=ar[high].ct;
        ar[high].check=1;
        printf("\t[ %d ]",ar[high].pid);
    }
}

void calc(struct process ar[],int n,int *avg_wt,int *avg_tat){
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}

void print(struct process ar[],int n){
    printf("\n\npid\tpr\tat\tbt\tct\ttat\twt\n---------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].pr,ar[i].at,ar[i].bt,ar[i].ct,ar[i].tat,ar[i].wt);
    }
    printf("\n"); 
}


void main(){
    int n;
    printf("enter the no of processes: ");
    scanf("%d",&n);
    struct process ar[n];
    read(ar,n);
    sort(ar,n);
    work(ar,n);
    print(ar,n);
}
