//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CMD_LENGTH 1024
#define ARG_LENGTH 128
#define MAX_ARGS 10

int run_command(char **args);
void parse_arguments(char *command_string, char **args);

int main(int argc, char **argv) {
    char cmd[CMD_LENGTH];
    char *args[MAX_ARGS];
    int exit_status = 0;

    // Configurables
    char prompt[] = "my_shell> ";

    while (1) {
        // Print prompt and get command
        printf("%s", prompt);
        fgets(cmd, CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = '\0'; // Remove trailing new line character

        // Exit command
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        // Parse command into arguments
        parse_arguments(cmd, args);

        // Run command
        exit_status = run_command(args);

        // Reset arguments
        for (int i = 0; i < MAX_ARGS; i++) {
            args[i] = NULL;
        }
    }

    return exit_status;
}

void parse_arguments(char *command_string, char **args) {
    char *arg_string = strtok(command_string, " ");
    int arg_num = 0;

    while (arg_string != NULL) {
        args[arg_num] = (char*) malloc(ARG_LENGTH);
        strcpy(args[arg_num], arg_string);

        arg_num++;
        arg_string = strtok(NULL, " ");
    }
}

int run_command(char **args) {
    int pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);

        // If we reach this line, the command failed to execute
        printf("Error executing command: %s\n", args[0]);
        exit(1);
    } else if (pid < 0) {
        // Fork failed
        printf("Fork failed");
        exit(1);
    } else {
        // Parent process
        int status = 0;
        waitpid(pid, &status, 0);

        return WEXITSTATUS(status);
    }
}