#include<stdio.h>

struct process{
    int at,bt,ct,tat,wt,bt1;
};
typedef struct process pro;


void read(pro ar[],int n){
    for (int i = 0; i < n; i++)
    {
	printf("\nenter the arrival time of process no %d:",i+1);
	scanf("%d",&ar[i].at);
    printf("enter the burst time of process no %d:",i+1);
    scanf("%d",&ar[i].bt);
    ar[i].bt1 = ar[i].bt;
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

void work(pro ar[],int n, int time){
    int current_time;
    current_time = ar[0].at;
    for (int  i = 0; i < n; i++)
    {
        
    
    
    if (ar[i].bt1 <= time)
    {
        ar[i].bt = 0;
    }
    else if(ar[i].bt1 > time){
        
    }
    }
    
}


void print(pro ar[],int n){
    printf("process|\tat|\tbt|\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n",i+1,ar[i].at,ar[i].bt);
    }
    printf("\n");
    
}






void main(){
	int n,ts;
    printf("enter the time space for each processes: ");
    scanf("%d",&ts);
	printf("enter the no of process: ");
	scanf("%d",&n);
	pro ar[n];
	read(ar,n);
    print(ar,n);
    sort(ar,n);
    print(ar,n);
}
