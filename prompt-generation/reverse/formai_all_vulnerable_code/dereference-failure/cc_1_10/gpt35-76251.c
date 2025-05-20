//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024

int executeCommand(char **args) {
    int pid, status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: unknown command\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Error: unable to fork\n");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

char *readLine(void) {
    int bufferSize = MAX_LENGTH;
    char *line = malloc(sizeof(char) * bufferSize);
    int index = 0, inputChar;

    if(!line) {
        printf("Error: memory not allocated\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        inputChar = getchar();

        if (inputChar == EOF || inputChar == '\n') {
            line[index] = '\0';
            return line;
        } else {
            line[index] = inputChar;
        }
        index++;

        if(index >= bufferSize) {
            bufferSize += MAX_LENGTH;
            line = realloc(line, bufferSize);
            if(!line) {
                printf("Error: memory not allocated\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **parseLine(char *line) {
    int bufferSize = MAX_LENGTH, index = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;

    if(!tokens) {
        printf("Error: memory not allocated\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[index] = token;
        index++;

        if(index >= bufferSize) {
          bufferSize += MAX_LENGTH;
          tokens = realloc(tokens, bufferSize * sizeof(char*));
          if (!tokens) {
              printf("Error: memory not allocated\n");
              exit(EXIT_FAILURE);
          }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[index] = NULL;
    return tokens;
}

int main(int argc, char *argv[]) {
    char *line, **args;
    int status;

    do {
        printf("unix-like-shell> ");
        line = readLine();
        args = parseLine(line);
        status = executeCommand(args);

        free(line);
        free(args);
    } while (status);
    return 0;
}