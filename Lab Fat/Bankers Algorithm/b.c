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

int count=0;
int safe[np],index=0;
while (count < np){
        int found=0;
        for(int i=0;i<np;i++){
            if(need[i][0] == -1) continue;
            int flag=1;
            for(int j=0;j<nr;j++){
                if(need[i][j] > ava[j]) {   // Check if the resources required by the process are less than or equal to available resources
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
            printf("System is not in safe state\n");
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