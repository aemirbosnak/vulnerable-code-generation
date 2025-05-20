//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
} process;

process* create_process(int id, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->process_id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, process* new_process) {
    if (head == NULL) {
        head = new_process;
    } else {
        head->next = new_process;
        head = new_process;
    }
}

void simulate_cpu(process* head) {
    time_t start_time = time(NULL);
    process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        current_process->completion_time = time_spent + current_process->arrival_time;
        printf("Process %d completed in %d seconds.\n", current_process->process_id, current_process->completion_time);
        start_time = end_time;
        current_process = current_process->next;
    }
}

int main() {
    process* head = NULL;
    add_process(head, create_process(1, 0, 5));
    add_process(head, create_process(2, 2, 3));
    add_process(head, create_process(3, 4, 2));
    add_process(head, create_process(4, 6, 4));
    add_process(head, create_process(5, 8, 3));

    simulate_cpu(head);

    return 0;
}