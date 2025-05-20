//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD 1024
#define MAX_ARG 100

void display_prompt() {
    printf("🌈 HappyShell > ");
}

void parse_input(char *input, char **args) {
    for (int i = 0; i < MAX_ARG; i++) {
        args[i] = strsep(&input, " ");
        if (args[i] == NULL) {
            break;
        }
    }
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("🌟 Fork failed");
        return;
    }

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("❌ Command execution failed");
        }
        exit(EXIT_FAILURE);
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void change_directory(char **args) {
    if (args[1] == NULL) {
        printf("🚀 Please provide a directory to change to.\n");
    } else if (chdir(args[1]) != 0) {
        perror("❌ Change directory failed");
    }
}

void list_directory() {
    system("ls -l");
}

void happy_exit() {
    printf("🌼 Exiting HappyShell. Stay joyful! 🌈\n");
    exit(0);
}

int main() {
    char input[MAX_CMD];
    char *args[MAX_ARG];

    printf("🎉 Welcome to HappyShell! 🌈\n");
    printf("Type your commands below and spread the joy!\n");

    while (1) {
        display_prompt();
        
        // Get user input
        if (fgets(input, MAX_CMD, stdin) == NULL) {
            printf("\n");
            continue;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // Parse the input into arguments
        parse_input(input, args);

        // Handle built-in commands
        if (args[0] == NULL) {
            continue; // No command entered
        } else if (strcmp(args[0], "exit") == 0) {
            happy_exit();
        } else if (strcmp(args[0], "cd") == 0) {
            change_directory(args);
            continue;
        } else if (strcmp(args[0], "ls") == 0) {
            list_directory();
            continue;
        }

        // Execute external commands
        execute_command(args);
    }

    return 0;
}