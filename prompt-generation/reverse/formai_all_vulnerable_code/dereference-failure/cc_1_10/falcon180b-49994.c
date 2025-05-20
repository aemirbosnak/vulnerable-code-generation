//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PATH ":/sbin:/bin:/usr/sbin:/usr/bin"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;
    token = strtok(command, DELIM);
    while(token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

pid_t fork() {
    pid_t pid;
    pid = vfork();
    if(pid == 0) {
        setsid();
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;
    if(argv[0] == NULL) {
        fprintf(stderr, "Command not found.\n");
        return 1;
    }
    pid = fork();
    if(pid == 0) {
        if(execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) &&!WIFSIGNALED(status));
    }
    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;
    int status;

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        if(argv[0] == NULL) {
            continue;
        }
        pid = fork();
        if(pid == 0) {
            execute_command(argv);
            exit(0);
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while(!WIFEXITED(status) &&!WIFSIGNALED(status));
        }
    }

    return 0;
}