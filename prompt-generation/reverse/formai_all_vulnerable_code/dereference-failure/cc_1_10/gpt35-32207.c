//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_HISTORY 10

char* history[MAX_HISTORY];
int history_count = 0;

void execute(char** args) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0) {
        perror("Fork failed");
    }
    else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void add_to_history(char* command) {
    if (history_count >= MAX_HISTORY) {
        free(history[0]);
        memmove(&history[0], &history[1], (MAX_HISTORY - 1) * sizeof(history[0]));
        history_count--;
    }
    history[history_count] = strdup(command);
    history_count++;
}

int main(void) {
    char* args[MAX_LINE/2 + 1];
    char* command;
    int should_run = 1;
    while (should_run) {
        printf("osh> ");
        fflush(stdout);
        command = calloc(MAX_LINE+1, sizeof(*command));
        fgets(command, MAX_LINE+1, stdin);
        if (strlen(command) > 1) {
            if (command[strlen(command)-1] == '\n') {
                command[strlen(command)-1] = '\0';
            }
            add_to_history(command);
            int i = 0;
            args[i] = strtok(command, " ");
            while (args[i] != NULL) {
                i++;
                args[i] = strtok(NULL, " ");
            }
            if (strcmp(args[0], "exit") == 0) {
                should_run = 0;
                break;
            }
            if (strcmp(args[0], "history") == 0) {
                int i;
                for (i = 0; i < history_count; i++) {
                    printf("%d. %s\n", i+1, history[i]);
                }
                continue;
            }
            execute(args);
        }
        free(command);
    }
    int i;
    for (i = 0; i < history_count; i++) {
        free(history[i]);
    }
    return 0;
}