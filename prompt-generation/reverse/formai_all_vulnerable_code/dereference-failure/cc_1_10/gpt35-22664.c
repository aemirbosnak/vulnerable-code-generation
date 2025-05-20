//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** split(char* str, const char* delim) {
    // split the string by delimiter
    char* tok;
    char** tokens = malloc(128 * sizeof(char*));
    int i = 0;
    tok = strtok(str, delim);

    while (tok != NULL) {
        tokens[i++] = tok;
        tok = strtok(NULL, delim);
    }

    tokens[i] = NULL;
    return tokens;
}

char* read_line() {
    // read the command line input
    char* line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

void execute(char* command) {
    // execute the command
    char** args = split(command, " ");

    if (strcmp(args[0], "ls") == 0) {
        execlp("ls", "ls", args[1], NULL);
    } else if (strcmp(args[0], "pwd") == 0) {
        execlp("pwd", "pwd", NULL);
    } else {
        printf("Invalid command!\n");
    }

    free(args);
}

int main() {
    char* line;
    int status = 1;

    while (status) {
        printf(">> ");
        line = read_line();
        execute(line);
        free(line);
    }

    return 0;
}