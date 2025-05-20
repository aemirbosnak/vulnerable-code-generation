//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " "

char **split_string(char *string) {
    int count = 0, i = 0;
    char **tokens = malloc(1024 * sizeof(char*));
    char *token;

    while ((token = strtok(string, DELIM))) {
        tokens[count++] = token;
        if (count >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: Command too long.\n");
            exit(1);
        }
        i += strlen(token) + 1;
        if (i >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: Command too long.\n");
            exit(1);
        }
    }
    tokens[count] = NULL;
    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[1024];
    char **tokens;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        if (fgets(input, 1024, stdin) == NULL) {
            fprintf(stderr, "Error: Input too long.\n");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0';

        tokens = split_string(input);
        execute_command(tokens);
    }

    return 0;
}