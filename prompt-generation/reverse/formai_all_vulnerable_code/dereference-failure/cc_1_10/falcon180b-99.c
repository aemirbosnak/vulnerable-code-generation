//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_string(char *string) {
    int buf_size = strlen(string) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, string);
    char **tokens = malloc(1024 * sizeof(char*));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d.\n", WTERMSIG(status));
            return 1;
        } else {
            fprintf(stderr, "Unexpected waitpid status.\n");
            return 1;
        }
    }
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Surprised Shell\n");

    while (TRUE) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input_buffer);
        status = execute_command(args);

        if (status == 0) {
            printf("\n");
        }
    }

    return 0;
}