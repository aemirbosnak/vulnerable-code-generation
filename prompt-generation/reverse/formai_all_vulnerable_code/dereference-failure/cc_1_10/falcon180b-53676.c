//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t launch_shell(char **args);
char *read_line(int fd);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        pid_t pid = launch_shell(args);
        waitpid(pid, NULL, 0);
    }
    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int count = 0;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    while (token!= NULL && count < MAX_COMMAND_LENGTH / 2) {
        args[count] = strdup(token);
        token = strtok(NULL, DELIM);
        count++;
    }
    args[count] = NULL;
    return args;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    if (args[0] == NULL) {
        return -1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error forking");
        exit(1);
    }
    return pid;
}

char *read_line(int fd) {
    char input[MAX_COMMAND_LENGTH];
    int count = 0;
    while (count < MAX_COMMAND_LENGTH - 1) {
        int bytes_read = read(fd, &input[count], 1);
        if (bytes_read == 0 || input[count] == '\n') {
            input[count] = '\0';
            break;
        }
        count++;
    }
    return strdup(input);
}