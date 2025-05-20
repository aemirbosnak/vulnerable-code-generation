//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENVIRONMENT_VARIABLES 10

char *program_name = "My Shell";
char *prompt = "My Shell > ";

void execute_command(char *command) {
    char *argv[MAX_ARGUMENTS];
    int argc = 0;
    char *delimiter = " ";
    char *token = strtok(command, delimiter);

    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, delimiter);
    }

    argv[argc] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void loop() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        execute_command(input);
    }
}

int main() {
    loop();
    return 0;
}