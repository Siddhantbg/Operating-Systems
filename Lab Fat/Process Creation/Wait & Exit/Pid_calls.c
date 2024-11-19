#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pd;
    printf("------------------------------------\n");
    printf("\t wait() and exit()\n");
    printf("------------------------------------\n");
    
    if(fork()==0){
        printf("Child is Calling....\n");
        exit(0); //!ye use kr rhe
    }
    else{
        pd=wait(NULL);
        printf("Parent is calling...\n");
        printf("Parent PID\t:%d\n",getppid());
        printf("Child Process ID\t: %d\n",pd);
    }
    return 0;
}