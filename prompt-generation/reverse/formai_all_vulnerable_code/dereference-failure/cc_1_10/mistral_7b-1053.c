//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_CMDS 64
#define MAX_CMD_LEN 256

struct cmd {
    char *cmd;
    pid_t pid;
    int status;
    struct cmd *next;
};

struct cmd *cmd_list = NULL;

void print_prompt() {
    printf("\033[1;31m%s@%s:\033[0m%s$ ", "Woodstock", "shell", "> ");
}

void sigint_handler(int sig) {
    struct cmd *current = cmd_list;

    while (current != NULL) {
        if (current->pid > 0) {
            kill(current->pid, SIGINT);
            current->status = 128 + SIGINT;
        }
        current = current->next;
    }
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED | WNOHANG);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            printf("\033[1;32m[+]\033[0m Command executed with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("\033[1;31m[-]\033[0m Command terminated by signal: %d\n", WTERMSIG(status));
        }
    }

    free(args);
    return 1;
}

char **split_line(char *line) {
    int bufsize = 64, position = 0, i = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(line, " ");

    while (token != NULL) {
        tokens[i] = token;
        i++;

        if (++position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

int main() {
    char line[MAX_INPUT_SIZE];
    char **args;
    int should_run = 1;

    signal(SIGINT, sigint_handler);

    while (should_run) {
        print_prompt();
        fgets(line, MAX_INPUT_SIZE, stdin);

        if (strcmp(line, "exit\n") == 0) {
            should_run = 0;
            continue;
        }

        args = split_line(line);
        execute_command(args);

        free(args);
    }

    return EXIT_SUCCESS;
}