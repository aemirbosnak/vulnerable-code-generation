//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMANDS 1000
#define MAX_COMMAND_LENGTH 1000

typedef struct {
    char *command;
    int frequency;
    time_t timestamp;
} Command;

Command commands[MAX_COMMANDS];
int num_commands = 0;

void add_command(char *command) {
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].frequency++;
            commands[i].timestamp = time(NULL);
            return;
        }
    }
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: too many commands\n");
        return;
    }
    strncpy(commands[num_commands].command, command, MAX_COMMAND_LENGTH - 1);
    commands[num_commands].command[MAX_COMMAND_LENGTH - 1] = '\0';
    commands[num_commands].frequency = 1;
    commands[num_commands].timestamp = time(NULL);
    num_commands++;
}

void sort_commands() {
    int i, j;
    for (i = 0; i < num_commands - 1; i++) {
        for (j = i + 1; j < num_commands; j++) {
            if (commands[j].frequency > commands[i].frequency) {
                Command temp = commands[i];
                commands[i] = commands[j];
                commands[j] = temp;
            }
        }
    }
}

void print_commands() {
    int i;
    for (i = 0; i < num_commands; i++) {
        printf("%s (%d)\n", commands[i].command, commands[i].frequency);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        add_command(command);
        sort_commands();
        print_commands();
    }
    return 0;
}