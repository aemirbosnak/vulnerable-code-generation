//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the maximum size of the queue
#define MAX_SIZE 100

// structure for representing a process
typedef struct Process {
    int process_id;     // unique identifier for the process
    int arrival_time;   // time when the process arrives
    int burst_time;     // time required by the process to complete
    int priority;       // priority of the process
} Process;

// structure for representing a node in the queue
typedef struct QueueNode {
    Process* process;   // pointer to the process represented by the node
    struct QueueNode* next;     // pointer to the next node in the queue
} QueueNode;

// structure for representing a queue
typedef struct {
    QueueNode* front;   // pointer to the front of the queue
    QueueNode* rear;    // pointer to the rear of the queue
    int size;           // current size of the queue
} Queue;

// function for creating a process
Process* create_process(int process_id, int arrival_time, int burst_time, int priority) {
    Process* process = (Process*) malloc(sizeof(Process));
    process->process_id = process_id;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->priority = priority;
    return process;
}

// function for creating a new node in the queue
QueueNode* create_queue_node(Process* process) {
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    node->process = process;
    node->next = NULL;
    return node;
}

// function for creating a new queue
Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// function for checking if the queue is empty
bool is_empty(Queue* queue) {
    return queue->size == 0;
}

// function for adding a process to the queue based on its priority
void add_process(Queue* queue, Process* process) {
    QueueNode* node = create_queue_node(process);

    if (is_empty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        QueueNode* current = queue->front;
        QueueNode* previous = NULL;

        while (current != NULL && current->process->priority >= process->priority) {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) {
            node->next = queue->front;
            queue->front = node;
        } else if (current == NULL) {
            queue->rear->next = node;
            queue->rear = node;
        } else {
            node->next = current;
            previous->next = node;
        }
    }

    queue->size++;
}

// function for removing the first process from the queue
Process* remove_process(Queue* queue) {
    if (is_empty(queue)) {
        return NULL;
    }

    QueueNode* node = queue->front;
    Process* process = node->process;
    
    if (queue->size == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = node->next;
    }

    free(node);
    queue->size--;
    return process;
}

// function for running the priority scheduling algorithm
void priority_scheduling(Process* processes[], int num_processes) {
    Queue* queue = create_queue();
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (true) {
        // check if there are any processes that have arrived
        bool no_more_processes = true;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i]->arrival_time <= current_time && processes[i]->burst_time > 0) {
                add_process(queue, processes[i]);
                no_more_processes = false;
            }
        }

        if (no_more_processes && is_empty(queue)) {
            break;
        }

        Process* current_process = remove_process(queue);

        // run the current process for 1 time unit
        current_process->burst_time--;
        current_time++;

        // check if the current process has finished
        if (current_process->burst_time == 0) {
            total_waiting_time += current_time - current_process->arrival_time - current_process->burst_time;
            total_turnaround_time += current_time - current_process->arrival_time;
        } else {
            add_process(queue, current_process);
        }
    }

    // print the average waiting time and turnaround time
    printf("Average waiting time: %f\n", total_waiting_time / (float) num_processes);
    printf("Average turnaround time: %f\n", total_turnaround_time / (float) num_processes);
}

int main() {
    // create some sample processes
    Process* process1 = create_process(1, 0, 6, 3);
    Process* process2 = create_process(2, 2, 4, 1);
    Process* process3 = create_process(3, 4, 3, 2);

    // put the processes into an array
    Process* processes[] = {process1, process2, process3};
    int num_processes = sizeof(processes) / sizeof(Process*);

    // run the priority scheduling algorithm
    priority_scheduling(processes, num_processes);

    // free the memory allocated for the processes
    free(process1);
    free(process2);
    free(process3);

    return 0;
}