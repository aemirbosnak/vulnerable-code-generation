//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

typedef struct {
    char *command;
    int frequency;
} Command;

void loadCommands(Command commands[], int numCommands, FILE *fp) {
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= numCommands) {
            printf("Error: Too many commands.\n");
            exit(1);
        }

        char *command = strtok(line, " ");
        commands[i].command = strdup(command);
        commands[i].frequency = 1;

        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <commands_file> <program>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open commands file.\n");
        return 1;
    }

    Command commands[MAX_COMMANDS];
    int numCommands = 0;

    loadCommands(commands, MAX_COMMANDS, fp);
    fclose(fp);

    char **args = malloc(sizeof(char *) * (argc - 2));
    for (int i = 2; i < argc; i++) {
        args[i - 2] = strdup(argv[i]);
    }

    int pid = fork();
    if (pid == 0) {
        for (int i = 0; i < numCommands; i++) {
            if (strcmp(commands[i].command, argv[2]) == 0) {
                commands[i].frequency++;
            }
        }

        execvp(argv[2], args);
        printf("Error: Cannot execute %s.\n", argv[2]);
        return 1;
    } else {
        wait(NULL);

        fp = fopen("boot_log", "w");
        if (fp == NULL) {
            printf("Error: Cannot open boot log file.\n");
            return 1;
        }

        for (int i = 0; i < numCommands; i++) {
            fprintf(fp, "%s: %d\n", commands[i].command, commands[i].frequency);
        }

        fclose(fp);
    }

    return 0;
}