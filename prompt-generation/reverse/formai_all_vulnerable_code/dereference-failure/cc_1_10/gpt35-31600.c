//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
        char name[32]; // process name
        int pid; // process ID
        float cpu; // CPU usage
        float mem; // Memory usage
} Process;

typedef struct ProcessList {
        Process* processes; // list of processes
        int numProcesses; // number of processes in the list
} ProcessList;

char getRandomChar()
{
    int x = rand() % 26;
    char c = 'a' + x;
    return c;
}

void fillRandomString(char* str, int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        str[i] = getRandomChar();
    }
    str[len - 1] = '\0';
}

ProcessList getRandomProcessList(int numProcesses)
{
    ProcessList processList = {0};
    processList.numProcesses = numProcesses;
    processList.processes = (Process*)malloc(numProcesses * sizeof(Process));

    for (int i = 0; i < numProcesses; ++i)
    {
        Process* process = processList.processes + i;

        fillRandomString(process->name, sizeof(process->name));

        process->pid = rand() % 100000;
        process->cpu = (float)(rand() % 1000) / 10.0;
        process->mem = (float)(rand() % 1000) / 10.0;
    }

    return processList;
}

void printProcessList(ProcessList* processList)
{
    printf("----------------------------------------------\n");
    printf("| %-32s | %-5s | %-5s |\n", "NAME", "PID", "CPU%");
    printf("----------------------------------------------\n");

    for (int i = 0; i < processList->numProcesses; ++i)
    {
        Process* process = processList->processes + i;

        printf("| %-32s | %-5d | %-5.1f |\n", process->name, process->pid, process->cpu);
    }

    printf("----------------------------------------------\n");
}

int main()
{
    srand(42); // Seed random number generator

    ProcessList processList = getRandomProcessList(10);

    printf("Welcome to the most amazing process viewer ever created!\n");

    while (1)
    {
        printf("\nEnter any key to refresh the process list (q to quit): ");
        char ch;
        scanf(" %c", &ch);

        if (ch == 'q')
        {
            break;
        }

        printProcessList(&processList);
    }

    free(processList.processes); // Clean up

    printf("Goodbye!\n");

    return 0;
}