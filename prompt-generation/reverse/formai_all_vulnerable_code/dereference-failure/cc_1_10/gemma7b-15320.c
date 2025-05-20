//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    int completionTime;
    struct Process* next;
} Process;

void simulateRoundRobin(Process* head) {
    int currentProcessor = 0;
    int time = head->arrivalTime;

    while (head) {
        if (time >= head->arrivalTime && head->processingTime > 0) {
            head->completionTime = time;
            printf("Process %d completed at time %d\n", head->id, head->completionTime);
            head->processingTime--;
        } else {
            currentProcessor = (currentProcessor + 1) % MAX_PROCESSORS;
            time++;
        }
        head = head->next;
    }
}

int main() {
    Process* head = NULL;
    Process* process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->arrivalTime = 0;
    process1->processingTime = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->arrivalTime = 2;
    process2->processingTime = 3;

    Process* process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->arrivalTime = 4;
    process3->processingTime = 2;

    head = process1;
    head->next = process2;
    head->next->next = process3;

    simulateRoundRobin(head);

    return 0;
}