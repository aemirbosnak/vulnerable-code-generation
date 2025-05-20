//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_CPU_TIME 1000

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int num_processes, i;
    int quantum = 2; // Time slice for each process
    int current_time = 0;
    int completed_processes = 0;
    struct process *process_table = (struct process*) malloc(MAX_PROCESSES * sizeof(struct process));

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for(i=0; i<num_processes; i++) {
        printf("Enter the details of process %d:\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &process_table[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &process_table[i].burst_time);
    }

    printf("\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while(completed_processes < num_processes) {
        int shortest_burst = MAX_CPU_TIME;
        int shortest_index = -1;

        for(i=0; i<num_processes; i++) {
            if(process_table[i].arrival_time <= current_time && process_table[i].burst_time <= shortest_burst) {
                shortest_burst = process_table[i].burst_time;
                shortest_index = i;
            }
        }

        if(shortest_index!= -1) {
            current_time += shortest_burst;
            process_table[shortest_index].waiting_time = current_time - process_table[shortest_index].arrival_time - process_table[shortest_index].burst_time;
            process_table[shortest_index].turnaround_time = process_table[shortest_index].waiting_time + process_table[shortest_index].burst_time;
            completed_processes++;
        } else {
            current_time++;
        }
    }

    printf("\n\nProcess\tID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0; i<num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, process_table[i].id, process_table[i].arrival_time, process_table[i].burst_time, process_table[i].waiting_time, process_table[i].turnaround_time);
    }

    return 0;
}