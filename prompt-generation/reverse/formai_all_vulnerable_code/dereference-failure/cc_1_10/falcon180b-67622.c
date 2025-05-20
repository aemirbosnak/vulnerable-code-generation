//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NUM_PROCESSES 4
#define MAX_COMMAND_LENGTH 100

char **command_argv[NUM_PROCESSES];
int command_argc[NUM_PROCESSES];

void execute_command(int index) {
    pid_t pid = fork();

    if (pid == 0) {
        char *command = command_argv[index][0];
        int argc = command_argc[index];

        execvp(command, command_argv[index]);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void read_commands_from_file(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        char line[MAX_COMMAND_LENGTH];
        fgets(line, MAX_COMMAND_LENGTH, file);

        if (line[0] == '\n') {
            continue;
        }

        char *command = strtok(line, " ");
        command_argv[i] = malloc(sizeof(char *) * (strlen(command) + 1));
        strcpy(command_argv[i], command);

        int argc = 1;
        while ((command = strtok(NULL, " "))!= NULL) {
            command_argv[i] = realloc(command_argv[i], sizeof(char *) * (argc + 1));
            strcpy(command_argv[i][argc], command);
            argc++;
        }

        command_argc[i] = argc;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_PROCESSES; i++) {
        char filename[20];
        sprintf(filename, "process%d.txt", i + 1);
        read_commands_from_file(filename);
    }

    bool finished[NUM_PROCESSES] = {false};

    while (!finished[0] ||!finished[1] ||!finished[2] ||!finished[3]) {
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finished[i]) {
                execute_command(i);
            }
        }
    }

    return 0;
}