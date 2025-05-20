//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 64
#define MAX_SCHEDULING_Quantum 1024

typedef struct Process {
    int process_id;
    char name[256];
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

Process* create_process(int id, char* name, int arrival_time, int execution_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    strcpy(process->name, name);
    process->arrival_time = arrival_time;
    process->execution_time = execution_time;
    process->next = NULL;
    return process;
}

void add_process(Process* head, int id, char* name, int arrival_time, int execution_time) {
    Process* process = create_process(id, name, arrival_time, execution_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void round_robin(Process* head, int quantum) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (time(NULL) - start_time < quantum) {
        if (current_process) {
            printf("Process: %s, Execution Time: %d\n", current_process->name, current_process->execution_time);
            current_process->execution_time--;
            if (current_process->execution_time == 0) {
                current_process = current_process->next;
            }
        } else {
            current_process = head;
        }
    }
}

int main() {
    Process* head = NULL;
    add_process(head, 1, "A", 0, 5);
    add_process(head, 2, "B", 2, 4);
    add_process(head, 3, "C", 4, 3);
    add_process(head, 4, "D", 6, 2);

    round_robin(head, MAX_SCHEDULING_Quantum);

    return 0;
}