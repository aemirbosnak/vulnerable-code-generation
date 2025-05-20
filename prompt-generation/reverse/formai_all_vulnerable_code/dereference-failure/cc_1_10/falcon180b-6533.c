//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_COMMANDS 100

typedef struct {
    char *command;
    int priority;
} Command;

int compare_commands(const void *a, const void *b) {
    const Command *cmd1 = a;
    const Command *cmd2 = b;

    return cmd1->priority - cmd2->priority;
}

void execute_commands(Command *commands, int num_commands) {
    for (int i = 0; i < num_commands; i++) {
        printf("Executing command: %s\n", commands[i].command);
    }
}

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *command;
    int num_commands = 0;
    Command commands[MAX_NUM_COMMANDS];

    input_file = fopen("boot_commands.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        command = strtok(line, " ");
        if (command == NULL) {
            continue;
        }

        num_commands++;
        if (num_commands >= MAX_NUM_COMMANDS) {
            printf("Error: Maximum number of commands exceeded.\n");
            fclose(input_file);
            return 1;
        }

        commands[num_commands - 1].command = strdup(command);
        commands[num_commands - 1].priority = atoi(strtok(NULL, " "));
    }

    fclose(input_file);

    qsort(commands, num_commands, sizeof(Command), compare_commands);

    execute_commands(commands, num_commands);

    for (int i = 0; i < num_commands; i++) {
        free(commands[i].command);
    }

    return 0;
}