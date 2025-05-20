//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESS 10

typedef struct process {
    char name[20];
    int priority;
    int cpu_burst;
    struct process* next;
} process;

process* create_process(char* name, int priority, int cpu_burst) {
    process* new_process = (process*)malloc(sizeof(process));
    strcpy(new_process->name, name);
    new_process->priority = priority;
    new_process->cpu_burst = cpu_burst;
    new_process->next = NULL;
    return new_process;
}

void round_robin(process* head) {
    process* current = head;
    time_t start_time = time(NULL);
    time_t end_time;

    while (current) {
        end_time = time(NULL);
        sleep(current->cpu_burst);
        printf("%s has finished execution\n", current->name);
        current = current->next;
    }

    start_time = time(NULL) - start_time;
    printf("Total time taken: %ld seconds\n", start_time);
}

int main() {
    process* head = NULL;
    process* tail = NULL;

    // Create a few processes
    head = create_process("Process A", 1, 5);
    tail = head;
    tail = create_process("Process B", 2, 3);
    tail = tail;
    tail = create_process("Process C", 3, 2);

    // Round robin scheduling
    round_robin(head);

    return 0;
}