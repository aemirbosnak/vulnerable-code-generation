//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string)
{
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        bufsize++;
        tokens = realloc(tokens, bufsize * sizeof(char *));
        tokens[i] = strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

int launch_shell()
{
    char input[1024];
    char **args;
    pid_t pid;

    printf("Happy Shell > ");
    fgets(input, sizeof(input), stdin);

    args = split_string(input);

    switch (fork()) {
        case -1: /* error occurred */
            perror("fork");
            return 1;
        case 0: /* child process */
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                return 1;
            }
            break;
        default: /* parent process */
            do {
                waitpid(pid, NULL, WNOHANG);
            } while (pid!= -1);
            break;
    }

    return 0;
}

void setup_signals()
{
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
}

int main()
{
    setup_signals();

    while (1) {
        launch_shell();
    }

    return 0;
}