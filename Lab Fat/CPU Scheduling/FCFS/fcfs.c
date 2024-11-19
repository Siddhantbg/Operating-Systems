#include <stdio.h>

int main() {
    int n;
    
    // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n];
    int total_wt = 0, total_tat = 0;
    
    // Burst time input
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        scanf("%d", &bt[i]);
    }
    
    // Calculate waiting time for each process
    wt[0] = 0;  // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        //! wait time = button time + wait time
    }
    
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        //! turnAround time= burst time + wait time
    }
    
    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i]; 
        total_tat += tat[i];
        //!total wait time and turnaround time
    }
    

    // Print process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    
    // Print average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
    
    return 0;
}
