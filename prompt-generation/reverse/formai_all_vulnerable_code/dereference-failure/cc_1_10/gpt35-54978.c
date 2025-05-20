//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struct to hold process information */
typedef struct {
    int pid; /* Process ID */
    int priority; /* Priority number */
    int burst_time; /* Time needed to complete this process */
    int remaining_time; /* Remaining time for this process */
} Process;

/* Function to initialize process information */
void init_proc(Process* p, int pid) {
    p->pid = pid;
    p->priority = rand() % 10 + 1; /* Random priority between 1 and 10 */
    p->burst_time = rand() % 20 + 1; /* Random burst time between 1 and 20 */
    p->remaining_time = p->burst_time;
}

/* Function to print process information */
void print_proc(Process* p) {
    printf("  Process %d\n", p->pid);
    printf("    Priority: %d\n", p->priority);
    printf("    Burst Time: %d\n", p->burst_time);
    printf("    Remaining Time: %d\n", p->remaining_time);
}

/* Function to select the next process in the queue */
int select_process(Process** queue, int num_procs, bool* used_procs) {
    int next_proc = -1;
    int highest_priority = -1;
    for (int i = 0; i < num_procs; i++) {
        if (!used_procs[i] && queue[i]->priority > highest_priority) {
            highest_priority = queue[i]->priority;
            next_proc = i;
        }
    }
    return next_proc;
}

int main() {
    const int num_procs = 10;
    Process* procs[num_procs];
    bool used_procs[num_procs];
    bool all_procs_done = false;

    /* Initialize process queue */
    for (int i = 0; i < num_procs; i++) {
        procs[i] = malloc(sizeof(Process));
        init_proc(procs[i], i);
        used_procs[i] = false;
    }

    /* Loop until all processes have completed */
    int curr_time = 0;
    while (!all_procs_done) {
        all_procs_done = true;
        int next_proc = select_process(procs, num_procs, used_procs);
        if (next_proc != -1) {
            all_procs_done = false;
            used_procs[next_proc] = true;
            Process* p = procs[next_proc];
            printf("Selected process %d at time %d\n", p->pid, curr_time);
            p->remaining_time--;
            if (p->remaining_time == 0) {
                printf("Process %d completed at time %d\n", p->pid, curr_time);
            }
        }
        curr_time++;
    }

    /* Clean up memory */
    for (int i = 0; i < num_procs; i++) {
        free(procs[i]);
    }

    return 0;
}