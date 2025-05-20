//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n, q;

    printf("Enter the number of processes to schedule: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);

        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }

    printf("Enter the quantum time: ");
    scanf("%d", &q);

    int time = 0;
    int done = 0;

    while (done != n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                if (p[i].remaining_time <= q) {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    done++;
                }
                else {
                    time += q;
                    p[i].remaining_time -= q;
                }
            }
        }
    }

    float total_turnaround_time = 0;
    float total_waiting_time = 0;

    printf("PID\tArrival-Time\tBurst-Time\tCompletion-Time\tTurnaround-Time\tWaiting-Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
    }

    printf("Average Turnaround Time: %f\n", total_turnaround_time / n);
    printf("Average Waiting Time: %f\n", total_waiting_time / n);

    return 0;
}