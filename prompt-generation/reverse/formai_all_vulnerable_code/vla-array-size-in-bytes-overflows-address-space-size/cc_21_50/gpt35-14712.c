//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PROCESSES 1000
#define MAX_PRIORITY 10

int main() {
    int i, j, total_time = 0;
    float avg_wait_time = 0.0, avg_turnaround_time = 0.0;
    int bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES], pr[MAX_PROCESSES];
    int n = 0, time_quantum, priority_levels, random_priority;

    // seed random number generator
    srand(time(0));

    // welcome message
    printf("Welcome to the C System Boot Optimizer\n\n");

    // get user input
    printf("How many processes would you like to run? ");
    scanf("%d", &n);
    printf("Enter the time quantum for the Round Robin scheduler: ");
    scanf("%d", &time_quantum);
    printf("Enter the number of priority levels for the Priority Queue scheduler: ");
    scanf("%d", &priority_levels);

    // initialize burst times and priorities
    for (i = 0; i < n; i++) {
        bt[i] = rand() % 20 + 1; // random burst time between 1 and 20 seconds
        random_priority = rand() % priority_levels + 1; // random priority level between 1 and number of priority levels
        pr[i] = random_priority;
    }

    // print process information
    printf("\nProcess\tBurst Time\tPriority Level\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i+1, bt[i], pr[i]);
    }

    // Round Robin scheduler
    printf("\nRunning Round Robin scheduler with time quantum of %d seconds...\n", time_quantum);
    int rem_bt[n];
    for (i = 0 ; i < n ; i++) {
        rem_bt[i] =  bt[i];
    }
    int t = 0; // current time
    while (1) {
        int done = 1;
        for (i = 0 ; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > time_quantum) {
                    t += time_quantum;
                    rem_bt[i] -= time_quantum;
                }
                else {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }

    // calculate average wait time and turnaround time for Round Robin scheduler
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_time += tat[i];
    }
    avg_wait_time = (float) total_time / n;
    avg_turnaround_time = (float) total_time / n;
    printf("\nRound Robin scheduler results:\n");
    printf("Average wait time: %.2f seconds\n", avg_wait_time);
    printf("Average turnaround time: %.2f seconds\n", avg_turnaround_time);

    // Priority Queue scheduler
    printf("\nRunning Priority Queue scheduler with %d priority levels...\n", priority_levels);
    int time = 0, k, min;
    for (i = 0; i < n; i++) {
        wt[i] = 0;
    }
    while (1) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && pr[i] >= priority_levels/2) {
                flag = 1;
                if (rem_bt[i] > time_quantum) {
                    wt[i] += time_quantum;
                    rem_bt[i] -= time_quantum;
                }
                else {
                    wt[i] += rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag == 0) {
            break;
        }
    }
    while (1) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && pr[i] < priority_levels/2) {
                flag = 1;
                if (rem_bt[i] > time_quantum) {
                    wt[i] += time_quantum;
                    rem_bt[i] -= time_quantum;
                }
                else {
                    wt[i] += rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag == 0) {
            break;
        }
    }
    // calculate average wait time and turnaround time for Priority Queue scheduler
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_time += tat[i];
    }
    avg_wait_time = (float) total_time / n;
    avg_turnaround_time = (float) total_time / n;
    printf("\nPriority Queue scheduler results:\n");
    printf("Average wait time: %.2f seconds\n", avg_wait_time);
    printf("Average turnaround time: %.2f seconds\n", avg_turnaround_time);

    return 0;
}