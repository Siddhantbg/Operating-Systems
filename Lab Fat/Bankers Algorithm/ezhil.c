#include <stdio.h> 
#include <stdbool.h> 
 
void calculateNeed(int need[][10], int max[][10], int alloc[][10], int np, int nr) { 
    // Calculate the need matrix 
    for (int i = 0; i < np; i++) { 
        for (int j = 0; j < nr; j++) { 
            need[i][j] = max[i][j] - alloc[i][j]; 
        } 
    } 
} 
 
bool isSafe(int processes[], int avail[], int max[][10], int alloc[][10], int np, int 
nr) { 
    int need[10][10]; 
    calculateNeed(need, max, alloc, np, nr); 
 
    bool finish[np]; 
    for (int i = 0; i < np; i++) { 
        finish[i] = false; 
    } 
 
    int safeSeq[np]; 
    int work[nr]; 
    for (int i = 0; i < nr; i++) { 
        work[i] = avail[i]; 
    } 
 
    int count = 0; 
    while (count < np) { 
        bool found = false; 
        for (int p = 0; p < np; p++) { 
            if (!finish[p]) { 
                int j; 
                for (j = 0; j < nr; j++) { 
                    if (need[p][j] > work[j]) 
                        break; 
                } 
                if (j == nr) { 
                    for (int k = 0; k < nr; k++) 
                        work[k] += alloc[p][k]; 
                     
                    safeSeq[count++] = processes[p]; 
                    finish[p] = true; 
                    found = true; 
                } 
            } 
        } 
        if (!found) { 
            printf("System is not in safe state.\n"); 
            return false; 
        } 
    } 
 
    printf("System is in safe state.\nSafe sequence is: "); 
    for (int i = 0; i < np; i++) { 
        printf("%d ", safeSeq[i]); 
    } 
    printf("\n"); 
    return true; 
} 
 
void requestResources(int processes[], int avail[], int max[][10], int alloc[][10], 
int np, int nr) { 
    int process_num; 
    int request[nr]; 
 
    printf("Enter the process number making the request (0-%d): ", np-1); 
    scanf("%d", &process_num); 
 
    printf("Enter the requested resources: "); 
    for (int i = 0; i < nr; i++) { 
        scanf("%d", &request[i]); 
    } 
 
    for (int i = 0; i < nr; i++) { 
        if (request[i] > avail[i]) { 
            printf("Requested resources are greater than available resources. Request cannot be granted.\n"); 
            return; 
        } 
    } 
 
    for (int i = 0; i < nr; i++) { 
        if (request[i] > max[process_num][i] - alloc[process_num][i]) { 
            printf("Requested resources exceed maximum claim for process.Request cannot be granted.\n"); 
            return; 
        } 
    } 
 
    for (int i = 0; i < nr; i++) { 
        avail[i] -= request[i]; 
        alloc[process_num][i] += request[i]; 
        max[process_num][i] -= request[i]; 
    } 
 
    if (isSafe(processes, avail, max, alloc, np, nr)) { 
        printf("Request can be granted. Resources have been allocated.\n"); 
    } else { 
        printf("Request cannot be granted as it leads to unsafe state. Rolling back  the request.\n"); 
        for (int i = 0; i < nr; i++) { 
            avail[i] += request[i]; 
            alloc[process_num][i] -= request[i]; 
            max[process_num][i] += request[i]; 
        } 
    } 
} 
 
int main() { 
    int np, nr; 
    int processes[10], avail[10]; 
    int max[10][10], alloc[10][10]; 
 
    printf("Enter the number of processes: "); 
    scanf("%d", &np); 
 
    printf("Enter the number of resources: "); 
    scanf("%d", &nr); 
 
    printf("Enter the allocation matrix:\n"); 
    for (int i = 0; i < np; i++) { 
        processes[i] = i; 
        for (int j = 0; j < nr; j++) { 
            scanf("%d", &alloc[i][j]); 
        } 
    } 
 
    printf("Enter the maximum demand matrix:\n"); 
    for (int i = 0; i < np; i++) { 
        for (int j = 0; j < nr; j++) { 
            scanf("%d", &max[i][j]); 
        } 
    } 
 
    printf("Enter the available resources: "); 
    for (int i = 0; i < nr; i++) { 
        scanf("%d", &avail[i]); 
    } 
 
    if (isSafe(processes, avail, max, alloc, np, nr)) { 
        printf("System is in a safe state.\n"); 
    } else { 
        printf("System is not in a safe state.\n"); 
    } 
 
    char ch; 
    printf("Do you want to request resources for a process? (y/n): "); 
    scanf(" %c", &ch); 
 
    if (ch == 'y' || ch == 'Y') { 
        requestResources(processes, avail, max, alloc, np, nr); 
    } 
 
    return 0; 
} 

/*
Enter the number of processes: 3
Enter the number of resources: 3
Enter the allocation matrix:
1 2 3
3 4 5
2 3 4
Enter the maximum demand matrix:
5 5 5
5 5 5
5 5 5
Enter the available resources: 4 4 4
System is in safe state.
Safe sequence is: 0 1 2
System is in a safe state.
Do you want to request resources for a process? (y/n): y
Enter the process number making the request (0-2): 1
Enter the requested resources: 2 3 4 
Requested resources exceed maximum claim for process.Request cannot be granted.
*/