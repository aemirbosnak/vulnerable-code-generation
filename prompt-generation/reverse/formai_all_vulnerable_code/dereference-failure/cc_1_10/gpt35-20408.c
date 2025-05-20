//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

/* Queue size */
#define SIZE 5

/* Structure for each process */
struct Process {
    int pid;
    int at; /* Arrival time */
    int bt; /* Burst time */
    int wt; /* Waiting time */
    int tt; /* Turnaround time */
}; 

/* Insert function for queue */
void insert(struct Process queue[], struct Process p, int *rear) {
    if (*rear == SIZE - 1) {
        printf("Queue is full\n");
        exit(1);
    }

    queue[++(*rear)] = p;
}

/* Delete function for queue */
struct Process delete(struct Process queue[], int *front, int rear) {
    if (*front == rear + 1) {
        printf("Queue is empty\n");
        exit(1);
    }

    return queue[(*front)++];
}

/* Round Robin scheduling algorithm */
void round_robin(struct Process queue[], int front, int rear, int quantum) {
    int i, t = 0, flag = 0;

    while (front <= rear) {
        struct Process p = delete(queue, &front, rear);

        if (p.bt > quantum) {
            p.bt -= quantum;
            t += quantum;
            insert(queue, p, &rear);
        } else {
            t += p.bt;
            p.tt = t - p.at;
            p.wt = p.tt - p.bt;
            printf("Process %d: Waiting time = %d, Turnaround time = %d\n", p.pid, p.wt, p.tt);
            flag = 1;
        }

        if (front > rear && flag == 0) {
            printf("No more processes left to execute\n");
        }
    }
}

/* Main function */
int main() {
    int n, quantum, i, front = 0, rear = -1;

    /* Input number of processes and time quantum */
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    /* Initialize queue */
    struct Process *queue = (struct Process*) malloc(sizeof(struct Process) * SIZE);

    /* Input arrival time and burst time for each process */
    for (i = 0; i < n; i++) {
        struct Process p;
        p.pid = i + 1;
        printf("Enter arrival time and burst time of process %d: ", p.pid);
        scanf("%d%d", &p.at, &p.bt);
        insert(queue, p, &rear);
    }

    /* Call Round Robin scheduling algorithm */
    round_robin(queue, front, rear, quantum);

    return 0;
}