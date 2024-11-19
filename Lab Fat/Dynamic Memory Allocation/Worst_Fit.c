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
        int worstIdx = -1;
        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (worstIdx == -1 || block[j] > block[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;    // Allocate block worstIdx to process i
            block[worstIdx] -= process[i]; // Reduce available memory in the block
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
