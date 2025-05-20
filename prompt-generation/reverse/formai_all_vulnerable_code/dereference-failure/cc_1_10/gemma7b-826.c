//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int id;
    int burst_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->burst_time = burst_time;
    process->waiting_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int burst_time) {
    Process* process = createProcess(id, burst_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    int i = 0;
    while (head) {
        head->waiting_time++;
        i++;
        if (i % MAX_SCHEDULE_SIZE == 0) {
            head = head->next;
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 2);
    addProcess(head, 3, 3);
    addProcess(head, 4, 4);

    roundRobin(head);

    for (head = head; head; head = head->next) {
        printf("Process ID: %d, Waiting Time: %d\n", head->id, head->waiting_time);
    }

    return 0;
}