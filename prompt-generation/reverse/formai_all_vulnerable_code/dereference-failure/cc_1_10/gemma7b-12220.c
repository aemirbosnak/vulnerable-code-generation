//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROC_NUM 20

typedef struct Process
{
    char name[20];
    int pid;
    struct Process *next;
} Process;

Process *head = NULL;

void addProcess(char *name)
{
    Process *newProcess = malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = getpid();
    newProcess->next = NULL;

    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        Process *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newProcess;
    }
}

void viewProcesses()
{
    Process *temp = head;
    printf("Processes:\n");
    while (temp)
    {
        printf("- %s (PID: %d)\n", temp->name, temp->pid);
        temp = temp->next;
    }
}

int main()
{
    addProcess("Parent");
    fork();
    addProcess("Child");
    viewProcesses();

    return 0;
}