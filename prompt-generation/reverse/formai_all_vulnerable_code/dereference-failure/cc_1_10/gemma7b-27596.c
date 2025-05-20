//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

void roundRobin(Process* head, int quantum) {
    Process* current = head;
    time_t start_time = time(NULL);
    int time_quantum = 0;

    while (current) {
        if (time_quantum == quantum) {
            time_quantum = 0;
            printf("Process ID: %d, Name: %s, Arrival Time: %d, Service Time: %d\n", current->process_id, current->name, current->arrival_time, current->service_time);
            current = current->next;
        } else {
            time_quantum++;
        }

        sleep(1);
    }

    printf("\nTotal time: %d seconds\n", time(NULL) - start_time);
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    strcpy(process1->name, "Process 1");
    process1->arrival_time = 0;
    process1->service_time = 5;
    process1->next = NULL;

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    strcpy(process2->name, "Process 2");
    process2->arrival_time = 2;
    process2->service_time = 3;
    process2->next = NULL;

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    strcpy(process3->name, "Process 3");
    process3->arrival_time = 3;
    process3->service_time = 4;
    process3->next = NULL;

    // Add processes to the queue
    head = process1;
    process1->next = process2;
    process2->next = process3;

    // Round Robin scheduling
    roundRobin(head, 2);

    return 0;
}