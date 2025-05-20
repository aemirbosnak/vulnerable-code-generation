//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process
{
    int id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrival_time, int service_time)
{
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->arrival_time = arrival_time;
    newProcess->service_time = service_time;
    newProcess->completion_time = 0;
    newProcess->next = NULL;

    return newProcess;
}

void addProcess(Process* head, int id, int arrival_time, int service_time)
{
    Process* newProcess = createProcess(id, arrival_time, service_time);
    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        Process* tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

void roundRobin(Process* head)
{
    int timeQuantum = 5;
    Process* currentProcess = head;
    time_t start_time = time(NULL);

    while (currentProcess)
    {
        time_t end_time = time(NULL);
        int timeSpent = end_time - start_time;

        if (timeSpent >= currentProcess->service_time)
        {
            currentProcess->completion_time = time(NULL);
            currentProcess = currentProcess->next;
        }
        else
        {
            printf("Process %d is running...", currentProcess->id);
            sleep(timeQuantum);
            start_time = time(NULL);
        }
    }

    printf("All processes completed!");
}

int main()
{
    Process* head = NULL;
    addProcess(head, 1, 2, 3);
    addProcess(head, 2, 4, 5);
    addProcess(head, 3, 3, 4);
    addProcess(head, 4, 5, 6);
    addProcess(head, 5, 4, 2);

    roundRobin(head);

    return 0;
}