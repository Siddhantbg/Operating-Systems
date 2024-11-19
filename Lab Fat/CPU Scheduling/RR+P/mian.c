#include <stdio.h>

void roundRobin(int n, int bt[], int rt[], int tq) {
    int t = 0, completed = 0, wt = 0, tat = 0;
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
}

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int bt[n], rt[n], pr[n], p[n];
    printf("Enter burst times and priorities (format: bt pr):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];
        p[i] = i + 1; // Process IDs
    }

    // Sort based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = rt[i];
                rt[i] = rt[j];
                rt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("Execution Order (by priority, Round Robin within same priority):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i]);
    }
    printf("\n");

    roundRobin(n, bt, rt, tq);
    return 0;
}
