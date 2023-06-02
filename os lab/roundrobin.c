#include<stdio.h>

struct process{
    int at,bt,ct,tat,wt;
};
typedef struct process pro;


void read(pro ar[],int n){
    for (int i = 0; i < n; i++)
    {
	printf("\nenter the arrival time of process no %d:",i+1);
	scanf("%d",&ar[i].at);
    printf("enter the burst time of process no %d:",i+1);
    scanf("%d",&ar[i].bt);
    }
}


void print(pro ar[],int n){
    printf("process|\tat|\tbt|\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n",i+1,ar[i].at,ar[i].bt);
    }
    
}






void main(){
	int n;
	printf("enter the no of process: ");
	scanf("%d",&n);
	pro ar[n];
	read(ar,n);
    print(ar,n);
}
