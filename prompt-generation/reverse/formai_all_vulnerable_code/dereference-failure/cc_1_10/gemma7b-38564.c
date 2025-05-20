//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process
{
    int id;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->serviceTime = serviceTime;
    process->completionTime = -1;
    process->next = NULL;
    return process;
}

void simulate(Process* processList)
{
    int currentTime = 0;
    int i = 0;
    Process* currentProcess = NULL;

    while (!processList->next || currentTime < processList->arrivalTime)
    {
        currentTime++;
    }

    while (processList)
    {
        if (processList->arrivalTime <= currentTime && currentProcess == NULL)
        {
            currentProcess = processList;
        }

        if (currentProcess && currentProcess->serviceTime > 0)
        {
            currentProcess->serviceTime--;
            currentTime++;
        }

        if (currentProcess->serviceTime == 0)
        {
            currentProcess->completionTime = currentTime;
            currentProcess = NULL;
        }

        processList = processList->next;
    }
}

int main()
{
    Process* processList = NULL;

    processList = createProcess(1, 0, 5);
    processList = createProcess(2, 2, 4);
    processList = createProcess(3, 3, 3);
    processList = createProcess(4, 4, 2);
    processList = createProcess(5, 5, 1);

    simulate(processList);

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process %d completed at time %d\n", processList[i].id, processList[i].completionTime);
    }

    return 0;
}