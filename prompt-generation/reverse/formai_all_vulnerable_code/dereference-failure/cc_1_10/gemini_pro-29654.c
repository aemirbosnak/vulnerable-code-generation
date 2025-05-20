//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

typedef struct command {
    char *argv[MAX_ARGS];
    int argc;
    int background;
} command_t;

int parse_line(char *line, command_t *cmd) {
    char *argv[MAX_ARGS];
    int argc = 0;
    char *pch;
    
    pch = strtok(line, " ");
    while (pch != NULL) {
        argv[argc++] = pch;
        pch = strtok(NULL, " ");
    }
    
    if (strcmp(argv[argc - 1], "&") == 0) {
        cmd->background = 1;
        argc--;
    } else {
        cmd->background = 0;
    }
    
    cmd->argv[argc] = NULL;
    cmd->argc = argc;
    return 0;
}

int execute(command_t *cmd) {
    pid_t pid;
    
    if ((pid = fork()) == -1) {
        perror("fork");
        return -1;
    }
    
    if (pid == 0) {
        execvp(cmd->argv[0], cmd->argv);
        perror("execvp");
        exit(1);
    }
    
    if (!cmd->background) {
        waitpid(pid, NULL, 0);
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    command_t cmd;
    
    while (1) {
        printf("$ ");
        fflush(stdout);
        
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }
        
        parse_line(line, &cmd);
        
        if (cmd.argc == 0) {
            continue;
        }
        
        if (strcmp(cmd.argv[0], "exit") == 0) {
            break;
        }
        
        execute(&cmd);
    }
    
    return 0;
}