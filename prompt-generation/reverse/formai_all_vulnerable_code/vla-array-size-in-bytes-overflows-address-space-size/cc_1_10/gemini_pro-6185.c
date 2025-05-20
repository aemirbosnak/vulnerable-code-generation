//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void print_gantt_chart(Process *processes, int n) {
    int current_time = 0;
    int i;

    printf("Gantt Chart:\n");
    printf("--------------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        if(processes[i].arrival_time > current_time) {
            printf("| Idle |");
            current_time = processes[i].arrival_time;
        }

        printf("| P%d (%d) |", i + 1, processes[i].burst_time);
        current_time += processes[i].burst_time;
    }

    printf("\n--------------------------------------------------------------------------------\n");
}

void print_statistics(Process *processes, int n) {
    int i;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for(i = 0; i < n; i++) {
        avg_waiting_time += processes[i].remaining_time - processes[i].burst_time;
        avg_turnaround_time += processes[i].remaining_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;
    int i;
    int time_quantum;
    int total_time = 0;
    int queue[100];
    int head = 0;
    int tail = 0;
    int counter = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    for(i = 0; i < n; i++) {
        if(processes[i].arrival_time <= total_time) {
            queue[tail] = i;
            tail = (tail + 1) % 100;
            counter++;
        }
    }

    while(counter > 0) {
        int process = queue[head];
        head = (head + 1) % 100;
        counter--;

        if(processes[process].remaining_time <= time_quantum) {
            total_time += processes[process].remaining_time;
            processes[process].remaining_time = 0;
        } else {
            processes[process].remaining_time -= time_quantum;
            total_time += time_quantum;
            queue[tail] = process;
            tail = (tail + 1) % 100;
            counter++;
        }

        for(i = 0; i < n; i++) {
            if(processes[i].arrival_time <= total_time && processes[i].remaining_time > 0) {
                queue[tail] = i;
                tail = (tail + 1) % 100;
                counter++;
            }
        }
    }

    print_gantt_chart(processes, n);
    print_statistics(processes, n);

    return 0;
}