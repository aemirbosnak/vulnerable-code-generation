//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_PROCESS_COMMAND_LENGTH 200

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    char command[MAX_PROCESS_COMMAND_LENGTH];
    pid_t pid;
    int priority;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(const char* name, const char* command, int priority) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    Process* process = &processes[num_processes];
    strncpy(process->name, name, MAX_PROCESS_NAME_LENGTH-1);
    strncpy(process->command, command, MAX_PROCESS_COMMAND_LENGTH-1);
    process->pid = 0;
    process->priority = priority;

    num_processes++;
}

void remove_process(int index) {
    if (index < 0 || index >= num_processes) {
        printf("Error: Invalid process index.\n");
        return;
    }

    num_processes--;
    if (index < num_processes) {
        memmove(&processes[index], &processes[index+1], sizeof(Process) * (num_processes - index));
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <process name> <process command> [process priority]\n", argv[0]);
        return 1;
    }

    add_process(argv[1], argv[2], argc >= 4? atoi(argv[3]) : 0);

    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d. %s (%s) - Priority: %d\n", i+1, processes[i].name, processes[i].command, processes[i].priority);
    }

    return 0;
}