//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 10

char* commands[MAX_ARGS];
char cmd[MAX_CMD_LEN];

void parse_input(char* input);
int execute_command();

int main() {
    while (true) {
        printf("> ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        parse_input(cmd);
        execute_command();
    }
    return 0;
}

void parse_input(char* input) {
    int i = 0;
    char* token = strtok(input, " \n");
    while (token) {
        commands[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    commands[i] = NULL;
}

int execute_command() {
    int pid, status;
    pid = fork();
    
    if (pid == -1) { //fork failed
        printf("fork: %s\n", strerror(errno));
        return -1;
    }
    else if (pid > 0) { //parent process
        waitpid(pid, &status, 0); //wait for child process to finish
        return 0;
    }
    else { //child process
        if (execvp(commands[0], commands) == -1) { //execute command
            printf("%s: %s\n", commands[0], strerror(errno));
            return -1;
        }
    }
    
    return 0;
}