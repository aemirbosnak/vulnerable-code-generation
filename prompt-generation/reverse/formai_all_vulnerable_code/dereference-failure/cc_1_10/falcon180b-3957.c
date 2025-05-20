//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0
#define ERR_EXIT(m) \
    do { perror(m); exit(EXIT_FAILURE); } while (0)
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, DELIM);
    int count = 0;
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

void sigint_handler(int signum) {
    printf("\nInterrupted by user.\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: %s [-i]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int interactive_mode = FALSE;
    if (argc == 2 && strcmp(argv[1], "-i") == 0) {
        interactive_mode = TRUE;
    }

    signal(SIGINT, sigint_handler);

    char input[MAX_COMMAND_LENGTH];
    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **tokens = split_string(input);
        if (tokens[0] == NULL) {
            continue;
        }
        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                ERR_EXIT("execvp");
            }
        } else if (pid < 0) {
            ERR_EXIT("fork");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
        if (interactive_mode) {
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}