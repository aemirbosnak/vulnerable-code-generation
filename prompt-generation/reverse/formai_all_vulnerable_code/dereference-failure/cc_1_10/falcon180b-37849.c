//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 10

char *args[MAX_ARGS];
int num_args;
int background = 0;
int foreground = 0;

void sigchild(int signo)
{
    int status;
    waitpid(-1, &status, WNOHANG);
}

int launch_process(char *cmd)
{
    pid_t pid;
    int i;

    if (num_args == 0) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

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
        if (foreground) {
            for (i = 0; i < num_args; i++) {
                printf("%s ", args[i]);
            }
            printf("\n");
        }
        if (background) {
            fprintf(stderr, "[%d] %s", pid, cmd);
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    char line[MAX_LINE];
    char *token;
    int i;

    signal(SIGCHLD, sigchild);

    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        num_args = 0;
        args[num_args++] = strtok(line, " ");

        while ((token = strtok(NULL, " "))!= NULL) {
            if (num_args >= MAX_ARGS) {
                fprintf(stderr, "Too many arguments.\n");
                continue;
            }
            args[num_args++] = token;
        }

        if (num_args == 0) {
            fprintf(stderr, "No command specified.\n");
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "bg") == 0) {
            background = 1;
        } else if (strcmp(args[0], "fg") == 0) {
            foreground = 1;
        } else {
            launch_process(line);
        }
    }

    return 0;
}