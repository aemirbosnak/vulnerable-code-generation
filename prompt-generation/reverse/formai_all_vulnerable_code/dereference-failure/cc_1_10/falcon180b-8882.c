//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Happy Shell! Type 'help' for a list of commands.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char **args = split_command(input);
        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;
        else if (strcmp(args[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  exit\n");
            printf("  help\n");
        } else {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("fork");
            } else if (child_pid > 0) {
                int status;
                waitpid(child_pid, &status, 0);
            } else {
                signal(SIGINT, handle_signal);
                execute_command(args);
                exit(0);
            }
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *));
    args[0] = strtok(command, DELIM);
    int num_args = 1;

    while ((args[num_args] = strtok(NULL, DELIM))!= NULL) {
        num_args++;
        args = realloc(args, sizeof(char *) * num_args);
    }
    args[num_args] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
        }
    }

    return 0;
}

void handle_signal(int signum) {
    printf("Interrupted by signal %d\n", signum);
    exit(1);
}