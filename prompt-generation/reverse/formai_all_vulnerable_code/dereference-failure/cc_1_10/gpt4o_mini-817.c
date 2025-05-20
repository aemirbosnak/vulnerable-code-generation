//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 100
#define MAX_ARG_SIZE 10
#define PROMPT "NeonShell> "

void clear_buffer(char *buffer) {
    memset(buffer, 0, strlen(buffer));
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("NeonShell Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("NeonShell Error");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);
    }
}

void parse_input(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void display_banner() {
    printf("\033[1;36m");
    printf("==========================================\n");
    printf("          Welcome to NeonShell           \n");
    printf("    A Cyberpunk-inspired Command Shell    \n");
    printf("==========================================\n");
    printf("\033[0m");
}

int main() {
    char *input = malloc(MAX_INPUT_SIZE);
    char *args[MAX_ARG_SIZE];
    
    display_banner();

    while (1) {
        printf("%s", PROMPT);
        clear_buffer(input);
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("NeonShell Error");
            continue;
        }
        
        if (strcmp(input, "exit\n") == 0) {
            printf("Shutting down NeonShell...\n");
            break;
        }

        parse_input(input, args);
        
        if (args[0] == NULL) {
            continue; // Empty input
        }

        execute_command(args);
    }

    free(input);
    return 0;
}