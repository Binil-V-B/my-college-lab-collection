#include<stdio.h>

struct process{
	int pid,at,bt,bt_c,ct,wt,tat,flag;
};

void read(struct process ar[],int n){
	for(int i=0;i<n;i++){
		printf("Enter the arrival time of p%d: ",i+1);
		scanf("%d",&ar[i].at);
		printf("Enter the burst time of p%d: ",i+1);
		scanf("%d",&ar[i].bt);
		ar[i].bt_c=ar[i].bt;
		ar[i].pid = i+1;
		ar[i].flag=0;
	}
}

void sort(struct process ar[],int n){
	struct process temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(ar[j].at>ar[j+1].at){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}

void work(struct process ar[],int n){
	int i=0,current_time,no=0,j,small;
	current_time=ar[0].at;
	for(;no!=n;){ //no tracks the no of processes finished and n is the total no of processes
		ar[i].bt_c--;
		current_time++;
		if(ar[i].bt_c==0){
			ar[i].flag=1;
			no++;
			ar[i].ct=current_time;
			ar[i].tat= ar[i].ct - ar[i].at;
			ar[i].wt= ar[i].tat - ar[i].bt;
		}
		
		j=i;
		small=999;
		for(int k =0;k<n;k++){
			if(ar[k].bt_c<=small && ar[k].flag==0 && ar[k].at<=current_time){
				small=ar[k].bt_c;
				j=k;
			}
		}
		if(j!=i || small==999){printf("  %d-%d  ",ar[i].pid,current_time);}
		i=j;
		
	}
}

void print(struct process ar[],int n){
    printf("\n\nafter scheduling:\npid\tat\tbt\tct\ttat\twt\n---------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",ar[i].pid,ar[i].at,ar[i].bt,ar[i].ct,ar[i].tat,ar[i].wt);
    }
    printf("\n");
}

void main(){
	int n;
	printf("Enter the no of processe: ");
	scanf("%d",&n);
	struct process ar[n];
	read(ar,n);
	sort(ar,n);
	work(ar,n);
	print(ar,n);
}


