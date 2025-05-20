//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: grateful
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
#define MAX_ARGUMENTS 512

char **split_command(char *command, int *argc);
int execute_command(char **argv);

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        char *command = strtok(input_buffer, "\n");
        int argc = 0;
        char **argv = split_command(command, &argc);
        int status = execute_command(argv);
        for (int i = 0; i < argc; i++) {
            free(argv[i]);
        }
        free(argv);
        if (status == 1) {
            break;
        }
    }
    return 0;
}

char **split_command(char *command, int *argc) {
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    int i = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        argv[i] = malloc(strlen(token) + 1);
        strcpy(argv[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;
    *argc = i;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;
    if (argv[0] == NULL) {
        printf("Invalid command.\n");
        return 1;
    }
    if (strcmp(argv[0], "exit") == 0) {
        return 1;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}