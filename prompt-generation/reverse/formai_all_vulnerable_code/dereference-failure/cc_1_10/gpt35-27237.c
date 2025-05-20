//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#define MAX_PATH_LENGTH 100

int execute_command(char** args);
char** parse_command(char* command, int* num_args);
void print_prompt();

int main() {
    while(1) {
        print_prompt();

        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';

        int num_args;
        char** args = parse_command(command, &num_args);

        execute_command(args);

        free(args);
    }

    return 0;
}

void print_prompt() {
    char* username = getenv("USER");
    char cwd[MAX_PATH_LENGTH];
    getcwd(cwd, sizeof(cwd));

    printf("%s@%s$ ", username, cwd);
}

char** parse_command(char* command, int* num_args) {
    // Count the number of arguments and allocate memory for them
    *num_args = 0;
    char* arg = strtok(command, " ");
    while(arg != NULL) {
        (*num_args)++;
        arg = strtok(NULL, " ");
    }

    char** args = malloc((*num_args + 1) * sizeof(char*));
    args[*num_args] = NULL;

    // Parse each argument and copy them to the args array
    char* tmp_command = strdup(command);
    int i = 0;
    arg = strtok(tmp_command, " ");
    while(arg != NULL) {
        args[i] = malloc((strlen(arg) + 1) * sizeof(char));
        strcpy(args[i], arg);
        arg = strtok(NULL, " ");
        i++;
    }

    free(tmp_command);

    return args;
}

int execute_command(char** args) {
    int status;
    pid_t pid = fork();

    // Child process
    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } 

    // Fork error
    else if(pid < 0) {
        perror("Forking error");
    }

    // Parent process
    else {
        waitpid(pid, &status, 0);
    }

    return 0;
}