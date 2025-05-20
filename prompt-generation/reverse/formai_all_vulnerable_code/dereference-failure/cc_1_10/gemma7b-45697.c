//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_PROCESSORS 4
#define MAX_NUMBER_OF_PROCESSES 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    struct Process* next;
} Process;

void roundRobin(Process* head) {
    int current_processor = 0;
    Process* current_process = head;

    while (current_process) {
        if (current_process->arrival_time <= current_processor) {
            printf("Process %d is running on Processor %d\n", current_process->process_id, current_processor);
            current_process->burst_time--;
            if (current_process->burst_time == 0) {
                current_process = current_process->next;
            }
        } else {
            current_processor++;
        }
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->burst_time = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->burst_time = 4;

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 3;
    process3->burst_time = 3;

    Process* process4 = malloc(sizeof(Process));
    process4->process_id = 4;
    process4->arrival_time = 4;
    process4->burst_time = 2;

    // Add the processes to the linked list
    head = process1;
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;

    // Round robin scheduling
    roundRobin(head);

    return 0;
}