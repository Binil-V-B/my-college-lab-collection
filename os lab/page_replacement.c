/*
read the no of pages -np
read the reference string -rs[]
read the no of frames -nf
create an array frames[nf]
set the vaule of all index in frames[] as -1
set i=0,pagefault=0,k=0;

declare a vaiable i and initailize with 0 to track the position in the frame
print the i the index of reference string
set avail =0
check if the current reference string is alredy present on the frame
    set avail to 1
check if avail 0
    increment pagefault
    frames[k]=rs[i]
    k=(k+1)%nf
    print all the value in the frame
increment i
goto line 

*/

#include<stdio.h>
void main(){
    int np,nf,avail,paf=0;
    printf("enter the no of pages: ");
    scanf("%d",&np);
    int rs[np];
    printf("enter the reference string: \n");
    for (int i = 0; i < np; i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("enter the no of frames: ");
    scanf("%d",&nf);
    int frames[nf];
    for (int i = 0; i < nf; i++)
    {
        frames[i]=-1;
    }


    int k=0;
    printf("refe string\tframe\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d\t",rs[i]);
        avail=0;
        for (int j = 0; j < nf; j++)
        {
            if (frames[j]==rs[i])
            {
                avail=1;
                break;
            }
        }
        if (avail==0)
        {
            paf++;
            frames[k]=rs[i];
            k=(k+1)%nf;
            for (int a = 0; a < nf; a++)
            {
                printf("\t%d",frames[a]);
            }  
        }
        printf("\n");
        
    }
    printf("\ntotal page fault= %d\n",paf);
    
       
}