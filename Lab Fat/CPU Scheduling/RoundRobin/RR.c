#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int bt[n], rt[n], wt = 0, tat = 0, t = 0, completed = 0;

    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= tq) {
                    t += rt[i];
                    rt[i] = 0;
                    completed++;
                    wt += t - bt[i];
                    tat += t;
                } else {
                    t += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    printf("Average Waiting Time: %.2f\n", (float)wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)tat / n);

    return 0;
}
