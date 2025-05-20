//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct Process {
    int id;
    int arrivalTime;
    int serviceTime;
    struct Process* next;
} Process;

void schedule(Process* head) {
    Process* current = head;
    while (current) {
        // Calculate the process's remaining time
        int remainingTime = current->serviceTime - time(NULL) - current->arrivalTime;

        // If the remaining time is greater than the maximum time,
        // move the process to the end of the queue
        if (remainingTime > MAX_TIME) {
            Process* next = current->next;
            current->next = head;
            head = current;
            current = next;
        } else {
            // Otherwise, increment the process's completion time
            current->serviceTime = time(NULL) + remainingTime;

            // Move the process to the end of the queue
            Process* next = current->next;
            current->next = head;
            head = next;
        }
    }
}

int main() {
    // Create a list of processes
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* process = malloc(sizeof(Process));
        process->id = i;
        process->arrivalTime = rand() % MAX_TIME;
        process->serviceTime = rand() % MAX_TIME + 1;
        process->next = head;
        head = process;
    }

    // Schedule the processes
    schedule(head);

    // Print the completion time for each process
    Process* current = head;
    while (current) {
        printf("Process ID: %d, Completion Time: %d\n", current->id, current->serviceTime);
        current = current->next;
    }

    return 0;
}