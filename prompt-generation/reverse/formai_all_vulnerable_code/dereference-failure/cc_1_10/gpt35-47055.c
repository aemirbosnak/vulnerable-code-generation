//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"

void execute(char **args);
char *read_line(void);
char **split_line(char *line);

int main(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        execute(args);

        free(line);
        free(args);
    } while (status != -1);

    return 0;
}

void execute(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork Error\n");
        return;
    }

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command Not Found\n");
        }
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }
}

char *read_line(void) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    int c;

    if (!buffer) {
        printf("Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }

        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            buffer = realloc(buffer, sizeof(char) * buffer_size);
            if (!buffer) {
                printf("Allocation Error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **split_line(char *line) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        printf("Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITER);

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                printf("Allocation Error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }

    tokens[position] = NULL;
    return tokens;
}