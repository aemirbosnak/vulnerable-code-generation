//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#define MAX_CPU_TIME 30
#define MIN_CPU_TIME 5

struct Process {
    int pid;
    int priority;
    int cpu_time;
    int arrival_time;
    int waiting_time;
};

void generate_processes(struct Process *process_list, int count) {
    srand(time(NULL));
    for(int i = 0; i < count; i++) {
        process_list[i].pid = i;
        process_list[i].priority = rand() % (MAX_PRIORITY - MIN_PRIORITY + 1) + MIN_PRIORITY;
        process_list[i].cpu_time = rand() % (MAX_CPU_TIME - MIN_CPU_TIME + 1) + MIN_CPU_TIME;
        process_list[i].arrival_time = rand() % (count * 2);
    }
}

void print_process_list(struct Process *process_list, int count) {
    printf("\nPID\tPriority\tCPU Time\tArrival Time\tWaiting Time\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", process_list[i].pid, process_list[i].priority, process_list[i].cpu_time, process_list[i].arrival_time, process_list[i].waiting_time);
    }
}

void fifo(struct Process *process_list, int count) {
    printf("\nFIFO Algorithm:\n");
    int current_time = 0;
    for(int i = 0; i < count; i++) {
        process_list[i].waiting_time = current_time - process_list[i].arrival_time;
        current_time += process_list[i].cpu_time;
    }
    print_process_list(process_list, count);
}

void sjf(struct Process *process_list, int count) {
    printf("\nSJF Algorithm:\n");
    int current_time = 0;
    for(int i = 0; i < count; i++) {
        int shortest = -1;
        for(int j = 0; j < count; j++) {
            if(process_list[j].arrival_time <= current_time && process_list[j].cpu_time > 0) {
                if(shortest == -1 || process_list[j].cpu_time < process_list[shortest].cpu_time) {
                    shortest = j;
                }
            }
        }
        process_list[shortest].waiting_time = current_time - process_list[shortest].arrival_time;
        current_time += process_list[shortest].cpu_time;
        process_list[shortest].cpu_time = 0;
    }
    print_process_list(process_list, count);
}

void priority(struct Process *process_list, int count) {
    printf("\nPriority Algorithm:\n");
    int current_time = 0;
    for(int i = 0; i < count; i++) {
        int highest = -1;
        for(int j = 0; j < count; j++) {
            if(process_list[j].arrival_time <= current_time && process_list[j].cpu_time > 0) {
                if(highest == -1 || process_list[j].priority > process_list[highest].priority) {
                    highest = j;
                }
            }
        }
        process_list[highest].waiting_time = current_time - process_list[highest].arrival_time;
        current_time += process_list[highest].cpu_time;
        process_list[highest].cpu_time = 0;
    }
    print_process_list(process_list, count);
}

int main() {
    int count = 5;
    struct Process process_list[count];
    generate_processes(process_list, count);
    print_process_list(process_list, count);

    fifo(process_list, count);
    sjf(process_list, count);
    priority(process_list, count);

    return 0;
}