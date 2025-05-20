//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process procs[], int n, int quantum) {
    int remaining_burst[n];
    for (int i = 0; i < n; i++)
        remaining_burst[i] = procs[i].burst_time;

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0; // There is a pending process
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    procs[i].waiting_time = time - procs[i].burst_time;
                    remaining_burst[i] = 0;
                }
            }
        }
        if (done == 1) break; // All processes are done
    }
}

void calculate_turnaround_time(Process procs[], int n) {
    for (int i = 0; i < n; i++)
        procs[i].turnaround_time = procs[i].burst_time + procs[i].waiting_time;
}

void print_processes(Process procs[], int n) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
            procs[i].process_id, 
            procs[i].burst_time, 
            procs[i].waiting_time, 
            procs[i].turnaround_time);
}

void round_robin(Process procs[], int n, int quantum) {
    calculate_waiting_time(procs, n, quantum);
    calculate_turnaround_time(procs, n);
    print_processes(procs, n);
}

int main() {
    int n;
    int quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process* procs = malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        procs[i].process_id = i + 1; // Process IDs start from 1
        printf("Enter burst time for process %d: ", procs[i].process_id);
        scanf("%d", &procs[i].burst_time);
        procs[i].waiting_time = 0; // Initialize waiting time
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    round_robin(procs, n, quantum);

    free(procs);
    return 0;
}