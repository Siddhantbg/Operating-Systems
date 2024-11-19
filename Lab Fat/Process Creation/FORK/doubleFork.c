#include <unistd.h>
#include <stdio.h>

int main(){
    printf("-----------------\n");
    printf("\tCalling Double Fork");
    printf("\t-----------------\n");
    fork();
    fork();
    printf("Good Morning\n");
    return 0;
}