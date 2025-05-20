//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
} Process;

typedef struct Node {
    Process process;
    struct Node *next;
} Node;

// Function prototypes
Node *create_process(int pid, int arrival_time, int burst_time);
void add_process(Node **head, Node *new_node);
void print_processes(Node *head);
void schedule_processes(Node *head);

// Main function
int main() {
    // Create a linked list of processes
    Node *head = NULL;
    add_process(&head, create_process(1, 0, 5));
    add_process(&head, create_process(2, 2, 3));
    add_process(&head, create_process(3, 4, 2));
    add_process(&head, create_process(4, 6, 4));

    // Print the processes
    printf("Processes:\n");
    print_processes(head);

    // Schedule the processes
    schedule_processes(head);

    return 0;
}

// Function to create a process
Node *create_process(int pid, int arrival_time, int burst_time) {
    Node *new_node = malloc(sizeof(Node));
    new_node->process.pid = pid;
    new_node->process.arrival_time = arrival_time;
    new_node->process.burst_time = burst_time;
    new_node->next = NULL;
    return new_node;
}

// Function to add a process to the linked list
void add_process(Node **head, Node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the processes
void print_processes(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d %d %d\n", current->process.pid, current->process.arrival_time, current->process.burst_time);
        current = current->next;
    }
}

// Function to schedule the processes
void schedule_processes(Node *head) {
    // Create a queue of ready processes
    Node *ready_queue = NULL;

    // Create a variable to track the current time
    int current_time = 0;

    // While there are still processes to be scheduled
    while (head != NULL || ready_queue != NULL) {
        // Check if there are any processes that have arrived at the current time
        while (head != NULL && head->process.arrival_time <= current_time) {
            add_process(&ready_queue, head);
            head = head->next;
        }

        // If there are no ready processes, increment the current time
        if (ready_queue == NULL) {
            current_time++;
            continue;
        }

        // Get the next process from the ready queue
        Node *next_process = ready_queue;
        ready_queue = ready_queue->next;

        // Execute the process
        printf("Executing process %d\n", next_process->process.pid);
        current_time += next_process->process.burst_time;

        // Free the process
        free(next_process);
    }
}