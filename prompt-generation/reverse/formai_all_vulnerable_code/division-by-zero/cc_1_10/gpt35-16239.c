//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>

// defining a struct for processes
struct process {
    char name[10];
    int arrival_time;
    int burst_time;
    int priority;
} p[10], temp;

// defining a function to sort processes by their arrival time
void sort_by_arrival(int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (p[j].arrival_time < p[i].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n, total_time = 0, avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // taking input for each process
    for (int i=0; i<n; i++) {
        printf("Enter the details for process %d:\n", i+1);
        printf("Name: ");
        scanf("%s", &p[i].name);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        total_time += p[i].burst_time;
    }

    // sorting processes by their arrival time
    sort_by_arrival(n);

    // implementing priority scheduling
    for (int i=0; i<total_time; i++) {
        int highest_priority_process = -1, highest_priority = -1;
        for (int j=0; j<n; j++) {
            if (p[j].arrival_time <= i && p[j].burst_time > 0) {
                if (p[j].priority > highest_priority) {
                    highest_priority = p[j].priority;
                    highest_priority_process = j;
                }
            }
        }
        p[highest_priority_process].burst_time--;

        if (p[highest_priority_process].burst_time == 0) {
            int turnaround_time = i + 1 - p[highest_priority_process].arrival_time;
            int wait_time = turnaround_time - p[highest_priority_process].burst_time;
            avg_turnaround_time += turnaround_time;
            avg_wait_time += wait_time;
            printf("Process %s has finished at time %d. Turnaround time: %d, Wait time: %d\n", p[highest_priority_process].name, i+1, turnaround_time, wait_time);
        }
    }

    // printing average turnaround and wait time
    avg_turnaround_time /= n;
    avg_wait_time /= n;
    printf("Average turnaround time: %d\nAverage wait time: %d\n", avg_turnaround_time, avg_wait_time);

    return 0;
}