//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 10
#define MAX_SCHEDULE_SIZE 10

typedef struct process {
    int id;
    int burst_time;
    struct process* next;
} process;

process* create_process(int id, int burst_time) {
    process* p = (process*)malloc(sizeof(process));
    p->id = id;
    p->burst_time = burst_time;
    p->next = NULL;
    return p;
}

void round_robin(process* ready_queue) {
    process* current_process = ready_queue;
    while (current_process) {
        printf("Process %d is running...\n", current_process->id);
        sleep(current_process->burst_time);
        current_process = current_process->next;
    }
}

int main() {
    process* head = NULL;
    process* tail = NULL;
    process* ready_queue = NULL;

    // Create a few processes
    process* p1 = create_process(1, 5);
    process* p2 = create_process(2, 3);
    process* p3 = create_process(3, 2);

    // Add processes to the queue
    if (head == NULL) {
        head = p1;
        tail = p1;
    } else {
        tail->next = p1;
        tail = p1;
    }

    // Add processes to the ready queue
    if (ready_queue == NULL) {
        ready_queue = p1;
    } else {
        ready_queue->next = p1;
        ready_queue = p1;
    }

    // Round robin scheduling
    round_robin(ready_queue);

    return 0;
}