//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 20
#define MAX_COMMAND_LENGTH 100

void print_happy_shell() {
    printf("\n");
    printf("Welcome to the Happy Shell!\n");
    printf("What can I do for you? I'm here to make your day!\n");
    printf("Just type a command, I'll do the rest!\n");
    printf("\n");
}

void get_input(char* command) {
    printf("happy-shell$ ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    if (strlen(command) > 0 && command[strlen(command)-1] == '\n') {
        command[strlen(command)-1] = '\0';
    }
}

void parse_command(char* command, char** args) {
    int args_count = 0;
    char* token = strtok(command, " ");

    while (token != NULL && args_count < MAX_ARGS) {
        args[args_count] = token;
        token = strtok(NULL, " ");
        args_count++;
    }
}

void execute_command(char** args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Sorry, I couldn't execute that command.\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Sorry, I couldn't fork the process.\n");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];

    print_happy_shell();

    while(1) {
        get_input(command);
        parse_command(command, args);

        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye! Have a happy day!\n");
            exit(EXIT_SUCCESS);
        } else {
            execute_command(args);
        }
    }

    return EXIT_SUCCESS;
}