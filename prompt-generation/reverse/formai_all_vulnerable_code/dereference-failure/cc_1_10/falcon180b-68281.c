//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

// Function prototypes
void execute_command(char *command);
char *get_next_token(char *line);
int is_valid_command(char *command);
void print_help();

int main() {
    char input_line[MAX_LINE_LENGTH];
    char *command = NULL;
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;
    int i;

    printf("Welcome to the Unix-like Shell!\n");
    printf("Type 'help' for a list of valid commands.\n");

    while (fgets(input_line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strlen(input_line) == 0 || input_line[0] == '#') {
            continue; // Ignore empty lines and comments
        }

        command = strtok(input_line, " \t\n");
        if (is_valid_command(command)) {
            num_arguments = 0;
            while ((arguments[num_arguments] = get_next_token(input_line))!= NULL) {
                num_arguments++;
                if (num_arguments >= MAX_ARGUMENTS) {
                    printf("Error: Too many arguments.\n");
                    break;
                }
            }

            execute_command(command);
        } else {
            printf("Invalid command: %s\n", command);
        }
    }

    return 0;
}

void execute_command(char *command) {
    if (strcmp(command, "exit") == 0) {
        exit(0);
    } else if (strcmp(command, "help") == 0) {
        print_help();
    } else {
        system(command);
    }
}

char *get_next_token(char *line) {
    char *token = NULL;
    char *p = line;

    while (isspace(*p)) {
        p++;
    }

    token = p;
    while (!isspace(*p) && *p!= '\0') {
        p++;
    }

    *p = '\0';
    return token;
}

int is_valid_command(char *command) {
    char *valid_commands[] = {"exit", "help", NULL};
    int i;

    for (i = 0; valid_commands[i]!= NULL; i++) {
        if (strcmp(command, valid_commands[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void print_help() {
    printf("Valid commands:\n");
    printf("  exit       - Exit the shell\n");
    printf("  help       - Print this help message\n");
}