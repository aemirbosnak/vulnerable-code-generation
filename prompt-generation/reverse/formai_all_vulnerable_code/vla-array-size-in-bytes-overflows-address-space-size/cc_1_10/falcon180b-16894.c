//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_PROCESS_TIME 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int time;
} Process;

int compare(const void *a, const void *b) {
    Process *processA = (Process *) a;
    Process *processB = (Process *) b;
    if (processA->time > processB->time) {
        return 1;
    } else if (processA->time < processB->time) {
        return -1;
    } else {
        return 0;
    }
}

void executeProcesses(Process processes[], int numProcesses) {
    qsort(processes, numProcesses, sizeof(Process), compare);
    int totalWaitTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        totalWaitTime += processes[i].time;
        printf("Executing process %s\n", processes[i].name);
        sleep(processes[i].time);
    }
    printf("Total wait time: %d milliseconds\n", totalWaitTime);
}

int main() {
    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    Process processes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf(" %[^\n]", processes[i].name);
        printf("Enter the time required for process %s: ", processes[i].name);
        scanf("%d", &processes[i].time);
    }

    executeProcesses(processes, numProcesses);

    return 0;
}