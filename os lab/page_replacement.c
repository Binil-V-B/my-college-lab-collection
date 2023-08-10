/*
read the no of pages -np
read the reference string -rs[]
read the no of frames -nf
create an array frames[nf]
set the vaule of all index in frames[] as -1
set i=0,pagefault=0,k=0;

declare a vaiable j and initailize with 0 to track the position in the frame
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