//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 80 // Max number of characters in a command
#define MAXARGS 10 // Max number of arguments in a command
#define MAXHISTORY 20 // Max number of commands in history

char* history[MAXHISTORY]; // history array to store commands
int history_count = 0; // number of commands in history

char** tokenize_input(char *input) {
    char **args = malloc(MAXARGS * sizeof(char *));
    char *arg;
    int arg_count = 0;

    arg = strtok(input, " ");
    while (arg != NULL && arg_count < MAXARGS - 1) {
        args[arg_count++] = arg;
        arg = strtok(NULL, " ");
    }
    args[arg_count] = NULL;
    return args;
}

void print_history() {
    int i;
    for (i = 0; i < history_count; i++) {
        printf("%d %s\n", i+1, history[i]);
    }
}

void add_to_history(char *input) {
    if (history_count == MAXHISTORY) {
        free(history[0]);
        for (int i = 1; i < MAXHISTORY; i++) {
            history[i-1] = history[i];
        }
        history_count--;
    }
    history[history_count++] = strdup(input);
}

int main() {
    char input[MAX];
    char **args;
    int status;
    pid_t pid;

    while (1) {
        printf("myshell >> ");
        fflush(stdout);

        fgets(input, MAX, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "history") == 0) {
            print_history();
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (strlen(input) == 0) {
            continue;
        }

        args = tokenize_input(input);

        pid = fork();

        if (pid < 0) {
            printf("Error forking.\n");
        }
        else if (pid == 0) {
            execvp(args[0], args);
        }
        else {
            waitpid(pid, &status, 0);
        }

        add_to_history(input);
    }

    return 0;
}