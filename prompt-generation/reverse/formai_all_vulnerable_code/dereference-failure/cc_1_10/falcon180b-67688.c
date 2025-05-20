//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 10
#define MAX_LINE_LENGTH 512

char *commands[MAX_COMMANDS];
char *arguments[MAX_ARGUMENTS];
int num_commands;
int num_arguments;

void execute_command(char *command, int num_arguments) {
    for (int i = 0; i < num_arguments; i++) {
        printf("%s ", arguments[i]);
    }
    printf("\n");
}

void add_command(char *command) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands\n");
        return;
    }
    strcpy(commands[num_commands], command);
    num_commands++;
}

void add_argument(char *argument) {
    if (num_arguments >= MAX_ARGUMENTS) {
        printf("Error: Too many arguments\n");
        return;
    }
    strcpy(arguments[num_arguments], argument);
    num_arguments++;
}

int main() {
    char input[MAX_LINE_LENGTH];
    char *token;
    int in_command = 0;
    int in_quote = 0;

    num_commands = 0;
    num_arguments = 0;

    add_command("echo");
    add_command("cd");
    add_command("exit");

    printf("Enter commands followed by arguments (use quotes for arguments with spaces):\n");

    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(input, " ");
        while (token!= NULL) {
            if (in_quote) {
                if (token[0] == '"') {
                    in_quote = 0;
                } else {
                    strcat(arguments[num_arguments-1], token);
                    strcat(arguments[num_arguments-1], " ");
                }
            } else if (strcasecmp(token, "echo") == 0) {
                in_command = 1;
            } else if (strcasecmp(token, "cd") == 0) {
                in_command = 1;
            } else if (strcasecmp(token, "exit") == 0) {
                in_command = 1;
            } else if (in_command) {
                add_argument(token);
            }
            token = strtok(NULL, " ");
        }
        if (in_command) {
            execute_command(arguments[0], num_arguments-1);
            num_arguments = 0;
            in_command = 0;
        }
    }

    return 0;
}