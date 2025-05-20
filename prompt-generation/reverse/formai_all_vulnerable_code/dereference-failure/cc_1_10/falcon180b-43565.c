//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process_info {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_info_t;

void print_process_info(process_info_t *process_info) {
    printf("PID: %d\n", process_info->pid);
    printf("Command: %s\n", process_info->command);
    printf("Status: %d\n\n", process_info->status);
}

int main() {
    int num_processes = 0;
    process_info_t *process_info_array = malloc(MAX_PROCESSES * sizeof(process_info_t));

    if (process_info_array == NULL) {
        printf("Error: Failed to allocate memory for process info array.\n");
        return 1;
    }

    FILE *proc_file = fopen("/proc/self/status", "r");

    if (proc_file == NULL) {
        printf("Error: Failed to open /proc/self/status.\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, proc_file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            char *command_start = line + 6;
            int command_length = strlen(command_start) - 1;

            if (command_length >= MAX_COMMAND_LENGTH) {
                printf("Warning: Command length exceeds maximum limit.\n");
                continue;
            }

            strncpy(process_info_array[num_processes].command, command_start, MAX_COMMAND_LENGTH);
            process_info_array[num_processes].command[command_length] = '\0';
            process_info_array[num_processes].pid = getpid();
            process_info_array[num_processes].status = 0;
            num_processes++;
        }
    }

    fclose(proc_file);

    for (int i = 0; i < num_processes; i++) {
        print_process_info(&process_info_array[i]);
    }

    free(process_info_array);
    return 0;
}