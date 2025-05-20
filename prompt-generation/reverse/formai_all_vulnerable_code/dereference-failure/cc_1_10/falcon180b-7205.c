//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct process{
    char name[20];
    int pid;
    int memory;
}Process;

Process *createProcess(char *name, int pid, int memory){
    Process *process = (Process*)malloc(sizeof(Process));
    strcpy(process->name, name);
    process->pid = pid;
    process->memory = memory;
    return process;
}

void printProcesses(Process *processes, int numProcesses){
    printf("Process\tPID\tMemory\n");
    for(int i=0; i<numProcesses; i++){
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memory);
    }
}

int main(){
    int numProcesses, i;
    char input[100];
    Process *processes = NULL;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    processes = (Process*)malloc(numProcesses*sizeof(Process));

    for(i=0; i<numProcesses; i++){
        printf("Enter process %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", input);
        strcpy(processes[i].name, input);

        printf("PID: ");
        scanf("%d", &processes[i].pid);

        printf("Memory usage (in KB): ");
        scanf("%d", &processes[i].memory);
    }

    printf("Processes created successfully!\n");
    printProcesses(processes, numProcesses);

    return 0;
}