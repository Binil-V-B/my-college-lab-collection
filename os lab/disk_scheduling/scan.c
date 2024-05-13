/*
read the no of disk requests -n
read all the request to an array -ar
read the size of the disk -max
read the initial position of the head -initial
read the direction -0 or 1
declare a variable headmovement and initialize it to 0
sort the request in the ascending order using any sorting algorithm
find the index of request in array which is right next to the initial position of the head -index

if direction is to right (1)
    i=index
    create a loop which starts from the i and iterates until i<n  --this will visit all the cylinders to the right of the intial cylinder
    headmovement+=ar[i]-initial
    initial=ar[i]
    i++

    create a loop which iterates from i=index-1 to 0
    headmovement+=initial - ar[i];
    i--;


if direction is to left (0)

print the total head movement;
    
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
    int j,i,n,temp,max,initial,headmovement=0,drection,index;
    printf("enter the no of disk requests: ");
    scanf("%d",&n);
    int ar[n];
    printf("enter all the request: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("enter the max size of the disk: ");
    scanf("%d",&max);
    max--;
    printf("enter the initial position of the head: ");
    scanf("%d",&initial);
    printf("enter the direction of movement of the head \n 0-low \n 1-high\n:");
    scanf("%d",&drection);


    //bubble sort
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            
        }
        
    }
    
    //finding the index just right to the intial position of the head
    for (int i = 0; i < n; i++)
    {
        if (ar[i]>initial)
        {
            index=i;break;
        }
        index=i;
    }
    

    switch (drection)
    {
    case 1:
        for (i = index; i < n; i++)
        {
            headmovement+=abs(ar[i]-initial);
            initial=ar[i];
        }
        headmovement+=max-initial;
        initial=max;
        for ( i = index-1; i >= 0; i--)
        {
            headmovement+=initial-ar[i];
            initial=ar[i];
        }
        break;
    
    case 0:
        for (i = index-1; i >= 0; i--)
        {
            headmovement+=abs(initial-ar[i]);
            initial=ar[i];
        }
        headmovement+=initial;
        initial=0;
        for ( i =index; i < n; i++)
        {
            headmovement+=ar[i]-initial;
            initial=ar[i];
        }
        break;

    default:
        exit(0);
    }

    printf("total head movement=%d\n",headmovement);    
}