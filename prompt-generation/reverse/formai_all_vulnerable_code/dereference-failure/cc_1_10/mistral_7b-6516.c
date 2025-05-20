//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    int pid;
    char name[20];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process *next;
} Process;

void create_processes(Process **head, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        Process *new_process = (Process *)malloc(sizeof(Process));
        scanf("%s %d %d", new_process->name, &new_process->arrival_time, &new_process->burst_time);
        new_process->pid = i + 1;
        new_process->next = NULL;
        if (*head == NULL) {
            *head = new_process;
        } else {
            Process *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_process;
        }
    }
}

void round_robin_scheduling(Process *processes, int num_processes, int quantum) {
    Process *ready_queue = NULL;
    Process *current = NULL;
    int time = 0;
    int completed = 0;

    while (completed < num_processes) {
        if (current == NULL) {
            if (ready_queue == NULL) {
                current = processes;
                while (current->arrival_time <= time && current != NULL) {
                    current = current->next;
                }
                if (current != NULL) {
                    ready_queue = processes;
                    processes = processes->next;
                    current->next = ready_queue;
                }
            } else {
                current = ready_queue;
                ready_queue = current->next;
            }
        }

        if (current != NULL && current->burst_time > quantum) {
            current->burst_time -= quantum;
            time += quantum;
            current->next = ready_queue;
            ready_queue = current;
            current = NULL;
        } else {
            time += current->burst_time;
            current->waiting_time = current->turnaround_time = time - current->arrival_time;
            completed++;
        }
    }

    printf("\nProcess ID\tName\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (Process *temp = processes; temp != NULL; temp = temp->next) {
        printf("\n%d\t%s\t%d\t%d\t%d\t%d", temp->pid, temp->name, temp->arrival_time, temp->burst_time, temp->waiting_time, temp->turnaround_time);
    }
}

int main() {
    int num_processes, quantum;
    scanf("%d %d", &num_processes, &quantum);
    Process *head = NULL;
    create_processes(&head, num_processes);
    round_robin_scheduling(head, num_processes, quantum);
    return 0;
}