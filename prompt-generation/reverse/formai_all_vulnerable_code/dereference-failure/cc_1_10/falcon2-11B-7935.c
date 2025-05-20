//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>

// Function to simulate the execution time of a process
double simulateExecutionTime(int processId, int cpuId) {
    double time = 0.0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (cpuId == 0) {
        time = (double)rand() / (double)RAND_MAX * 1000;
    } else {
        time = (double)rand() / (double)RAND_MAX * 5000;
    }
    gettimeofday(&end, NULL);
    time += (double)((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec) / 1000000.0;
    return time;
}

// Function to schedule the execution of processes
int scheduleExecution(int nProcesses, int* processTimes, int* processCpus) {
    int i, j, processId, cpuId;
    double totalTime = 0.0;
    double remainingTime = 0.0;
    int remainingProcesses = nProcesses;
    int* readyProcesses = malloc(nProcesses * sizeof(int));
    int* cpuUtilization = malloc(nProcesses * sizeof(int));
    for (i = 0; i < nProcesses; i++) {
        readyProcesses[i] = i;
        cpuUtilization[i] = 0;
    }
    while (remainingProcesses > 0) {
        processId = readyProcesses[rand() % remainingProcesses];
        cpuId = processCpus[processId];
        totalTime += simulateExecutionTime(processId, cpuId);
        cpuUtilization[processId]++;
        remainingTime -= processTimes[processId];
        if (remainingTime > 0) {
            readyProcesses[processId] = rand() % remainingProcesses;
        } else {
            remainingProcesses--;
        }
    }
    for (i = 0; i < nProcesses; i++) {
        printf("%d: %d (%d)\n", i, cpuUtilization[i], processTimes[i]);
    }
    return totalTime;
}

int main() {
    int nProcesses = 10;
    int* processTimes = malloc(nProcesses * sizeof(int));
    int* processCpus = malloc(nProcesses * sizeof(int));
    for (int i = 0; i < nProcesses; i++) {
        processTimes[i] = (int)((double)rand() / (double)RAND_MAX * 10000);
        processCpus[i] = rand() % 2;
    }
    int totalTime = scheduleExecution(nProcesses, processTimes, processCpus);
    printf("Total time: %f\n", totalTime);
    return 0;
}