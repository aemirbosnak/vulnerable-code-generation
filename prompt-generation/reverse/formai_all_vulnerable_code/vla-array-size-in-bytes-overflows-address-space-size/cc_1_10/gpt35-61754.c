//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

struct process {
    int pid; // Process ID
    int bt; // Burst Time
    int at; // Arrival Time
    int ct; // Completion Time
    int wt; // Waiting Time
};

void fcfs(struct process p[], int n) {
    int t = 0; // stores current time
    for(int i=0;i<n;i++) {
        if(t < p[i].at) t = p[i].at; // check if process has arrived or not
        p[i].ct = t + p[i].bt; // set completion time of process
        p[i].wt = t - p[i].at; // set waiting time of process
        t = p[i].ct; // update current time
    }
}

void sjf(struct process p[], int n) {
    int t = 0; // stores current time
    int idx = 0; // index of process with shortest remaining time
    int done = 0; // no of processes completed
    while(done < n) {
        int minval = 1000;
        for(int i=0;i<n;i++) {
            if(p[i].at <= t && p[i].bt < minval && p[i].ct == 0) {
                minval = p[i].bt;
                idx = i;
            }
        }
        p[idx].ct = t + p[idx].bt; // set completion time of process
        p[idx].wt = t - p[idx].at; // set waiting time of process
        t = p[idx].ct; // update current time
        done++;
    }
}

int main() {
    int n;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    struct process p[n];
    srand(time(0));
    // generate random arrival times and burst times
    for(int i=0;i<n;i++) {
        p[i].pid = i+1;
        p[i].at = rand() % 10 + 1;
        p[i].bt = rand() % 10 + 1;
        p[i].ct = p[i].wt = 0;
    }
    printf("\nFCFS scheduling\n");
    fcfs(p,n);
    // print details of each process
    printf("ID AT BT CT WT\n");
    for(int i=0;i<n;i++) {
        printf("%d %d %d %d %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].wt);
    }
    for(int i=0;i<n;i++) {
        p[i].ct = p[i].wt = 0;
    }
    printf("\nSJF scheduling\n");
    sjf(p,n);
    // print details of each process
    printf("ID AT BT CT WT\n");
    for(int i=0;i<n;i++) {
        printf("%d %d %d %d %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].wt);
    }
    return 0;
}