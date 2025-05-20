//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int service_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(Process* head, int process_id, int arrival_time, int service_time) {
    Process* new_process = create_process(process_id, arrival_time, service_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(Process* head) {
    time_t start_time = time(NULL);
    int current_time = 0;
    int processes_completed = 0;
    while (processes_completed < MAX_PROCESS) {
        for (Process* process = head; process; process = process->next) {
            if (process->arrival_time <= current_time) {
                current_time += process->service_time;
                processes_completed++;
                printf("Process %d completed at time %d\n", process->process_id, current_time);
                free(process);
            }
        }
        current_time++;
    }
    time_t end_time = time(NULL);
    printf("Total time taken: %d seconds\n", end_time - start_time);
}

int main() {
    Process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 4);
    add_process(head, 3, 4, 3);
    add_process(head, 4, 6, 2);
    add_process(head, 5, 8, 1);

    round_robin(head);

    return 0;
}