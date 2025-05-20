//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_TIME 10

typedef struct Process {
    int id;
    int arrivalTime;
    int serviceTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->serviceTime = serviceTime;
    process->next = NULL;
    return process;
}

void insertProcess(Process** head, int id, int arrivalTime, int serviceTime) {
    Process* process = createProcess(id, arrivalTime, serviceTime);
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
    }
}

void schedule(Process** head) {
    time_t currentTime = time(NULL);
    Process* currentProcess = NULL;

    while (*head) {
        if (currentProcess == NULL || (*head)->arrivalTime <= currentTime) {
            currentProcess = *head;
            *head = (*head)->next;
        } else {
            break;
        }
    }

    if (currentProcess) {
        printf("Process %d is being serviced.\n", currentProcess->id);
    } else {
        printf("No processes are waiting or being serviced.\n");
    }
}

int main() {
    Process* head = NULL;

    insertProcess(&head, 1, 0, 5);
    insertProcess(&head, 3, 2, 3);
    insertProcess(&head, 2, 3, 4);
    insertProcess(&head, 4, 5, 2);
    insertProcess(&head, 5, 6, 6);

    schedule(&head);

    return 0;
}