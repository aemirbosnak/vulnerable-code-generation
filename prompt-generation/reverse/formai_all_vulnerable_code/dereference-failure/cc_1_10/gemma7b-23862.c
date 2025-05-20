//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    int waiting_time;
    struct Process* next;
} Process;

void roundrobin(Process* head) {
    Process* current = head;
    while (current) {
        current->waiting_time++;
        current = current->next;
    }
    current = head;
    while (current) {
        current->completion_time = current->arrival_time + current->service_time;
        current = current->next;
    }
}

int main() {
    Process* head = NULL;
    int i, time = 0, processes = 0;

    // Allocate memory for processes
    for (i = 0; i < MAX_PROCESSES; i++) {
        head = (Process*)malloc(sizeof(Process));
        head->next = NULL;
        processes++;
        head = head->next;
    }

    // Generate arrival and service times for each process
    for (i = 0; i < processes; i++) {
        head->arrival_time = rand() % MAX_QUEUE_SIZE;
        head->service_time = rand() % MAX_QUEUE_SIZE;
        head = head->next;
    }

    // Round robin scheduling algorithm
    roundrobin(head);

    // Print completion time for each process
    for (i = 0; i < processes; i++) {
        printf("Process ID: %d, Completion Time: %d\n", head->process_id, head->completion_time);
        head = head->next;
    }

    return 0;
}