//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

int main(int argc, char *argv[]) {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    if (argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        return 1;
    }

    int target_pid = atoi(argv[1]);

    FILE *proc_file = fopen("/proc/self/task", "r");
    if (proc_file == NULL) {
        printf("Error: Could not open /proc/self/task\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, proc_file)!= NULL) {
        if (sscanf(line, "%d", &processes[num_processes].pid)!= 1) {
            continue;
        }

        processes[num_processes].pid = processes[num_processes].pid;
        strcpy(processes[num_processes].command, argv[0]);
        num_processes++;

        if (num_processes == MAX_PROCESSES) {
            break;
        }
    }

    fclose(proc_file);

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == target_pid) {
            printf("Process ID: %d\n", processes[i].pid);
            printf("Command: %s\n", processes[i].command);
            return 0;
        }
    }

    printf("Process not found.\n");
    return 1;
}