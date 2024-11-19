#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], pr[n], wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Input burst times and priorities
    printf("Enter Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1; // Store process number
    }

    // Sort processes by priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // Swap priorities
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process numbers
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
    }

    // Print results
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
