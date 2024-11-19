#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int t = 0, completed = 0, wt = 0, tat = 0;

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        int shortest = -1, min_rt = INT_MAX;

        // Find the shortest remaining job
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        // Execute the selected process for 1 unit of time
        rt[shortest]--;
        if (rt[shortest] == 0) {
            completed++;
            int finish_time = t + 1;
            wt += finish_time - at[shortest] - bt[shortest];
            tat += finish_time - at[shortest];
        }

        t++;
    }

    printf("Average Waiting Time: %.2f\n", (float)wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)tat / n);

    return 0;
}
