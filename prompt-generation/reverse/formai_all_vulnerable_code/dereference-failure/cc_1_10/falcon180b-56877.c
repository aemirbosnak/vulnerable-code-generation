//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 20
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENT_LENGTH 20
#define DELIMITER " "

typedef struct {
    char *command;
    char *arguments[MAX_ARGUMENTS];
    int num_arguments;
} Command;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }

    int process_id = atoi(argv[1]);

    char process_name[MAX_COMMAND_LENGTH];
    snprintf(process_name, MAX_COMMAND_LENGTH, "/proc/%d/comm", process_id);

    FILE *fp = fopen(process_name, "r");
    if (fp == NULL) {
        printf("Error: Process not found.\n");
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    if (fgets(command, MAX_COMMAND_LENGTH, fp) == NULL) {
        printf("Error: Process not found.\n");
        exit(1);
    }

    fclose(fp);

    command[strcspn(command, DELIMITER)] = '\0';

    int num_arguments = 0;
    char *token = strtok(command, DELIMITER);
    while (token!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            break;
        }

        char argument[MAX_ARGUMENT_LENGTH];
        strncpy(argument, token, MAX_ARGUMENT_LENGTH);
        argument[MAX_ARGUMENT_LENGTH - 1] = '\0';

        Command *cmd = malloc(sizeof(Command));
        cmd->command = strdup(command);
        cmd->arguments[num_arguments] = strdup(argument);
        cmd->num_arguments = num_arguments + 1;
        num_arguments++;

        printf("Command: %s\n", cmd->command);
        for (int i = 0; i < cmd->num_arguments; i++) {
            printf("  Argument %d: %s\n", i, cmd->arguments[i]);
        }

        free(cmd);

        token = strtok(NULL, DELIMITER);
    }

    return 0;
}