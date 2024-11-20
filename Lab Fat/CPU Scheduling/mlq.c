#include <stdio.h>

int main() {
    int n, tq1, tq2, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time
        ct[i] = 0;
    }

    printf("Enter Time Quantum for Level 1: ");
    scanf("%d", &tq1);
    printf("Enter Time Quantum for Level 2: ");
    scanf("%d", &tq2);

    // Level 1: Round Robin with tq1
    for (int i = 0; i < n; i++) {
        if (rt[i] > 0) {
            if (rt[i] <= tq1) {
                time += rt[i];
                rt[i] = 0;
                ct[i] = time;
            } else {
                time += tq1;
                rt[i] -= tq1;
            }
        }
    }

    // Level 2: Round Robin with tq2
    for (int i = 0; i < n; i++) {
        if (rt[i] > 0) {
            if (rt[i] <= tq2) {
                time += rt[i];
                rt[i] = 0;
                ct[i] = time;
            } else {
                time += tq2;
                rt[i] -= tq2;
            }
        }
    }

    // Level 3: FCFS for remaining processes
    for (int i = 0; i < n; i++) {
        if (rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
        }
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Print Results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}
