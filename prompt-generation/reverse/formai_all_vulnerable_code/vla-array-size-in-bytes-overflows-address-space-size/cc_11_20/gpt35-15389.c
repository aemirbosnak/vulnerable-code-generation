//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include<stdio.h>

//Grateful CPU Scheduling Algorithm
int main(){
    int n, temp;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int burst_time[n],arrival_time[n],completion_time[n],turn_around_time[n],waiting_time[n],process_num[n];
    printf("\nEnter the burst time and arrival time of each process:\n");
    for(int i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d%d",&burst_time[i],&arrival_time[i]);
        process_num[i] = i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrival_time[i]>arrival_time[j]){
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;

                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;

                temp=process_num[i];
                process_num[i]=process_num[j];
                process_num[j]=temp;
            }
        }
    }
    int time=0, min=1000, smallest;
    for(int i=0;i<n;i++){
        if(arrival_time[i]<=time && burst_time[i]<min && burst_time[i]>0){
            min=burst_time[i];
            smallest=i;
        }
    }
    int run_time=1;
    while(run_time){
        burst_time[smallest]--;
        time++;
        if(burst_time[smallest]==0){
            run_time=0;
            completion_time[smallest]=time;
            turn_around_time[smallest]=completion_time[smallest]-arrival_time[smallest];
            waiting_time[smallest]=turn_around_time[smallest]-burst_time[smallest];
        }
        min = 1000;
        for(int i=0;i<n;i++){
            if(arrival_time[i]<=time && burst_time[i]<min && burst_time[i]>0){
                min=burst_time[i];
                smallest=i;
            }
        }
        if(run_time==0){
            int flag=0;
            for(int i=0;i<n;i++){
                if(burst_time[i]>0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                run_time=1;
            }
        }
    }
    printf("\n");
    printf("Process\tBurst-Time\tArrival-Time\tCompletion-Time\tTurnAround-Time\tWaiting-Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",process_num[i],burst_time[i],arrival_time[i],completion_time[i],turn_around_time[i],waiting_time[i]);
    }
    printf("\n");
    return 0;
}