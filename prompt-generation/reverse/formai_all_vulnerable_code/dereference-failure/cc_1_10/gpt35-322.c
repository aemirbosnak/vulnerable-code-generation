//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Maximum number of arguments a user can enter */
#define MAX_ARGS 10
/* Maximum length of an argument */
#define ARG_LEN 20
/* Maximum length of prompt */
#define MAX_PROMPT_LEN 50
/* Maximum length of command */
#define MAX_COMMAND_LEN 255

/* Function to print prompt */
void print_prompt(char* prompt) {
    printf("%s ", prompt);
}

/* Function to read user input */
void read_input(char* input) {
    fgets(input, MAX_COMMAND_LEN, stdin);
    input[strlen(input) - 1] = '\0'; /* Replace newline with null character */
}

/* Function to tokenize user input */
char** tokenize_input(char* input) {
    char** args = (char**) malloc(MAX_ARGS * sizeof(char*));
    char* arg = strtok(input, " ");
    int i = 0;
    while (arg != NULL) {
        args[i] = (char*) malloc(ARG_LEN * sizeof(char));
        strncpy(args[i], arg, ARG_LEN);
        arg = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL; /* Add NULL terminator */
    return args;
}

/* Function to execute command */
void execute_command(char** args) {
    pid_t pid = fork();
    if (pid == 0) { /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("exec");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0) { /* Error */
        perror("fork");
    }
    else { /* Parent process */
        wait(NULL);
    }
}

/* Function to handle signals */
void handle_signal(int signal) {
    printf("\n");
    print_prompt("myshell"); /* Print prompt again */
}

int main() {
    char input[MAX_COMMAND_LEN];
    char** args;
    char prompt[MAX_PROMPT_LEN] = "myshell";
    signal(SIGINT, SIG_IGN); /* Ignore Ctrl+C */
    signal(SIGINT, handle_signal); /* Register Ctrl+C handler */
    while (1) {
        print_prompt(prompt);
        read_input(input);
        args = tokenize_input(input);
        execute_command(args);
    }
    return 0;
}