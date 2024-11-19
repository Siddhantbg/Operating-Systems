#include <stdio.h>

int main(){
    int np,nr;
    printf("Enter the number of processes: ");
    scanf("%d",&np);
    printf("Enter the number of resources: ");
    scanf("%d",&nr);
    //!      Row Column
    int alloc[np][nr];
    int max[np][nr];
    int ava[nr];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&alloc[i][j]);
            }
    }
    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
            }
    }
    printf("Enter Available Matrix:\n");
    for(int i=0;i<nr;i++){
        scanf("%d",&ava[i]);
        }
        int need[np][nr];
//NEED MATRIX 
        for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){
                need[i][j]=max[i][j]-alloc[i][j];
        }        
        }
/*   
!NEED MATRIX
?Process  R0   R1
?P0       2    1
?P1       3    3
?P2       1    1

?Iteration 1: Process P0 (i = 0)
?need[0][j]: For P0, the need is {2, 1}.
?Check resource type R0 (j = 0):
?need[0][0] = 2, avail[0] = 3
?2 <= 3 → Satisfied
?Check resource type R1 (j = 1):
?need[0][1] = 1, avail[1] = 2
?1 <= 2 → Satisfied
?Since both resource checks pass, flag = 1, and P0 can execute.

Iteration 2: Process P1 (i = 1)
need[1][j]: For P1, the need is {3, 3}.
Check resource type R0 (j = 0):
need[1][0] = 3, avail[0] = 3
3 <= 3 → Satisfied
Check resource type R1 (j = 1):
need[1][1] = 3, avail[1] = 2
3 > 2 → Not satisfied
Since need[1][1] exceeds avail[1], flag = 0, and P1 cannot execute.
*/
int count=0;
int safe[np],index=0;
while (count < np){
        int found=0;
        for(int i=0;i<np;i++){
            if(need[i][0] == -1) continue;
            int flag=1;
            for(int j=0;j<nr;j++){
                if(need[i][j] > ava[j]) {
                    flag=0;
                    break;
                }
        }
        if(flag==1){
            for(int j=0;j<nr;j++){
                ava[j] += alloc[i][j]; // Release allocated resources
                }
                safe[index++]=i; //safe state
                count++;//counting the processes 
                need[i][0]=-1;//invalidating the finished process
                found=1;
                break;
        }
        }
        if(found==0){
            printf("System is not in ssafe state\n");
            return 0;
        }
}

printf("The System is in a Safe State.\n");
printf("The order of processes in a safe sequence is: \n");
for(int i=0;i<index;i++){
    printf("P%d->",safe[i]);
   
    }
    printf("End\n");
    return 0;
}