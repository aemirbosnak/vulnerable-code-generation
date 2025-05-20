//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int service_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = process_id;
    process->arrival_time = arrival_time;
    process->service_time = service_time;
    process->next = NULL;
    return process;
}

void add_process(Process** head, int process_id, int arrival_time, int service_time) {
    Process* process = create_process(process_id, arrival_time, service_time);
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
    }
}

void round_robin(Process** head) {
    Process* current_process = *head;
    while (current_process) {
        printf("Process ID: %d, Arrival Time: %d, Service Time: %d\n",
            current_process->process_id, current_process->arrival_time,
            current_process->service_time);
        sleep(current_process->service_time);
        current_process = current_process->next;
    }
}

int main() {
    Process* head = NULL;
    add_process(&head, 1, 0, 5);
    add_process(&head, 2, 2, 4);
    add_process(&head, 3, 4, 3);
    add_process(&head, 4, 6, 2);
    add_process(&head, 5, 8, 1);

    round_robin(&head);

    return 0;
}