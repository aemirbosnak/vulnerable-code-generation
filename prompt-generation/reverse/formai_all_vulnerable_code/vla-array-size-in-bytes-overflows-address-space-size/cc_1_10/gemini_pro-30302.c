//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
} Process;

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;

        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    int completed = 0, time = 0;
    while (completed < n) {
        int highest_priority = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (highest_priority == -1 || processes[i].priority > processes[highest_priority].priority) {
                    highest_priority = i;
                }
            }
        }

        if (highest_priority == -1) {
            time++;
            continue;
        }

        processes[highest_priority].remaining_time--;
        time++;

        if (processes[highest_priority].remaining_time == 0) {
            completed++;
            printf("Process %d completed at time %d\n", highest_priority + 1, time);
        }
    }

    return 0;
}