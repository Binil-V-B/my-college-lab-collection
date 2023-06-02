#include<stdio.h>

struct process{
    int at,bt,ct,tat,wt;
};
typedef struct process pro;


void read(pro ar[],int n){
    for (int i = 0; i < n; i++)
    {
	printf("enter the arrival time of process no %d:",i+1);
	scanf("%d",&ar[i].at);
    }
}








void main(){
	int n;
	printf("enter the no of process: ");
	scanf("%d",&n);
	struct process ar[n];
	read(ar[n],n);
}
