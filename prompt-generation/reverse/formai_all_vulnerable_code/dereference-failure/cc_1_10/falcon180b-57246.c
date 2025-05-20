//Falcon-180B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int execute_command(char **args) {
    pid_t pid;
    int status;
    if ((pid = fork()) == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid == -1) {
        fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];
    int num_arguments;
    int return_value;

    printf("Enter a command: ");
    fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    num_arguments = tokenize(input_buffer, args);

    return_value = execute_command(args);

    if (return_value == -1) {
        printf("Command execution failed.\n");
    } else {
        printf("Command executed with return value %d.\n", return_value);
    }

    return 0;
}

int tokenize(char *input_buffer, char **args) {
    int num_arguments = 0;
    char *token;

    token = strtok(input_buffer, " ");
    while (token!= NULL) {
        args[num_arguments++] = token;
        token = strtok(NULL, " ");
    }

    return num_arguments;
}