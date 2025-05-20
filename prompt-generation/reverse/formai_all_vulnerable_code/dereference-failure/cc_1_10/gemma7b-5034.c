//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROC 4

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    struct Process* next;
};

void roundrobin(struct Process* head)
{
    struct Process* current = head;
    struct Process* next = NULL;

    while (current)
    {
        next = current->next;
        sleep(current->burst_time);
        printf("Process %d completed\n", current->id);
        current = next;
    }
}

int main()
{
    struct Process* head = NULL;

    // Create a few processes
    for (int i = 0; i < NUM_PROC; i++)
    {
        struct Process* newProcess = malloc(sizeof(struct Process));
        newProcess->id = i;
        newProcess->arrival_time = rand() % 10;
        newProcess->burst_time = rand() % 5;

        if (head == NULL)
        {
            head = newProcess;
        }
        else
        {
            newProcess->next = head;
            head = newProcess;
        }
    }

    // Round robin scheduling
    roundrobin(head);

    return 0;
}