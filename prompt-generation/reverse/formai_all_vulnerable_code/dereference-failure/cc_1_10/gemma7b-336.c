//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESS 10

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

void add_process(Process* head, int process_id, int arrival_time, int service_time) {
    Process* process = create_process(process_id, arrival_time, service_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void round_robin(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        printf("Process %d completed in %d seconds\n", current_process->process_id, time_spent);
        current_process = current_process->next;
        start_time = time(NULL);
    }
}

int main() {
    Process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 3);
    add_process(head, 3, 4, 4);
    add_process(head, 4, 6, 2);
    round_robin(head);
    return 0;
}