//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int bt; // Burst time
    int wt; // Waiting time
    int rt; // Remaining time
};

void calculateWaitingTime(struct Process proc[], int n, int quantum) {
    int remaining = n;
    for (int t = 0; remaining != 0;) {
        for (int i = 0; i < n; ++i) {
            if (proc[i].rt > 0) {
                if (proc[i].rt > quantum) {
                    t += quantum;
                    proc[i].rt -= quantum;
                } else {
                    t += proc[i].rt;
                    proc[i].wt = t - proc[i].bt;
                    proc[i].rt = 0;
                    remaining--;
                }
            }
        }
    }
}

void displayResults(struct Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].wt);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process *proc = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].bt);
        proc[i].rt = proc[i].bt; // Remaining time initialized to burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    calculateWaitingTime(proc, n, quantum);
    displayResults(proc, n);

    free(proc);

    return 0;
}