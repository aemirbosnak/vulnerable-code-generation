//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAXCMDLENGTH 1024
#define MAXARGLENGTH 64
#define MAXARGS 64

char *readCommand() {
    char *command = NULL;
    ssize_t bufferSize = 0;
    getline(&command, &bufferSize, stdin);
    return command;
}

char **parseCommand(char *command) {
    char **parsedCommands = malloc(MAXARGS * sizeof(char*));
    char *parsedCommand;
    int position = 0;

    parsedCommand = strtok(command, " \t\n");
    while(parsedCommand != NULL) {
        parsedCommands[position] = parsedCommand;
        position++;
        parsedCommand = strtok(NULL, " \t\n");
    }
    parsedCommands[position] = NULL;
    return parsedCommands;
}

void executeCommand(char **commands) {
    pid_t pid = fork();
    if(pid == -1) {
        printf("Error: Forking process failed\n");
        return;
    } else if (pid == 0) {
        if(execvp(commands[0], commands) < 0) {
            printf("Error: Executing command failed\n");
        }
        exit(0);
    } else {
        wait(NULL);
        return;
    }
}

int main() {
    char *command;
    char **parsedCommands;
    int status;

    do {
        printf("Prompt$: ");
        command = readCommand();
        parsedCommands = parseCommand(command);
        executeCommand(parsedCommands);
        free(command);
        free(parsedCommands);
    } while (status);
    return 0;
}