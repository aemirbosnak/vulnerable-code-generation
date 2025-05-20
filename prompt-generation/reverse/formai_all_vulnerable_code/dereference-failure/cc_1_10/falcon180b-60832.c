//Falcon-180B DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int num_arguments;
    pid_t pid;
    int status;
} process_t;

void execute_command(char *command, process_t *process) {
    char *delimiter = " ";
    char *token = strtok(command, delimiter);
    int num_arguments = 0;

    while (token!= NULL) {
        process->arguments[num_arguments] = token;
        num_arguments++;

        if (num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: too many arguments\n");
            exit(1);
        }

        token = strtok(NULL, delimiter);
    }

    process->num_arguments = num_arguments;

    pid_t child_pid = fork();

    if (child_pid == 0) {
        execvp(process->arguments[0], process->arguments);
        fprintf(stderr, "Error: failed to execute command\n");
        exit(1);
    } else if (child_pid < 0) {
        fprintf(stderr, "Error: failed to fork\n");
        exit(1);
    } else {
        process->pid = child_pid;
        waitpid(child_pid, &process->status, 0);
    }
}

void print_process_info(process_t *process) {
    printf("PID: %d\n", process->pid);
    printf("Status: %d\n", process->status);

    for (int i = 0; i < process->num_arguments; i++) {
        printf("Argument %d: %s\n", i, process->arguments[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: no command specified\n");
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    process_t process;
    process.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    process.num_arguments = 0;

    execute_command(command, &process);

    print_process_info(&process);

    free(process.arguments);
    return 0;
}