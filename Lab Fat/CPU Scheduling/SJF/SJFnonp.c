#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n], completed[n];
    int total_wt = 0, total_tat = 0;

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;  // Process ID
        completed[i] = 0;  // Mark all as incomplete initially
    }

    int time = 0;  // Track current time

    for (int count = 0; count < n; count++) {
        int min_bt = 9999, shortest = -1;

        // Find the process with the shortest burst time that is not completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                shortest = i;
            }
        }

        // Process the selected task
        completed[shortest] = 1;  // Mark as completed
        wt[shortest] = time;  // Waiting time is current time
        time += bt[shortest];  // Increment current time by burst time
        tat[shortest] = time;  // Turnaround time = waiting + burst time
    }

    // Calculate total waiting time and turnaround time
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f\n", (float)total_wt /n);
    printf("Average Turnaround Time: %f\n", (float)total_tat /n);

    return 0;
}
