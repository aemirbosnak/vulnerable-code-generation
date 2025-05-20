//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Task structure
typedef struct task {
    int id;         // Task ID
    int arrival;    // Arrival time
    int burst;      // Burst time
} task;

// Compare function for sorting tasks by arrival time
int compare_arrival(const void *a, const void *b) {
    return ((task *)a)->arrival - ((task *)b)->arrival;
}

// Compare function for sorting tasks by burst time
int compare_burst(const void *a, const void *b) {
    return ((task *)a)->burst - ((task *)b)->burst;
}

// Round-robin scheduling algorithm
void round_robin(task *tasks, int n, int quantum) {
    int time = 0; // Current time
    int completed = 0; // Number of completed tasks
    int waiting = 0; // Average waiting time
    int turnaround = 0; // Average turnaround time
    int remaining[n]; // Remaining burst time for each task
    for (int i = 0; i < n; i++) {
        remaining[i] = tasks[i].burst;
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (remaining[i] <= quantum) {
                    time += remaining[i];
                    remaining[i] = 0;
                    completed++;
                    turnaround += time - tasks[i].arrival;
                } else {
                    time += quantum;
                    remaining[i] -= quantum;
                }
            }
        }
    }

    waiting = turnaround - time;
    printf("\nRound-Robin Scheduling Algorithm\n");
    printf("--------------------------------------------\n");
    printf("Task ID  Arrival  Burst  Waiting  Turnaround\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", tasks[i].id, tasks[i].arrival, tasks[i].burst, waiting, turnaround);
    }
    printf("--------------------------------------------\n");
    printf("Average Waiting Time: %d\n", waiting / n);
    printf("Average Turnaround Time: %d\n", turnaround / n);
}

int main() {
    // Input
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    task tasks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time for task %d: ", i + 1);
        scanf("%d", &tasks[i].arrival);
        printf("Enter the burst time for task %d: ", i + 1);
        scanf("%d", &tasks[i].burst);
        tasks[i].id = i + 1;
    }

    // Sort tasks by arrival time
    qsort(tasks, n, sizeof(task), compare_arrival);

    // Round-robin scheduling
    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    round_robin(tasks, n, quantum);

    return 0;
}