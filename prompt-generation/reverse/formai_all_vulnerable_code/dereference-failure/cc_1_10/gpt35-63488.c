//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include<stdio.h>
#include<stdlib.h>

struct process{
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main(){
    int n, q, i, j, currentTime = 0, count = 0;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    struct process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (struct process*)malloc(n * sizeof(struct process));

    for(i = 0; i < n; i++){
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burstTime);
        p[i].waitingTime = p[i].turnaroundTime = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &q);

    i = 0;
    while(count < n){
        if(p[i].burstTime > q){
            p[i].burstTime -= q;
            currentTime += q;
        }else if(p[i].burstTime > 0){
            currentTime += p[i].burstTime;
            p[i].burstTime = 0;
        }
        for(j = 0; j < n; j++){
            if(j != i && p[j].burstTime > 0)
                p[j].waitingTime += q;
        }
        if(p[i].burstTime == 0){
            count++;
            p[i].turnaroundTime = currentTime;
            avgWaitTime += p[i].waitingTime;
            avgTurnaroundTime += p[i].turnaroundTime;
        }
        i = (i + 1) % n;
    }

    avgWaitTime /= n;
    avgTurnaroundTime /= n;

    printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }

    printf("\nAverage waiting time: %f\nAverage turnaround time: %f", avgWaitTime, avgTurnaroundTime);

    free(p);

    return 0;
}