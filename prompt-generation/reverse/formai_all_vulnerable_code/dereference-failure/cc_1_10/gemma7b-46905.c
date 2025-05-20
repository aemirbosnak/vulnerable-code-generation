//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSORS 4

typedef struct process {
    char name[20];
    int arrival_time;
    int burst_time;
    int completion_time;
    struct process* next;
} process;

process* createProcess(char* name, int arrival_time, int burst_time) {
    process* newProcess = (process*)malloc(sizeof(process));
    strcpy(newProcess->name, name);
    newProcess->arrival_time = arrival_time;
    newProcess->burst_time = burst_time;
    newProcess->completion_time = 0;
    newProcess->next = NULL;

    return newProcess;
}

void schedule(process* head) {
    time_t start_time = time(NULL);
    process* currentProcess = head;

    while (currentProcess) {
        // Calculate remaining time
        int remaining_time = currentProcess->burst_time - (time(NULL) - start_time);

        // If remaining time is 0, complete the process
        if (remaining_time == 0) {
            currentProcess->completion_time = time(NULL);
            printf("%s completed\n", currentProcess->name);
            currentProcess = currentProcess->next;
        } else {
            // Otherwise, update the remaining time and wait
            printf("%s is waiting\n", currentProcess->name);
            sleep(remaining_time);
        }
    }

    // Print completion times for all processes
    printf("Completion times:\n");
    process* temp = head;
    while (temp) {
        printf("%s completed at time %d\n", temp->name, temp->completion_time);
        temp = temp->next;
    }
}

int main() {
    // Create a list of processes
    process* head = createProcess("A", 0, 5);
    head = createProcess("B", 2, 3);
    head = createProcess("C", 4, 4);
    head = createProcess("D", 6, 2);

    // Schedule the processes
    schedule(head);

    return 0;
}