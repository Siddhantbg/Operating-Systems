#include <stdio.h>

int main() {
    int b, p;
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    int block[b];
    printf("Enter sizes of blocks: ");
    for (int i = 0; i < b; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p], allocation[p];
    printf("Enter sizes of processes: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1; // Initialize as not allocated
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) { // Check if block fits
                allocation[i] = j;       // Allocate block j to process i
                block[j] -= process[i];  // Reduce available memory
                break;
            }
        }
    }

    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
