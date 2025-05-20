//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_service_time;
    struct process* next;
} process;

process* create_process(int id, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->process_id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_service_time = service_time;
    new_process->next = NULL;
    return new_process;
}

void round_robin(process* ready_queue) {
    time_t start_time = time(NULL);
    process* current_process = ready_queue;
    while (current_process) {
        process* next_process = NULL;
        int time_spent = time(NULL) - start_time;
        if (time_spent >= current_process->remaining_service_time) {
            current_process->remaining_service_time = 0;
            printf("Process %d completed.\n", current_process->process_id);
        } else {
            current_process->remaining_service_time -= time_spent;
            next_process = current_process->next;
        }
        current_process = next_process;
        start_time = time(NULL);
    }
}

int main() {
    process* head = create_process(1, 0, 5);
    process* second = create_process(2, 1, 4);
    process* third = create_process(3, 2, 3);
    process* fourth = create_process(4, 3, 2);
    process* fifth = create_process(5, 4, 1);

    process* ready_queue = head;

    round_robin(ready_queue);

    return 0;
}