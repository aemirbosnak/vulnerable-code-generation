//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct process {
    int p_id;
    int arrival_time;
    int burst_time;
    int wait_time;
    int turnaround_time;
    int remaining_time;
};

void print_processes(struct process *ps, int n) {
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", ps[i].p_id, ps[i].arrival_time, ps[i].burst_time, ps[i].wait_time, ps[i].turnaround_time);
    }
}

int sjf_cmp(const void *a, const void *b) {
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;
    if (p1->burst_time < p2->burst_time) return -1;
    else if (p1->burst_time == p2->burst_time) return 0;
    else return 1;
}

void sjf(struct process *ps, int n) {
    qsort(ps, n, sizeof(struct process), sjf_cmp);
    int time_count = 0;
    for (int i = 0; i < n; i++) {
        ps[i].remaining_time = ps[i].burst_time;
    }
    while (1) {
        int idx = -1;
        int min_burst_time = 0x7fffffff;
        for (int i = 0; i < n; i++) {
            if (ps[i].remaining_time > 0 && ps[i].arrival_time <= time_count) {
                if (ps[i].remaining_time < min_burst_time) {
                    min_burst_time = ps[i].remaining_time;
                    idx = i;
                }
            }
        }
        if (idx == -1) break;
        ps[idx].remaining_time--;
        if (ps[idx].remaining_time == 0) {
            ps[idx].turnaround_time = time_count - ps[idx].arrival_time + 1;
            ps[idx].wait_time = ps[idx].turnaround_time - ps[idx].burst_time;
        }
        time_count++;
    }
    print_processes(ps, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *ps = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &ps[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &ps[i].burst_time);
        ps[i].p_id = i + 1;
    }
    sjf(ps, n);
}