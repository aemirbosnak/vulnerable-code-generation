//GEMINI-pro DATASET v1.0 Category: System administration ; Style: retro
// C System Administration Example in a Retro Style

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

// Predefined Macros
#define MAX_COMMAND_LEN 1024
#define MAX_HISTORY_SIZE 10
#define PROMPT ">"

// Function Declarations
void print_welcome_banner();
char *read_line(char *line, size_t size);
char **parse_command(char *line);
int execute_command(char **argv);
void add_to_history(char *command);
void print_history();
void show_help();

// Global Variables
char *history[MAX_HISTORY_SIZE];
int history_index = 0;

// Start of Program
int main() {
    print_welcome_banner();

    char line[MAX_COMMAND_LEN];
    while (1) {
        printf("%s ", PROMPT);
        char *command_line = read_line(line, MAX_COMMAND_LEN);

        if (!command_line) {
            printf("Error reading command.\n");
            continue;
        }

        char **argv = parse_command(command_line);

        if (!argv) {
            printf("Error parsing command.\n");
            continue;
        }

        if (!strcmp(argv[0], "exit")) {
            break;
        } else if (!strcmp(argv[0], "h") || !strcmp(argv[0], "help")) {
            show_help();
            continue;
        } else if (!strcmp(argv[0], "history")) {
            print_history();
            continue;
        }

        add_to_history(command_line);

        int status = execute_command(argv);
    }

    printf("\nGoodbye!\n");
    return 0;
}

// Function Definitions
void print_welcome_banner() {
    printf("\n                                  __________________\n");
    printf("                                 |* RETRO SHELL 2023 *|\n");
    printf("                                 |__________________|\n\n");
}

char *read_line(char *line, size_t size) {
    return fgets(line, size, stdin);
}

char **parse_command(char *line) {
    char *argv[MAX_COMMAND_LEN];
    char *token = strtok(line, " ");
    int i = 0;

    while (token) {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }

    argv[i] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error creating child process");
        return -1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv)) {
            perror("Error executing command");
        }
    } else {
        int status;
        wait(&status);
    }

    return 0;
}

void add_to_history(char *command) {
    history[history_index++] = strdup(command);

    if (history_index >= MAX_HISTORY_SIZE) {
        history_index = 0;
    }
}

void print_history() {
    for (int i = 0; i < MAX_HISTORY_SIZE; i++) {
        if (history[i]) {
            printf("%d: %s\n", i + 1, history[i]);
        }
    }
}

void show_help() {
    printf("Available commands:\n");
    printf("    exit: exit the shell\n");
    printf("    h or help: show this help message\n");
    printf("    history: show the command history\n");
}