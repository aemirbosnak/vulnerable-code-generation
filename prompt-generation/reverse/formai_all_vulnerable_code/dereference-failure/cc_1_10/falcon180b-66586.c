//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 100
#define MAX_ARG_LENGTH 100

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

int main() {
    int num_commands = 0;
    Command commands[MAX_COMMANDS];

    while(1) {
        char input[MAX_ARG_LENGTH];
        printf("Enter command (or 'exit' to quit): ");
        fgets(input, MAX_ARG_LENGTH, stdin);

        if(strcmp(input, "exit") == 0) {
            break;
        }

        char *command = strtok(input, " ");
        int num_arguments = 0;
        char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

        while((arguments[num_arguments] = strtok(NULL, " "))!= NULL) {
            num_arguments++;
        }

        if(num_arguments > MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            continue;
        }

        for(int i = 0; i < num_arguments; i++) {
            int arg_length = strlen(arguments[i]);

            if(arg_length > MAX_ARG_LENGTH) {
                printf("Error: Argument too long.\n");
                free(arguments);
                continue;
            }
        }

        commands[num_commands].command = strdup(command);
        commands[num_commands].arguments = arguments;
        commands[num_commands].num_arguments = num_arguments;
        num_commands++;
    }

    for(int i = 0; i < num_commands; i++) {
        printf("Command %d: %s\n", i, commands[i].command);

        for(int j = 0; j < commands[i].num_arguments; j++) {
            printf("\tArgument %d: %s\n", j, commands[i].arguments[j]);
        }
    }

    return 0;
}