//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_ARG_LENGTH 100

typedef struct {
    char *command;
    char **args;
    int num_args;
} command_t;

int main() {
    FILE *fp;
    char line[MAX_ARG_LENGTH];
    char *token;
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];

    fp = fopen("boot_commands.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_ARG_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");

        if (token == NULL) {
            continue;
        }

        commands[num_commands].command = strdup(token);
        commands[num_commands].args = NULL;
        commands[num_commands].num_args = 0;

        while ((token = strtok(NULL, " "))!= NULL) {
            if (commands[num_commands].num_args >= MAX_ARG_LENGTH) {
                printf("Error: Too many arguments.\n");
                exit(1);
            }

            commands[num_commands].args[commands[num_commands].num_args] = strdup(token);
            commands[num_commands].num_args++;
        }

        num_commands++;

        if (num_commands >= MAX_COMMANDS) {
            printf("Error: Too many commands.\n");
            exit(1);
        }
    }

    fclose(fp);

    for (int i = 0; i < num_commands; i++) {
        printf("Command %d: %s\n", i+1, commands[i].command);

        for (int j = 0; j < commands[i].num_args; j++) {
            printf("  Argument %d: %s\n", j+1, commands[i].args[j]);
        }
    }

    return 0;
}