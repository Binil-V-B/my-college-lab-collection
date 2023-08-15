 /*
    read the no of requests -n
    read all the request to an array -ar
    sort the array using bubble sort
    read the max no of disk cylinders -max
    declare and initialise a varible called headmovement to 0
    read the initial position of the head -initial
    find the index in ar which is right next to initial position -xx
    read the direction of the head movement -direction 0/1 -0 for left and 1 for right
    if direction =1
        set i=xx and loop until i<n
            headmovement += ar[i] - initial
            initial = ar[i]
            i++;
        headmovement += max - initial
        

*/

#include<stdio.h>

void main(){
    int n,initial,dir,index;
    printf("enter the no of requests: ");
    scanf("%d",&n);
    int ar[n];
    printf("enter the request sequence:\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }

    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (ar[i]<ar[i+1])
            {
                temp=ar[i+1];
                ar[i+1]=ar[i];
                ar[i]=temp;   
            } 
        }
    }

    printf("enter the initial position of the head: ");
    scanf("%d",&initial);
    printf("enter the initial head movement:\n 1-high \n 0-low");
    scanf("%d",&dir);    

    for (int i = 0; i < n; i++)
    {
        if (ar[i]>initial)
        {
            index=i;
            break;
        }
    }

    
    

    switch (dir)
    {
    case 1 :

        break;
    
    case 0 :
        break;

    default:
        break;
    }
}