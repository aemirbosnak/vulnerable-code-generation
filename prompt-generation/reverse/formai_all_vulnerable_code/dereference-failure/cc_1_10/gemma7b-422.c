//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_PROC_NAME_LEN 256

typedef struct ProcessInfo {
    char name[MAX_PROC_NAME_LEN];
    int pid;
    struct ProcessInfo* next;
} ProcessInfo;

ProcessInfo* process_list = NULL;

void add_process(char* name, int pid) {
    ProcessInfo* new_process = malloc(sizeof(ProcessInfo));
    strcpy(new_process->name, name);
    new_process->pid = pid;
    new_process->next = process_list;
    process_list = new_process;
}

void print_processes() {
    ProcessInfo* current_process = process_list;
    printf("Processes:\n");
    while (current_process) {
        printf("  - %s (PID: %d)\n", current_process->name, current_process->pid);
        current_process = current_process->next;
    }
}

int main() {
    pid_t pid;
    char process_name[MAX_PROC_NAME_LEN];

    // Simulate process creation
    for (int i = 0; i < 5; i++) {
        sprintf(process_name, "Process %d", i);
        pid = fork();
        if (pid == 0) {
            sleep(i);
            exit(0);
        }
        add_process(process_name, pid);
    }

    // Print processes after they have finished
    sleep(6);
    print_processes();

    return 0;
}