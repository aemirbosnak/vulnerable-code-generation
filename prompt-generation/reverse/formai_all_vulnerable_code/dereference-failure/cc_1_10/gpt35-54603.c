//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_CMD_LENGTH 512
#define MAX_NUM_ARGS 10

void remove_newline(char* str) {
    int len = strlen(str);
    if(str[len-1] == '\n')
        str[len-1] = '\0';
}

void print_prompt() {
    printf(">> ");
}

int parse_input(char* input, char** args) {
    remove_newline(input);
    int i = 0;

    char* token = strtok(input, " ");
    while(token != NULL && i < MAX_NUM_ARGS) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return i;
}

void run_command(char** args) {
    pid_t pid;
    int status;

    pid = fork();
    
    if(pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if(pid == 0) {
        if(execvp(args[0], args) < 0) {
            perror("execvp failed");
            exit(1);
        }
    } 
    else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];
    char* args[MAX_NUM_ARGS+1];
    int num_args;
    while(1) {
        memset(cmd, '\0', sizeof(cmd));
        memset(args, NULL, sizeof(args));
        print_prompt();
        fgets(cmd, sizeof(cmd), stdin);

        num_args = parse_input(cmd, args);
        if(num_args > 0) {
            if(strcmp(args[0], "exit") == 0)
                exit(0);
            run_command(args);
        }
    }
    return 0;
}