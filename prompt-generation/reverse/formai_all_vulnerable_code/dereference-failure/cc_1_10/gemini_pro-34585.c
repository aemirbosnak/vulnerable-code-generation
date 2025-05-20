//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a process
typedef struct Process {
    int pid;        // Process ID
    int arrival_time;    // Arrival time of the process
    int burst_time;     // Burst time of the process
    int remaining_time; // Remaining time of the process
    int priority;    // Priority of the process
} Process;

// Structure to represent a node in a linked list
typedef struct Node {
    Process process;    // Process data
    struct Node *next;    // Pointer to the next node
} Node;

// Function to create a new process
Process *create_process(int pid, int arrival_time, int burst_time, int priority) {
    Process *process = (Process *)malloc(sizeof(Process));
    process->pid = pid;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->priority = priority;
    return process;
}

// Function to create a new node in a linked list
Node *create_node(Process *process) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->process = *process;
    node->next = NULL;
    return node;
}

// Function to insert a node into a linked list in ascending order of arrival time
void insert_node(Node **head, Node *node) {
    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && current->process.arrival_time <= node->process.arrival_time) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head = node;
        node->next = current;
    } else {
        previous->next = node;
        node->next = current;
    }
}

// Function to schedule processes using the First-Come, First-Served (FCFS) algorithm
void fcfs(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("Process %d executed for %d units of time\n", current->process.pid, current->process.burst_time);
        current = current->next;
    }
}

// Function to schedule processes using the Shortest Job First (SJF) algorithm
void sjf(Node *head) {
    Node *current = head;
    Node *shortest_job = NULL;

    while (current != NULL) {
        if (shortest_job == NULL || shortest_job->process.burst_time > current->process.burst_time) {
            shortest_job = current;
        }
        current = current->next;
    }

    printf("Process %d executed for %d units of time\n", shortest_job->process.pid, shortest_job->process.burst_time);
    head = shortest_job->next;
    free(shortest_job);
    sjf(head);
}

// Function to schedule processes using the Priority algorithm
void priority(Node *head) {
    Node *current = head;
    Node *highest_priority = NULL;

    while (current != NULL) {
        if (highest_priority == NULL || highest_priority->process.priority > current->process.priority) {
            highest_priority = current;
        }
        current = current->next;
    }

    printf("Process %d executed for %d units of time\n", highest_priority->process.pid, highest_priority->process.burst_time);
    head = highest_priority->next;
    free(highest_priority);
    priority(head);
}

// Function to schedule processes using the Round Robin (RR) algorithm
void rr(Node *head, int time_quantum) {
    Node *current = head;
    int time_elapsed = 0;

    while (current != NULL) {
        if (current->process.remaining_time <= time_quantum) {
            printf("Process %d executed for %d units of time\n", current->process.pid, current->process.remaining_time);
            time_elapsed += current->process.remaining_time;
            current->process.remaining_time = 0;
            current = current->next;
        } else {
            printf("Process %d executed for %d units of time\n", current->process.pid, time_quantum);
            time_elapsed += time_quantum;
            current->process.remaining_time -= time_quantum;
            current = current->next;
            if (current == NULL) {
                current = head;
            }
        }
    }
}

// Main function
int main() {
    // Create a linked list of processes
    Node *head = NULL;
    insert_node(&head, create_node(create_process(1, 0, 5, 1)));
    insert_node(&head, create_node(create_process(2, 2, 3, 2)));
    insert_node(&head, create_node(create_process(3, 4, 4, 3)));
    insert_node(&head, create_node(create_process(4, 6, 2, 4)));
    insert_node(&head, create_node(create_process(5, 8, 1, 5)));

    // Print the original linked list
    printf("Original linked list:\n");
    Node *current = head;
    while (current != NULL) {
        printf("Process %d: arrival time %d, burst time %d, remaining time %d, priority %d\n", current->process.pid, current->process.arrival_time, current->process.burst_time, current->process.remaining_time, current->process.priority);
        current = current->next;
    }

    // Schedule the processes using the FCFS algorithm
    printf("\nFCFS scheduling:\n");
    fcfs(head);

    // Schedule the processes using the SJF algorithm
    printf("\nSJF scheduling:\n");
    sjf(head);

    // Schedule the processes using the Priority algorithm
    printf("\nPriority scheduling:\n");
    priority(head);

    // Schedule the processes using the RR algorithm with a time quantum of 2
    printf("\nRR scheduling with a time quantum of 2:\n");
    rr(head, 2);

    return 0;
}