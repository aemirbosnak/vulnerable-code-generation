//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// process struct contains process number, burst time, and waiting time
struct process {
    int process_num;
    int burst_time;
    int waiting_time;
};

// function to sort processes in ascending order based on burst time using bubble sort algorithm
void sort_processes(struct process p[], int n) {
    int i, j;
    struct process temp;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// function to calculate waiting time of processes using SJF scheduling algorithm
void sjf(struct process p[], int n) {
    int i, j;
    float avg_waiting_time = 0;

    // sort processes in ascending order based on burst time
    sort_processes(p, n);

    // calculate waiting time of each process
    for (i = 0; i < n; i++) {
        p[i].waiting_time = 0;
        for (j = 0; j < i; j++) {
            p[i].waiting_time += p[j].burst_time;
        }
        avg_waiting_time += p[i].waiting_time;
    }

    // print details of each process
    printf("Process\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", p[i].process_num, p[i].burst_time, p[i].waiting_time);
    }

    // calculate and print average waiting time
    avg_waiting_time /= n;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

int main() {
    int i, n;
    struct process *p;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // allocate memory for n processes
    p = (struct process*) malloc(n * sizeof(struct process));

    // get details of each process from user
    for (i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].process_num = i+1;
    }

    // calculate waiting time of processes using SJF scheduling algorithm
    sjf(p, n);

    // free allocated memory
    free(p);

    return 0;
}