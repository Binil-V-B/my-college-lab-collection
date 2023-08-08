/*
    create varibles to store:
        no of process -np
        no of resources -nr
        available -a[] --used to store the available resource 
        work -work[] --used to store the no of available resources, it is copied from available
        max[][] -used to store the max no of resouces required by each process
        allocation[][] -used to store the no of resouces that are currently allocated to each process
        ss[] --used to store safe sequence
        finish[] --used to store status of each process completed/not completed
    algorithm:
        read the np,nr,
        read the allocation matrix
        read the max matrix
        read the no of available of each resource and copy the available matrix to work matrix
        set the finish[] of all process to 0
        calculate the need matrix

        start a loop which iterates through the processes -i
        start another loop which iterates throught the processes -j
            set flag =0
            check if finish[j]=0,
                check if each resource needed by the process is available
                    if not available set flag =1
                if flag=0 
                    add the allocated resource to the work matrix
                    add to the safe sequence
                    increment k
                    set finish to 1
                
            increment j
            increment i
        
        check if any process is left unfinished
            if unfinished print unsafe
            else print the safe sequence
*/
