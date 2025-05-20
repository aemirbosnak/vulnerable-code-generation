//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMANDS 50

void printBanner() {
    printf("Welcome to the wacky shell!\n");
    printf("Where all your shell dreams come true!\n");
    printf("But mostly just basic commands and child processes...\n");
    printf("----------------------------\n");
}

void printPrompt() {
    printf(">> ");
}

char** parseInput(char* input) {
    char** args = (char**) malloc(MAX_ARGS * sizeof(char*));

    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int execute(char** args) {
    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        printf("Goodbye, cruel shell world...\n");
        exit(0);
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Sorry, your child process was not born...\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Sorry, your command was not understood...\n");
        }
        exit(1);
    } else {
        // Parent process
        int childStatus;
        waitpid(pid, &childStatus, 0);
    }

    return 1;
}

int main() {
    printBanner();

    while(1) {
        printPrompt();

        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        char** commands = (char**) malloc(MAX_COMMANDS * sizeof(char*));
        int i = 0;
        commands[i] = strtok(input, ";");
        while (commands[i] != NULL && i < MAX_COMMANDS - 1) {
            i++;
            commands[i] = strtok(NULL, ";");
            commands[i] = commands[i] + strspn(commands[i], " ");
        }
        commands[i] = NULL;

        for (int j = 0; commands[j] != NULL; j++) {
            char** args = parseInput(commands[j]);
            execute(args);
            free(args);
        }
        free(commands);
    }

    return 0;
}