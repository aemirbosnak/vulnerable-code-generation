//Falcon-180B DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_LENGTH 100
#define MAX_ARG_LENGTH 50

typedef struct {
    char *command;
    char *args[MAX_ARG_LENGTH];
} command_t;

void execute_command(command_t *command) {
    pid_t pid;
    int status;
    int i;

    for (i = 0; i < MAX_ARG_LENGTH; i++) {
        if (command->args[i] == NULL) {
            break;
        }
    }

    pid = fork();

    if (pid == 0) {
        execvp(command->command, command->args);
        printf("Error: Failed to execute command.\n");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Error: Failed to fork.\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}

void parse_line(char *line, command_t *command) {
    char *token;
    int i = 0;

    token = strtok(line, " ");

    if (token == NULL) {
        return;
    }

    strcpy(command->command, token);

    while ((token = strtok(NULL, " "))!= NULL) {
        if (i >= MAX_ARG_LENGTH) {
            break;
        }

        strcpy(command->args[i], token);
        i++;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    command_t command;

    file = fopen("/etc/shadow", "r");

    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (line[0]!= '#') {
            parse_line(line, &command);
            execute_command(&command);
        }
    }

    fclose(file);

    return 0;
}