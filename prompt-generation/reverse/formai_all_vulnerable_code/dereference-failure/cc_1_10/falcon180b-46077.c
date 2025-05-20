//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(void) {
    char input[MAX_LINE_LENGTH];
    char **args;
    int background = 0;

    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);

        args = split_line(input);
        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "bg") == 0) {
            background = 1;
        } else if (strcmp(args[0], "fg") == 0) {
            background = 0;
        } else {
            execute_command(args);
        }
    }
}