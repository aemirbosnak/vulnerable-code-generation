//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PROC_NAME_LEN 256

typedef struct ProcessInfo {
    char name[MAX_PROC_NAME_LEN];
    int pid;
    struct ProcessInfo* next;
} ProcessInfo;

ProcessInfo* createProcessInfo(char* name, int pid) {
    ProcessInfo* newProcessInfo = malloc(sizeof(ProcessInfo));
    strcpy(newProcessInfo->name, name);
    newProcessInfo->pid = pid;
    newProcessInfo->next = NULL;
    return newProcessInfo;
}

void printProcessInfo(ProcessInfo* processInfo) {
    printf("Process Name: %s\n", processInfo->name);
    printf("Process ID: %d\n", processInfo->pid);
    printf("\n");
}

int main() {
    ProcessInfo* processInfoHead = NULL;

    // Get a list of all processes
    system("ps aux");

    // Parse the output of ps aux and create a linked list of ProcessInfo structures
    FILE* psAuxOutput = popen("ps aux", "r");
    char line[MAX_PROC_NAME_LEN];
    while (fgets(line, MAX_PROC_NAME_LEN, psAuxOutput) != NULL) {
        char* processName = strtok(line, " ");
        int pid = atoi(strtok(NULL, " "));
        ProcessInfo* newProcessInfo = createProcessInfo(processName, pid);
        if (processInfoHead == NULL) {
            processInfoHead = newProcessInfo;
        } else {
            processInfoHead->next = newProcessInfo;
            processInfoHead = newProcessInfo;
        }
    }

    // Print the process information
    printProcessInfo(processInfoHead);

    return 0;
}