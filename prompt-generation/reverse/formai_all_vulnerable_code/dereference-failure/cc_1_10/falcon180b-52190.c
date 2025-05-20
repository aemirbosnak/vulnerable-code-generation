//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
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
#define DELIM " \t\r\n\a"

int main() {
    char *args[MAX_ARGUMENTS];
    char input_buffer[MAX_COMMAND_LENGTH];
    int num_args;
    pid_t child_pid;
    int status;

    printf("Enter command: ");
    fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
    input_buffer[strcspn(input_buffer, DELIM)] = '\0';

    num_args = tokenize(input_buffer, args);

    if (num_args == 0) {
        printf("Invalid command\n");
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        execvp(args[0], args);
        printf("Exec failed: %s\n", strerror(errno));
        return 1;
    } else {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command executed successfully\n");
        } else {
            printf("Command execution failed\n");
        }
    }

    return 0;
}

int tokenize(char *str, char *args[]) {
    char *token;
    int count = 0;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        args[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }

    return count;
}