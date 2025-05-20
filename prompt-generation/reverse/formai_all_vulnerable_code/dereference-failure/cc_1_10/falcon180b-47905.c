//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE_SIZE 1024

char **split_line(char *line) {
    int buf_size = 0, words = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while ((token = strtok(line, " "))!= NULL) {
        words++;
    }

    tokens = (char **)malloc((words + 1) * sizeof(char *));

    strcpy(line, "");
    strcat(line, line);
    strcat(line, " ");

    token = strtok(line, " ");
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
        }
    }
}

void loop(void) {
    char input[MAX_LINE_SIZE];
    char **tokens;

    printf("> ");
    fgets(input, MAX_LINE_SIZE, stdin);

    tokens = split_line(input);
    execute_command(tokens);

    free(tokens);
}

void setup_signals(void) {
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
}

int main(void) {
    setup_signals();

    loop();

    return 0;
}