//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void roundrobin(Process* head) {
    Process* current = head;
    while (current) {
        printf("Process %d: ", current->pid);
        sleep(current->remaining_time);
        current->remaining_time--;
        if (current->remaining_time == 0) {
            printf("Completed\n");
            current = current->next;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->pid = i + 1;
        sprintf(newProcess->name, "Process %d", i + 1);
        newProcess->burst_time = rand() % MAX_QUEUE_SIZE;
        newProcess->remaining_time = newProcess->burst_time;
        newProcess->next = NULL;

        if (head == NULL) {
            head = newProcess;
            tail = newProcess;
        } else {
            tail->next = newProcess;
            tail = newProcess;
        }
    }

    // Round robin scheduling
    roundrobin(head);

    return 0;
}