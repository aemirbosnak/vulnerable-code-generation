//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A struct to represent a single process */
typedef struct Process {
    int pid;
    int cpuUsage;
    int ramUsage;
    struct Process *prev;
    struct Process *next;
} Process;

/* A struct to represent the RAM and its current usage */
typedef struct RAM {
    int totalSize;
    int usedSize;
    Process *head;
} RAM;

/* Checks if there is enough free space left in the RAM */
bool hasSpaceInRAM(RAM *ram, int newSize) {
    int remainingSpace = ram->totalSize - ram->usedSize;

    if (newSize <= remainingSpace)
        return true;

    return false;
}

/* Adds a new process to the RAM and keeps track of the CPU and RAM usage */
void addProcessToRAM(RAM *ram, int pid, int cpuUsage, int ramUsage) {
    if(!hasSpaceInRAM(ram, ramUsage)) {
        printf("Not enough free space in RAM to add process with PID: %d\n", pid);
        return;
    }

    Process *newProcess = malloc(sizeof(Process));
    newProcess->pid = pid;
    newProcess->cpuUsage = cpuUsage;
    newProcess->ramUsage = ramUsage;
    newProcess->prev = NULL;

    if(ram->head == NULL) {
        ram->head = newProcess;
        newProcess->next = NULL;
    }
    else {
        Process *temp = ram->head;

        while(temp->next != NULL)
            temp = temp->next;

        newProcess->prev = temp;
        temp->next = newProcess;
        newProcess->next = NULL;
    }

    ram->usedSize += ramUsage;

    printf("Process with PID: %d added successfully\n", pid);
}

/* Removes a process from the RAM and adjusts the CPU and RAM usage accordingly */
void removeProcessFromRAM(RAM *ram, int pid) {
    Process *temp = ram->head;

    while(temp != NULL && temp->pid != pid)
        temp = temp->next;

    if(temp == NULL) {
        printf("Process with PID: %d not found in RAM\n", pid);
        return;
    }

    if(temp->prev == NULL && temp->next == NULL)
        ram->head = NULL;
    else if(temp->prev == NULL)
        ram->head = temp->next;
    else if(temp->next == NULL)
        temp->prev->next = NULL;
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    ram->usedSize -= temp->ramUsage;

    free(temp);

    printf("Process with PID: %d removed successfully\n", pid);
}

/* Displays the current RAM usage and all the processes currently in the RAM */
void displayRAM(RAM *ram) {
    printf("\nCurrent RAM usage: %d/%d\n", ram->usedSize, ram->totalSize);
    printf("Processes currently in RAM: \n");

    Process *temp = ram->head;

    while(temp != NULL) {
        printf("PID: %d, CPU Usage: %d, RAM Usage: %d\n", temp->pid, temp->cpuUsage, temp->ramUsage);
        temp = temp->next;
    }
}

/* Main method to test the RAM usage monitor program */
int main() {
    RAM *ram = malloc(sizeof(RAM));
    ram->totalSize = 1000;
    ram->usedSize = 0;
    ram->head = NULL;

    addProcessToRAM(ram, 1001, 10, 100);
    addProcessToRAM(ram, 1002, 20, 200);
    addProcessToRAM(ram, 1003, 30, 300);

    displayRAM(ram);

    removeProcessFromRAM(ram, 1002);

    displayRAM(ram);

    addProcessToRAM(ram, 1004, 40, 400);

    displayRAM(ram);

    removeProcessFromRAM(ram, 1001);
    removeProcessFromRAM(ram, 1003);
    removeProcessFromRAM(ram, 1004);

    displayRAM(ram);

    free(ram);
    
    return 0;
}