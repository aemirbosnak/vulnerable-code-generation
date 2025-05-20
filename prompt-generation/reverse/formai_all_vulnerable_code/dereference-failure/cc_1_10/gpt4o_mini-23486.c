//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100

void trim_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void execute_command(char* command) {
    char* args[MAX_ARG_LEN];
    char* token = strtok(command, " ");
    int i = 0;

    while (token != NULL && i < MAX_ARG_LEN - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting the shell. Goodbye! 👋\n");
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (i > 1) {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        } else {
            fprintf(stderr, "cd expects a directory\n");
        }
        return;
    }

    pid_t pid = fork();
    
    if (pid == -1) {
        perror("Fork failed");
        return;
    } else if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
            exit(EXIT_FAILURE); // Exit child process if exec fails
        }
    } else { // Parent process
        wait(NULL);
    }
}

void print_shell_prompt() {
    char cwd[MAX_CMD_LEN];
    getcwd(cwd, sizeof(cwd));
    printf("\n🌌 myShell [%s] > ", cwd);
}

int main() {
    char command[MAX_CMD_LEN];

    printf("Welcome to myShell! 🎉 Type 'exit' to leave anytime.\n");

    while (1) {
        print_shell_prompt();
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Error reading command");
            continue;
        }

        trim_newline(command);
        execute_command(command);
    }

    return 0;
}