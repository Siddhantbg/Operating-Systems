#include <unistd.h>
#include <stdio.h>

int main(){
    printf("----------------------\n");
    printf("  Welcome to the triple Fork!\n");
    printf("----------------------\n");
    fork();
    fork();
    fork();
    printf("Kr dia Fork\n");
    return 0;
}

//! FORK ALWAYS WORKS IN 2^n