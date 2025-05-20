//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Failed to execute command: %s\n", argv[0]);
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Failed to fork process.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int status;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = split_command(input);
    status = execute_command(argv);

    if (status!= 0) {
        printf("Exit status: %d\n", status);
    }
}

int main(void) {
    loop();
    return 0;
}