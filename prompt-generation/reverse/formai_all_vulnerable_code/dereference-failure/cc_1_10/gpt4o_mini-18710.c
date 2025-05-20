//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_ARGS 10

// Function prototypes
void print_prompt();
char *read_command();
char **parse_command(char *cmd);
int execute_command(char **args);
void list_files();
void free_arguments(char **args);

int main() {
    char *command;
    char **args;

    while (1) {
        print_prompt();
        command = read_command();
        args = parse_command(command);

        if (args[0] == NULL) {
            free(command);
            free_arguments(args);
            continue; // Empty command
        }

        if (strcmp(args[0], "exit") == 0) {
            free(command);
            free_arguments(args);
            break; // Exit the shell
        } else if (strcmp(args[0], "ls") == 0) {
            list_files();
        } else {
            if (execute_command(args) == -1) {
                fprintf(stderr, "Error executing command: %s\n", args[0]);
            }
        }

        free(command);
        free_arguments(args);
    }

    return 0;
}

void print_prompt() {
    printf("myshell> ");
}

char *read_command() {
    char *cmd = malloc(MAX_CMD_LEN);
    if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }
    cmd[strcspn(cmd, "\n")] = 0; // Remove the newline character
    return cmd;
}

char **parse_command(char *cmd) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int i = 0;

    arg = strtok(cmd, " ");
    while (arg != NULL && i < MAX_ARGS - 1) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL; // Null-terminate the argument list
    return args;
}

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        return -1;
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 0; // Command executed
}

void list_files() {
    DIR *d;
    struct dirent *dir;
    
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("opendir");
    }
}

void free_arguments(char **args) {
    free(args);
}