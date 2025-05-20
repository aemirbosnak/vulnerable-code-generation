//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void print_welcome_message();
void print_prompt();
void get_input(char* input);
void parse_input(char* input, char** command, char** arguments);
void execute_command(char* command, char** arguments);
void print_usage();
void print_help_message();

int main() {
    char input[MAX_COMMAND_LENGTH + 1];
    char* command = NULL;
    char* arguments[MAX_ARGUMENTS + 1] = { NULL };

    print_welcome_message();

    while (1) {
        print_prompt();
        get_input(input);
        parse_input(input, &command, arguments);
        execute_command(command, arguments);
        free(command);
        command = NULL;
        memset(arguments, 0, sizeof(arguments));
    }

    return 0;
}

void print_welcome_message() {
    printf("Welcome to Ye Olde Shell!\n");
}

void print_prompt() {
    printf("Ye command: ");
}

void get_input(char* input) {
    fgets(input, MAX_COMMAND_LENGTH + 1, stdin);
    input[strcspn(input, "\n")] = 0;
}

void parse_input(char* input, char** command, char** arguments) {
    char* token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < MAX_ARGUMENTS) {
        if (*command == NULL) {
            *command = strdup(token);
        }
        else {
            arguments[i++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }

    if (i == MAX_ARGUMENTS) {
        print_usage();
        memset(arguments, 0, sizeof(arguments));
    }
}

void execute_command(char* command, char** arguments) {
    pid_t pid;
    int status;

    if (strncmp(command, "exit", 4) == 0) {
        printf("Farewell, fellow warrior!\n");
        exit(0);
    }
    else if (strncmp(command, "help", 4) == 0) {
        print_help_message();
    }
    else if ((pid = fork()) == 0) {
        execvp(command, arguments);
        printf("'%s' is not a valid command.\n", command);
        exit(0);
    }
    else if (pid < 0) {
        printf("Fork failed.\n");
    }
    else {
        waitpid(pid, &status, 0);
    }
}

void print_usage() {
    printf("Too many arguments provided. Maximum is %d.\n", MAX_ARGUMENTS);
}

void print_help_message() {
    printf("Ye Olde Shell is a powerful tool that allows one to execute commands as if they were a medieval warrior.\n\n");
    printf("The available commands are:\n\n");
    printf("exit   - Quit the shell.\n");
    printf("help   - Print this help message.\n\n");
}