//FormAI DATASET v1.0 Category: System boot optimizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 //Max length of string
#define MAX_PROC 100 //Max number of processes

//Struct to hold process information
typedef struct ProcessInfo {
    char name[MAX_LEN];
    int priority;
    int cpuUsage;
    int memoryUsage;
} ProcessInfo;

//Function to read input line by line and populate process information array
void readInput(ProcessInfo *processes, int *numProcesses) {
    char input[MAX_LEN];
    FILE *ptr = fopen("processes.txt", "r");
    if(ptr == NULL) {
        printf("Error: Unable to open input file 'processes.txt'\n");
        exit(-1);
    }
    while(fgets(input, MAX_LEN, ptr) != NULL) {
        char *token = strtok(input, ",");
        strcpy(processes[*numProcesses].name, token);
        token = strtok(NULL, ",");
        processes[*numProcesses].priority = atoi(token);
        token = strtok(NULL, ",");
        processes[*numProcesses].cpuUsage = atoi(token);
        token = strtok(NULL, ",");
        processes[*numProcesses].memoryUsage = atoi(token);
        (*numProcesses)++;
    }
    fclose(ptr);
}

//Function to sort processes based on priority (0 is highest priority)
void sortProcesses(ProcessInfo *processes, int numProcesses) {
    for(int i = 0; i < numProcesses; i++) {
        for(int j = i + 1; j < numProcesses; j++) {
            if(processes[j].priority < processes[i].priority) {
                ProcessInfo temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

//Function to print sorted processes to console
void printProcesses(ProcessInfo *processes, int numProcesses) {
    printf("Sorted processes:\n");
    for(int i = 0; i < numProcesses; i++) {
        printf("%s,%d,%d,%d\n", processes[i].name, processes[i].priority, processes[i].cpuUsage, processes[i].memoryUsage);
    }
}

//Main function
int main() {
    ProcessInfo processes[MAX_PROC];
    int numProcesses = 0;
    readInput(processes, &numProcesses);
    sortProcesses(processes, numProcesses);
    printProcesses(processes, numProcesses);
    return 0;
}