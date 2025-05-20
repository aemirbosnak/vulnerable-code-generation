//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define ROUND_ROBIN_SIZE 5

typedef struct Process {
    int id;
    int burst_time;
    struct Process* next;
} Process;

Process* create_process(int id, int burst_time) {
    Process* process = malloc(sizeof(Process));
    process->id = id;
    process->burst_time = burst_time;
    process->next = NULL;
    return process;
}

void round_robin(Process* processes) {
    int i = 0;
    processes = processes->next;
    while (processes) {
        processes->burst_time--;
        if (processes->burst_time == 0) {
            printf("Process %d completed.\n", processes->id);
            free(processes);
            processes = processes->next;
            i++;
        } else if (i == ROUND_ROBIN_SIZE - 1) {
            processes = processes->next;
            i = 0;
        } else {
            processes = processes->next;
        }
    }
}

int main() {
    Process* processes = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes = create_process(i + 1, rand() % 10 + 1);
        processes->next = processes;
    }

    round_robin(processes);

    return 0;
}