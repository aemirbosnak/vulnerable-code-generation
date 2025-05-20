//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for linked list
typedef struct node {
    int pid;
    struct node* next;
} Node;

// Linked list for storing processes
Node* head = NULL;

// Function to add a process to the linked list
void add_process(int pid) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->pid = pid;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to execute a process
void execute_process(int pid) {
    printf("Executing process %d\n", pid);
    sleep(1); // Simulate execution time
}

// Function to schedule processes using Round Robin scheduling algorithm
void schedule_processes() {
    int quantum = 2; // Time slice for each process
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < 5) { // Assume 5 processes need to be executed
        Node* temp = head;
        while (temp!= NULL) {
            if (temp->pid == completed_processes) {
                execute_process(temp->pid);
                completed_processes++;
            }
            temp = temp->next;
        }

        current_time += quantum;
        sleep(quantum);
    }
}

int main() {
    int i;

    // Add processes to the linked list
    for (i = 1; i <= 5; i++) {
        add_process(i);
    }

    // Schedule processes using Round Robin scheduling algorithm
    schedule_processes();

    return 0;
}