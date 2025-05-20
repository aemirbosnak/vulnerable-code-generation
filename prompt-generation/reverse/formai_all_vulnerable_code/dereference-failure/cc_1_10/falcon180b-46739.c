//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        execlp(command, command, NULL);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // error forking
        printf("Error forking: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
        processes[num_processes].pid = pid;
        processes[num_processes].status = status;
        num_processes++;
    }
}

void print_processes() {
    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        } else {
            execute_command(input);
        }
    }
    return 0;
}