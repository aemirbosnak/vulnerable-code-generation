//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include<stdio.h>

//one of the unique CPU scheduling algorithm is Shortest Job First (SJF)
int main(){
    int n, i, j;
    float avgWtTime = 0, avgTatTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n], wt[n], tat[n];
    printf("Enter the burst times of the processes:\n");
    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    //sorting the processes by burst time in ascending order using selection sort
    int minBT, temp, minIndex;
    for(i=0; i<n-1; i++){
        minIndex = i;
        minBT = bt[i];
        for(j=i+1; j<n; j++){
            if(bt[j] < minBT){
                minBT = bt[j];
                minIndex = j;
            }
        }
        if(minIndex != i){
            temp = bt[i];
            bt[i] = bt[minIndex];
            bt[minIndex] = temp;

            temp = p[i];
            p[i] = p[minIndex];
            p[minIndex] = temp;
        }
    }
    //calculating waiting time and turn around time of each process
    wt[0] = 0;
    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] += bt[j];
        }
    }
    for(i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }
    //calculating average waiting time and turn around time
    for(i=0; i<n; i++){
        avgWtTime += wt[i];
        avgTatTime += tat[i];
    }
    avgWtTime /= n;
    avgTatTime /= n;
    //displaying the final values
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("P[%d]\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f\n", avgWtTime);
    printf("Average Turnaround Time: %f\n", avgTatTime);

    return 0;
}