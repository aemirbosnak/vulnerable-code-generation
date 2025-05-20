//Falcon-180B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int argc;
} Command;

int execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(command->command, command->arguments) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Command terminated abnormally\n");
            return EXIT_FAILURE;
        }
    }
}

int main() {
    int num_commands;
    Command *commands;
    char input[MAX_COMMAND_LENGTH];
    char *token;
    int i, j;

    printf("Enter number of commands: ");
    scanf("%d", &num_commands);

    commands = malloc(sizeof(Command) * num_commands);

    for (i = 0; i < num_commands; i++) {
        printf("Enter command %d: ", i+1);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        commands[i].command = strdup(token);

        commands[i].arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);
        commands[i].argc = 0;

        while ((token = strtok(NULL, " "))!= NULL) {
            commands[i].arguments[commands[i].argc++] = strdup(token);
        }
    }

    for (i = 0; i < num_commands; i++) {
        printf("Executing command %d: %s ", i+1, commands[i].command);
        for (j = 0; j < commands[i].argc; j++) {
            printf("%s ", commands[i].arguments[j]);
        }
        printf("\n");
        execute_command(&commands[i]);
        printf("\n");
    }

    for (i = 0; i < num_commands; i++) {
        free(commands[i].command);
        for (j = 0; j < commands[i].argc; j++) {
            free(commands[i].arguments[j]);
        }
        free(commands[i].arguments);
    }
    free(commands);

    return 0;
}