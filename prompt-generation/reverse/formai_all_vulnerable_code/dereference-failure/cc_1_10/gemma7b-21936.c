//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4

typedef struct process {
    int id;
    int burst_time;
    int waiting_time;
    struct process* next;
} process;

process* createProcess(int id, int burst_time) {
    process* p = (process*)malloc(sizeof(process));
    p->id = id;
    p->burst_time = burst_time;
    p->waiting_time = 0;
    p->next = NULL;
    return p;
}

void addProcess(process* head, int id, int burst_time) {
    process* p = createProcess(id, burst_time);
    if (head == NULL) {
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void roundRobin(process* head) {
    time_t start_time = time(NULL);
    int current_processor = 0;
    process* current_process = head;

    while (current_process) {
        int remaining_time = current_process->burst_time - current_process->waiting_time;
        int time_spent = time(NULL) - start_time;

        if (remaining_time > time_spent) {
            current_process->waiting_time++;
        } else {
            current_process->waiting_time = 0;
            current_processor++;

            if (current_processor >= MAX_PROCESSORS) {
                current_processor = 0;
            }

            current_process = current_process->next;
        }

        start_time = time(NULL);
    }
}

int main() {
    process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 3);
    addProcess(head, 3, 7);
    addProcess(head, 4, 2);

    roundRobin(head);

    for (process* p = head; p; p = p->next) {
        printf("Process ID: %d, Waiting Time: %d\n", p->id, p->waiting_time);
    }

    return 0;
}