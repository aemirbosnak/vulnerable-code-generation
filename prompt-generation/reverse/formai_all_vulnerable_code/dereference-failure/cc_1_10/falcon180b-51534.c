//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMANDS 100

typedef struct {
    char *command;
    int priority;
} command_t;

int compare_commands(const void *a, const void *b) {
    const command_t *cmd1 = a;
    const command_t *cmd2 = b;

    return cmd1->priority - cmd2->priority;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];

    fp = fopen("boot.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open boot.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_commands >= MAX_COMMANDS) {
            printf("Error: Too many commands in boot.txt\n");
            exit(1);
        }

        char *cmd = strtok(line, " ");
        int priority = 0;

        if (strcmp(cmd, "high") == 0) {
            priority = 10;
        } else if (strcmp(cmd, "medium") == 0) {
            priority = 5;
        } else if (strcmp(cmd, "low") == 0) {
            priority = 1;
        } else {
            printf("Error: Invalid priority in boot.txt\n");
            exit(1);
        }

        commands[num_commands].command = strdup(line);
        commands[num_commands].priority = priority;

        num_commands++;
    }

    fclose(fp);

    qsort(commands, num_commands, sizeof(command_t), compare_commands);

    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].command);
    }

    return 0;
}