//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

void roundrobin(Process* head) {
    Process* current_process = head;
    int i = 0;

    while (current_process) {
        if (i % MAX_PROCESSORS == 0) {
            printf("Process %d started at time %d\n", current_process->process_id, time(NULL));
        }
        current_process->execution_time--;
        i++;

        if (current_process->execution_time == 0) {
            printf("Process %d completed at time %d\n", current_process->process_id, time(NULL));
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->execution_time = 5;
    process1->next = NULL;

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->execution_time = 3;
    process2->next = NULL;

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 4;
    process3->execution_time = 2;
    process3->next = NULL;

    head = process1;
    process1->next = process2;
    process2->next = process3;

    roundrobin(head);

    return 0;
}