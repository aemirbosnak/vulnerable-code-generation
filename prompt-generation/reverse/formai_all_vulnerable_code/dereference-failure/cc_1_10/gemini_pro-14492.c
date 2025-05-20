//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
// Terminal.c - Post-Apocalyptic Shell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Rusty machine gun banner
void banner() {
    printf("\n");
    printf("                _______\n");
    printf("       ___  _ _|_   __ \\ \n");
    printf("      / _ \\| | | | | |__) |\n");
    printf("     | (_) | | | | |___ / \n");
    printf("      \\___/|_|_|_|_____/  \n");
    printf("\n");
    printf("  Terminal.c - Post-Apocalyptic Shell\n");
    printf("\n");
}

// Global environment
char *envp[9] = { "HOME=/home/nutcase", "SHELL=/bin/terminal", "TERM=xterm", "PS1=~> ", "PATH=/bin:/usr/bin", "MANPATH=/usr/share/man", "INFOPATH=/usr/share/info", "HISTFILE=/home/nutcase/.terminal_history", NULL };

// Command history
#define HISTORY_SIZE 10
char *history[HISTORY_SIZE];
int history_head = 0;

// Main terminal loop
int main() {
    // Display banner
    banner();

    // Loop forever
    while (1) {
        // Read command from user
        char *command = NULL;
        size_t n = 0;
        printf("~> ");
        getline(&command, &n, stdin);
        if (strlen(command) == 0) continue;

        // Store command in history
        int index = (history_head + 1) % HISTORY_SIZE;
        history[index] = command;
        if (index != 0) history_head = index;

        // Execute command
        int status;
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execve(command, NULL, envp);
            perror("execve");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            wait(&status);
        }
    }

    return 0;
}