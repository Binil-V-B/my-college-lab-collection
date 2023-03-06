#include<stdio.h>

struct pro{
    int pid,at,bt,ct,tat,wt;
};

void main(){
    int a;
    printf("Enter the no of processes: ");
    scanf("%d",&a);
    struct pro ar[a];
    read(ar,a);
    sort(ar,a);
    calc(ar,a);

}

void read(struct pro a[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the process id: ");
        scanf("%d",a[i].pid);
        printf("Enter the arrival time: ");
        scanf("%d",a[i].at);
        printf("Enter the buffer time: ");
        scanf("%d",a[i].bt);
    }
}

void sort(struct pro a[],int n){
    struct pro temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].at>a[j+1].at){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

void calc(struct pro a[],int n){
    a[0].ct=a[0].bt+a[0].at;
    a[0].tat=a[0].ct-a[0].at;
    a[0].wt=a[0].tat-a[0].bt;
    for(int i=1;i<n;i++){
        a[i].ct=a[i-1].ct+a[i].bt;
        a[i].tat=a[i].ct-a[i].at;
        a[i].wt=a[i].tat-a[i].bt;
    }
}

void avg1(struct pro a[],int n){
    float a;


}


void print(){}