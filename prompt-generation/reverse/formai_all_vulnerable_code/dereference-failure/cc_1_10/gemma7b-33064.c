//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 5

typedef struct process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
} process;

process* create_process() {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->process_id = rand() % MAX_PROCESS_NUM;
    new_process->arrival_time = rand() % 10;
    new_process->service_time = rand() % 5;
    new_process->completion_time = 0;
    new_process->next = NULL;

    return new_process;
}

void add_process(process* head) {
    process* new_process = create_process();
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(process* head) {
    time_t start_time = time(NULL);
    process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int waiting_time = end_time - current_process->arrival_time;
        current_process->completion_time = start_time + waiting_time + current_process->service_time;
        current_process = current_process->next;
    }
}

int main() {
    process* head = NULL;
    for (int i = 0; i < 10; i++) {
        add_process(head);
    }
    round_robin(head);

    for (process* process = head; process; process = process->next) {
        printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Completion Time: %d\n", process->process_id, process->arrival_time, process->service_time, process->completion_time);
    }

    return 0;
}