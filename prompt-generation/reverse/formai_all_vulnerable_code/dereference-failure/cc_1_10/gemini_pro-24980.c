//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_LINE 1024
#define MAX_ARGS 128

// Function to split the input command into arguments
char **split_args(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

// Function to execute the input command
int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // Error
        perror("fork");
        return 1;
    }
}

// Function to handle the built-in command "cd"
int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: no directory specified\n");
        return 1;
    }
    if (chdir(args[1]) != 0) {
        perror("cd");
        return 1;
    }
    return 0;
}

// Function to handle the built-in command "ls"
int ls(char **args) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(".")) == NULL) {
        perror("opendir");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}

// Function to handle the built-in command "exit"
int exit_shell(char **args) {
    exit(0);
}

// Function to handle the built-in commands
int handle_built_in(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        return cd(args);
    } else if (strcmp(args[0], "ls") == 0) {
        return ls(args);
    } else if (strcmp(args[0], "exit") == 0) {
        return exit_shell(args);
    }
    return 1;
}

// Main function
int main() {
    char line[MAX_LINE];
    char **args;
    int status;

    while (1) {
        printf("osh> ");
        fflush(stdout);

        // Read the input command
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;
        }

        // Remove the trailing newline character
        line[strlen(line) - 1] = '\0';

        // Split the input command into arguments
        args = split_args(line);

        // Handle the built-in commands
        if (handle_built_in(args)) {
            // Execute the input command
            status = execute_command(args);
        }

        // Free the allocated memory
        free(args);
    }

    return 0;
}