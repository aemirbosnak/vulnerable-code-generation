//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_COMMANDS 100

typedef struct {
    char *command;
    int num_args;
    char **args;
} command_t;

void execute_command(command_t *command) {
    if (strcmp(command->command, "echo") == 0) {
        printf("Echoing: ");
        for (int i = 0; i < command->num_args; i++) {
            printf("%s ", command->args[i]);
        }
        printf("\n");
    } else {
        printf("Invalid command: %s\n", command->command);
    }
}

void parse_command(char *input, command_t *command) {
    char *token = strtok(input, " ");
    strcpy(command->command, token);

    command->num_args = 0;
    command->args = malloc(MAX_COMMAND_LENGTH * sizeof(char *));

    while ((token = strtok(NULL, " "))!= NULL) {
        command->args[command->num_args++] = strdup(token);
    }
}

int main() {
    FILE *fp;
    char line[MAX_COMMAND_LENGTH];
    int num_commands = 0;
    command_t commands[MAX_NUM_COMMANDS];

    fp = fopen("commands.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open commands file.\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        if (num_commands >= MAX_NUM_COMMANDS) {
            printf("Error: Maximum number of commands exceeded.\n");
            exit(1);
        }

        parse_command(line, &commands[num_commands]);
        num_commands++;
    }

    fclose(fp);

    for (int i = 0; i < num_commands; i++) {
        execute_command(&commands[i]);
    }

    return 0;
}