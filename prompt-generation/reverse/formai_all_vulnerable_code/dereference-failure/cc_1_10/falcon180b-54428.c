//Falcon-180B DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 10

typedef struct {
    pid_t pid;
    int status;
} process_t;

void execute_command(char *command, int *status) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execlp(command, command, NULL) == -1) {
            *status = errno;
        }
    } else if (pid < 0) {
        *status = errno;
    } else {
        waitpid(pid, status, 0);
    }
}

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter command (or type 'exit' to quit): ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        int status;
        execute_command(command, &status);

        if (status == 0) {
            printf("Command executed successfully.\n");
        } else {
            printf("Error executing command: %s\n", strerror(status));
        }

        num_processes++;
    }

    return 0;
}