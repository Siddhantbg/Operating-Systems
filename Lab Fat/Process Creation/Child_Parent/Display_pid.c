#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
    pid_t id;
    printf("----------------------------\n");
    printf("\tProcess ID of Parent & Child\n");
    printf("----------------------------\n");

    id=fork();
    if(id==0){
        printf("Child Process Calling....\n");
        printf("Process ID (PID) of child Process:%d\n",getpid());
    }else{
        printf("Parent Process Calling....\n");
        printf("Process ID (PID) of Parent Process:%d\n",getppid());
    }//! getppid()
    return 0;
}