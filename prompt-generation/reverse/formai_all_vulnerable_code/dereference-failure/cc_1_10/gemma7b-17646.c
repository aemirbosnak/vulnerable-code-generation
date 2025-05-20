//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROC_DIR "/proc"

typedef struct ProcessInfo {
    char name[256];
    int pid;
    int ppid;
    struct ProcessInfo* next;
} ProcessInfo;

ProcessInfo* process_info_head = NULL;

void add_process_info(char* name, int pid, int ppid) {
    ProcessInfo* new_info = malloc(sizeof(ProcessInfo));
    strcpy(new_info->name, name);
    new_info->pid = pid;
    new_info->ppid = ppid;
    new_info->next = process_info_head;
    process_info_head = new_info;
}

void print_process_info() {
    ProcessInfo* current = process_info_head;
    while (current) {
        printf("Process: %s (PID: %d, PPID: %d)\n", current->name, current->pid, current->ppid);
        current = current->next;
    }
}

int main() {
    char proc_name[256];
    int pid, ppid;

    // Get the process name from the user
    printf("Enter the process name: ");
    scanf("%s", proc_name);

    // Get the process ID and PPID
    pid = getpid();
    ppid = getppid();

    // Add the process information to the list
    add_process_info(proc_name, pid, ppid);

    // Print the process information
    print_process_info();

    return 0;
}