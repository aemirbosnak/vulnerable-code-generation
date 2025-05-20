//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_LINE_LENGTH 1024

// Function prototypes
char **split_string(char *str);
int execute_command(char **args);
int execute_builtin(char **args);
int launch_shell();

int main() {
    char input[MAX_LINE_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Shell! Type 'exit' to quit.\n");
    while(1) {
        fgets(input, MAX_LINE_LENGTH, stdin);
        args = split_string(input);
        if(strcmp(args[0], "exit") == 0) {
            break;
        }
        pid = fork();
        if(pid == -1) {
            printf("Error forking process.\n");
        } else if(pid == 0) {
            launch_shell();
        } else {
            wait(NULL);
        }
    }
    return 0;
}

// Split a string into an array of strings
char **split_string(char *str) {
    int i = 0;
    char **tokens = malloc(sizeof(char *));
    char delim[] = " \t\r\n";
    char *token = strtok(str, delim);

    while(token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return tokens;
}

// Execute a command
int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        printf("Error: Command not found.\n");
        return 1;
    }

    pid = fork();
    if(pid == -1) {
        printf("Error forking process.\n");
        return 1;
    } else if(pid == 0) {
        execvp(args[0], args);
        printf("Error: %s not found.\n", args[0]);
        exit(1);
    } else {
        wait(&status);
        if(WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            printf("Error: Command terminated abnormally.\n");
            return 1;
        }
    }
}

// Execute a builtin command
int execute_builtin(char **args) {
    if(strcmp(args[0], "cd") == 0) {
        if(args[1] == NULL) {
            printf("Error: Directory not specified.\n");
        } else {
            if(chdir(args[1])!= 0) {
                printf("Error: Directory not found.\n");
            }
        }
    } else if(strcmp(args[0], "pwd") == 0) {
        char cwd[MAX_COMMAND_LENGTH];
        getcwd(cwd, MAX_COMMAND_LENGTH);
        printf("%s\n", cwd);
    } else {
        printf("Error: Command not found.\n");
    }
    return 0;
}

// Launch the shell
int launch_shell() {
    char input[MAX_LINE_LENGTH];
    char **args;

    while(1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        args = split_string(input);

        if(strcmp(args[0], "exit") == 0) {
            break;
        }

        if(execute_builtin(args)!= 0) {
            execute_command(args);
        }
    }
    return 0;
}