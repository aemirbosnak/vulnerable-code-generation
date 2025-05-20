//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

Process* createProcess(int process_id, int arrival_time, int service_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = process_id;
    process->arrival_time = arrival_time;
    process->service_time = service_time;
    process->completion_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int process_id, int arrival_time, int service_time) {
    Process* process = createProcess(process_id, arrival_time, service_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void schedule(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        int remaining_service_time = current_process->service_time - (time(NULL) - start_time);
        if (remaining_service_time > 0) {
            sleep(remaining_service_time);
        }
        current_process->completion_time = time(NULL) - start_time;
        current_process = current_process->next;
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 3);
    addProcess(head, 4, 6, 2);

    schedule(head);

    Process* process = head;
    while (process) {
        printf("Process ID: %d, Arrival Time: %d, Completion Time: %d\n", process->process_id, process->arrival_time, process->completion_time);
        process = process->next;
    }

    return 0;
}