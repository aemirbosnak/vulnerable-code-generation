//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    struct Process* next;
} Process;

void roundRobin(Process* head)
{
    Process* currentProcess = head;
    while (currentProcess)
    {
        // Simulate process execution
        currentProcess->completionTime = currentProcess->arrivalTime + currentProcess->burstTime;

        // Move to the next process in the queue
        currentProcess = currentProcess->next;
    }
}

int main()
{
    // Create a linked list of processes
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->id = i;
        newProcess->arrivalTime = rand() % 10;
        newProcess->burstTime = rand() % 5;
        newProcess->completionTime = 0;
        newProcess->next = head;
        head = newProcess;
    }

    // Simulate the scheduling algorithm
    roundRobin(head);

    // Print the completion times for each process
    for (Process* process = head; process; process = process->next)
    {
        printf("Process ID: %d, Completion Time: %d\n", process->id, process->completionTime);
    }

    return 0;
}