//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process
{
    char name[20];
    int pid;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name)
{
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = getpid();
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

void viewProcesses()
{
    Process* currentProcess = head;

    printf("Avast, traveler, behold the list of processes:\n");

    while (currentProcess)
    {
        printf("Name: %s, PID: %d\n", currentProcess->name, currentProcess->pid);
        currentProcess = currentProcess->next;
    }

    printf("May the wind blow swift and the sea roar wild!\n");
}

int main()
{
    addProcess("The Black Dragon");
    addProcess("The Jolly Roger");
    addProcess("The Flying Dutchman");

    viewProcesses();

    return 0;
}