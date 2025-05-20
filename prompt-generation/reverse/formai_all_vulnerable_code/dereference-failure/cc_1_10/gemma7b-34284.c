//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct process {
    char name[20];
    int arrival_time;
    int service_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(char* name, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    strcpy(new_process->name, name);
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
    new_process->next = NULL;
    return new_process;
}

void simulate_cpu(process* head) {
    time_t start_time = time(NULL);
    int current_time = 0;
    process* current_process = head;

    while (current_process) {
        if (current_time >= current_process->arrival_time && current_process->remaining_time > 0) {
            current_process->remaining_time--;
            current_time++;
        } else {
            current_process = current_process->next;
        }
    }

    time_t end_time = time(NULL);
    int total_time = (int)(end_time - start_time);

    printf("Total time: %d\n", total_time);
}

int main() {
    process* head = create_process("A", 0, 5);
    head = create_process("B", 2, 3);
    head = create_process("C", 4, 4);
    head = create_process("D", 6, 2);
    head = create_process("E", 8, 3);

    simulate_cpu(head);

    return 0;
}