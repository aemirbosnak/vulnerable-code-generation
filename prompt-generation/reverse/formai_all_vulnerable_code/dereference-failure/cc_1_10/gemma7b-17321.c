//Gemma-7B DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a linked list of processes
    struct process
    {
        char name[20];
        int priority;
        struct process* next;
    };

    struct process* head = NULL;

    // Simulate process creation
    for (int i = 0; i < 5; i++)
    {
        struct process* newProcess = (struct process*)malloc(sizeof(struct process));
        strcpy(newProcess->name, "Process " + i);
        newProcess->priority = i + 1;
        newProcess->next = NULL;

        if (head == NULL)
        {
            head = newProcess;
        }
        else
        {
            head->next = newProcess;
            head = newProcess;
        }
    }

    // Print the process list
    struct process* currentProcess = head;
    while (currentProcess)
    {
        printf("Name: %s, Priority: %d\n", currentProcess->name, currentProcess->priority);
        currentProcess = currentProcess->next;
    }

    // Simulate process scheduling
    struct process* scheduledProcess = head;
    for (int i = 0; i < 3; i++)
    {
        printf("Scheduling process: %s\n", scheduledProcess->name);
        scheduledProcess = scheduledProcess->next;
    }

    return 0;
}