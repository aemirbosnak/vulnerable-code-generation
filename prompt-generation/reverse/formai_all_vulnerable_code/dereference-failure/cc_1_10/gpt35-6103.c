//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// defining structures
typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

typedef struct queue {
    Process *process;
    struct queue *next;
} Queue;

// global variables
Queue *ready_queue = NULL;
int current_time = 0;

// function to create a new process
Process *create_process(int pid, int arrival_time, int burst_time, int priority) {
    Process *new_process = malloc(sizeof(Process));
    new_process->pid = pid;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->priority = priority;
    return new_process;
}

// function to add a process to the ready queue
void add_to_ready_queue(Process *new_process) {
    Queue *new_node = malloc(sizeof(Queue));
    new_node->process = new_process;
    new_node->next = NULL;

    if (ready_queue == NULL) {
        ready_queue = new_node;
    } else {
        Queue *current_node = ready_queue;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// function to remove a process from the ready queue
Process *remove_from_ready_queue() {
    if (ready_queue == NULL) {
        return NULL;
    } else {
        Process *to_return = ready_queue->process;
        ready_queue = ready_queue->next;
        return to_return;
    }
}

// function to sort the ready queue by priority
void sort_ready_queue_by_priority() {
    if (ready_queue == NULL || ready_queue->next == NULL) {
        return;
    }

    Queue *current_node = ready_queue;
    Queue *previous_node = NULL;
    int swapped = 1;

    while (swapped) {
        swapped = 0;
        while (current_node->next != NULL) {
            if (current_node->process->priority > current_node->next->process->priority) {
                Queue *temp = current_node->next;
                current_node->next = current_node->next->next;
                temp->next = current_node;

                if (previous_node == NULL) {
                    ready_queue = temp;
                } else {
                    previous_node->next = temp;
                }

                previous_node = temp;
                swapped = 1;
            } else {
                previous_node = current_node;
                current_node = current_node->next;
            }
        }
    }
}

// function to print the ready queue
void print_ready_queue() {
    printf("Ready Queue:\n");
    Queue *current_node = ready_queue;
    while (current_node != NULL) {
        printf("PID: %d, Arrival Time: %d, Burst Time: %d, Priority: %d\n", current_node->process->pid, current_node->process->arrival_time, current_node->process->burst_time, current_node->process->priority);
        current_node = current_node->next;
    }
}

// function to run the First Come First Serve scheduling algorithm
void fcfs(Process **processes, int num_processes) {
    printf("First Come First Serve Scheduling Algorithm\n");

    for (int i = 0; i < num_processes; i++) {
        while (current_time < processes[i]->arrival_time) {
            printf("Time: %d, CPU idle\n", current_time);
            current_time++;
        }

        printf("Time: %d, Process %d running\n", current_time, processes[i]->pid);

        while (processes[i]->burst_time > 0) {
            current_time++;
            processes[i]->burst_time--;
            printf("Time: %d, Process %d running\n", current_time, processes[i]->pid);
        }

        printf("Time: %d, Process %d finished\n", current_time, processes[i]->pid);
    }

    printf("All processes finished\n");
}

// function to run the Preemptive Priority scheduling algorithm
void priority(Process **processes, int num_processes) {
    printf("Preemptive Priority Scheduling Algorithm\n");

    for (int i = 0; i < num_processes; i++) {
        while (current_time < processes[i]->arrival_time) {
            printf("Time: %d, CPU idle\n", current_time);
            current_time++;
        }

        add_to_ready_queue(processes[i]);

        while (ready_queue != NULL) {
            sort_ready_queue_by_priority();
            Process *current_process = remove_from_ready_queue();

            printf("Time: %d, Process %d running\n", current_time, current_process->pid);

            while (current_process->burst_time > 0) {
                current_time++;
                current_process->burst_time--;

                for (int j = i + 1; j < num_processes; j++) {
                    if (processes[j]->arrival_time <= current_time) {
                        add_to_ready_queue(processes[j]);
                        i++;
                    }
                }

                if (ready_queue != NULL && ready_queue->process->priority < current_process->priority) {
                    printf("Time: %d, Process %d preempted by Process %d\n", current_time, current_process->pid, ready_queue->process->pid);
                    add_to_ready_queue(current_process);
                    break;
                }
                printf("Time: %d, Process %d running\n", current_time, current_process->pid);
            }
            printf("Time: %d, Process %d finished\n", current_time, current_process->pid);
        }
    }

    printf("All processes finished\n");
}

int main() {
    Process *processes[4];
    processes[0] = create_process(1, 0, 5, 2);
    processes[1] = create_process(2, 1, 3, 3);
    processes[2] = create_process(3, 2, 4, 1);
    processes[3] = create_process(4, 3, 2, 4);

    fcfs(processes, 4);

    current_time = 0;
    ready_queue = NULL;

    priority(processes, 4);

    return 0;
}