//Falcon-180B DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void execute_command(char *command);
int create_process(char **args);
void sigchld_handler(int signum);

int main() {
    char input[1024];
    char *token;

    signal(SIGCHLD, sigchld_handler);

    while(1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, "\n");

        if(strcmp(token, "exit") == 0)
            break;

        execute_command(token);
    }

    return 0;
}

void execute_command(char *command) {
    char **args;
    int status;

    args = malloc(1024 * sizeof(char*));
    args[0] = strdup("/bin/sh");
    args[1] = strdup("-c");
    args[2] = strdup(command);
    args[3] = NULL;

    status = create_process(args);

    if(status == -1)
        printf("Error: Failed to execute command\n");
}

int create_process(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if(pid == -1) {
        printf("Error: Failed to fork\n");
        return -1;
    } else if(pid == 0) {
        execvp(args[0], args);
        printf("Error: Failed to execute %s\n", args[0]);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

void sigchld_handler(int signum) {
    while(waitpid(-1, NULL, WNOHANG) > 0);
}