//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

void roundRobin(Process* head) {
    Process* current_process = head;
    while (current_process) {
        // Execute the process
        printf("Process %d is running...\n", current_process->process_id);
        current_process->execution_time--;

        // If the process is completed, remove it from the queue
        if (current_process->execution_time == 0) {
            Process* next_process = current_process->next;
            free(current_process);
            current_process = next_process;
        } else {
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create a few processes
    Process* process1 = (Process*)malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->execution_time = 5;
    process1->next = NULL;

    Process* process2 = (Process*)malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->execution_time = 3;
    process2->next = NULL;

    Process* process3 = (Process*)malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 4;
    process3->execution_time = 4;
    process3->next = NULL;

    // Add the processes to the queue
    if (head == NULL) {
        head = process1;
        tail = process1;
    } else {
        tail->next = process1;
        tail = process1;
    }

    tail->next = process2;
    tail = process2;

    tail->next = process3;
    tail = process3;

    // Round robin scheduling
    roundRobin(head);

    return 0;
}