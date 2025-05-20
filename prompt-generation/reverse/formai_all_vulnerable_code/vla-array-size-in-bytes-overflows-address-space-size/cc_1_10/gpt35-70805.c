//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struct for Process Data */
typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

/* Function to Compare Arrival Times For Sorting */
int compare_arrival_time (const void* a, const void* b) {
    return ((Process*)a)->arrival_time - ((Process*)b)->arrival_time;
}

/* Function to Print Gantt Chart*/
void print_gantt_chart (Process proc[], int n) {
    int i, j;

    /* Print Top Border */
    printf("+");
    for (i = 0; i < n; i++) {
        for (j = 0; j < proc[i].burst_time; j++) {
            printf("-");
        }
        printf("+");
    }

    printf("\n|");

    /* Print Process ID and Time */
    for (i = 0; i < n; i++) {
        for (j = 0; j < proc[i].burst_time - 1; j++) {
            printf(" ");
        }
        printf("%d|", proc[i].process_id);
    }

    printf("\n+");

    /* Print Bottom Borders */
    for (i = 0; i < n; i++) {
        for (j = 0; j < proc[i].burst_time; j++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");

    /* Print Time Labels */
    printf("0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < proc[i].burst_time; j++) {
            printf(" ");
        }
        if (proc[i].turnaround_time > 9) {
            printf("%d ", proc[i].turnaround_time);
        } else {
            printf("%d  ", proc[i].turnaround_time);
        }
    }
    printf("\n");
}

/* First Come First Serve Algorithm */
void FCFS (Process proc[], int n) {
    int i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    /* Sort Based on Arrival Time */
    qsort(proc, n, sizeof(Process), compare_arrival_time);

    /* Initialize Wait and Turnaround Times */
    proc[0].waiting_time = 0;
    proc[0].turnaround_time = proc[0].burst_time;

    /* Calculate Wait and Turnaround Times */
    for (i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].turnaround_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }

    /* Print Information */
    printf("\nFirst Come First Serve Algorithm\n\n");
    printf("Process ID     Burst Time     Arrival Time     Waiting Time     Turnaround Time\n");
    printf("-------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-15d%-15d%-17d%-18d%d\n", proc[i].process_id, proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time, proc[i].turnaround_time);
        avg_waiting_time += proc[i].waiting_time;
        avg_turnaround_time += proc[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2fms\nAverage Turnaround Time: %.2fms\n", avg_waiting_time, avg_turnaround_time);

    /* Print Gantt Chart */
    print_gantt_chart(proc, n);
}

/* Priority Based Scheduling Algorithm */
void PRIORITY (Process proc[], int n) {
    int i, j, k;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    bool is_completed[10] = {0};
    int curr_time = 0;
    int burst_remaining[10];
    int highest_priority_index;

    /* Initialize Burst Remaining */
    for (i = 0; i < n; i++) {
        burst_remaining[i] = proc[i].burst_time;
    }

    /* Sort Based on Priority */
    for (j = 0; j < n - 1; j++) {
        highest_priority_index = j;
        for (k = j + 1; k < n; k++) {
            if (proc[k].arrival_time <= curr_time && proc[k].burst_time > 0 && proc[k].arrival_time < proc[highest_priority_index].arrival_time) {
                highest_priority_index = k;
            }
        }
        if (highest_priority_index != j) {
            Process temp = proc[j];
            proc[j] = proc[highest_priority_index];
            proc[highest_priority_index] = temp;
        }
    }

    /* Calculate Wait and Turnaround Times */
    for (i = 0; i < n; i++) {
        if (curr_time >= proc[i].arrival_time && !is_completed[i]) {
            curr_time += burst_remaining[i];
            proc[i].turnaround_time = curr_time - proc[i].arrival_time;
            proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;

            avg_waiting_time += proc[i].waiting_time;
            avg_turnaround_time += proc[i].turnaround_time;

            burst_remaining[i] = 0;
            is_completed[i] = true;
        }
    }

    /* Print Information */
    printf("\nPriority Based Scheduling Algorithm\n\n");
    printf("Process ID     Burst Time     Arrival Time     Priority       Waiting Time     Turnaround Time\n");
    printf("------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-15d%-15d%-17d%-15d%-18d%d\n", proc[i].process_id, proc[i].burst_time, proc[i].arrival_time, proc[i].process_id, proc[i].waiting_time, proc[i].turnaround_time);
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2fms\nAverage Turnaround Time: %.2fms\n", avg_waiting_time, avg_turnaround_time);

    /* Print Gantt Chart */
    print_gantt_chart(proc, n);
}

/* Main Function */
int main () {
    int i, n;

    /* Get Number of Processes */
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    /* Get Process Information */
    for (i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &proc[i].process_id);
        printf("Enter Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &proc[i].burst_time);
    }

    /* Choose CPU Scheduling Algorithm */
    int option;
    printf("\nChoose CPU Scheduling Algorithm -");
    printf("\n1. First Come First Serve");
    printf("\n2. Priority Based Scheduling");
    printf("\nEnter option: ");
    scanf("%d", &option);

    /* Call Respective Algorithm Function */
    switch (option) {
        case 1:
            FCFS(proc, n);
            break;
        case 2:
            PRIORITY(proc, n);
            break;
        default:
            printf("\nInvalid Option");
    }

    return 0;
}