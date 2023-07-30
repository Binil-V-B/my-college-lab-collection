/*
read the no of requests - n
read the request to an array - ar
read the initial position of the disk
declare and initialze a variable total head movement to 0
create a loop to loop through the array
    total head movement = total head movement + abs(ar[i]-initial)
    update initial to ar[i]
    repeat the loop for n
*/


#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,initial,hm=0;
    printf("enter the no of requests: ");
    scanf("%d",&n);
    int ar[n];
    printf("enter the request one by one:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("enter the initial position of the head: ");
    scanf("%d",&initial);
    for (int i = 0; i < n; i++)
    {
        hm=hm+abs(initial-ar[i]);
        initial=ar[i];
    }
    printf("total head movement = %d\n",hm);
    
    
}