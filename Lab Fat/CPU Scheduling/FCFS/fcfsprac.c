#include <stdio.h>

int main(){
    int n;
    printf("Enter a processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    int tot_wt=0,tot_tat;

    printf("Enter burst time for each processes");
    for(int i=0;i<n;i++){
        printf("Process P%d:",i);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;

    //! Wait time= Burst Time + Wait Time
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
        }
        //! TAT= BT+WT
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
    //!total wait time and turnaround time
    for(int i=0;i<n;i++){
        tot_wt+=wt[i];
        tot_tat+=tat[i];
}
printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
for(int i=0;i<n;i++){
    printf("P%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
}

printf("\n Avg Wait time:%f", (float)tot_wt / n);
printf("\n Avg Turnaround time:%f",(float)tot_tat / n);

return 0;
}