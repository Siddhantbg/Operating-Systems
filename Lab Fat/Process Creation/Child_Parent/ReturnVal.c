#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
    pid_t id;
    printf("--------------------\n");
    printf("\tReturn Code of Parent & Child\n");
    printf("--------------------\n");

    id=fork();
    if(id==0){
        printf("Child Process\n");
        printf("Child Process Return Value: %d\n",id);
    }
    else{ //! Identified by >0
        printf("Parent Process is calling---\n");
        printf("Parent Process Return Value: %d\n",id);
    }
    return 0;
}