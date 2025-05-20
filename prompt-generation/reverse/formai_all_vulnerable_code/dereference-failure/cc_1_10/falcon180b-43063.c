//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str){
    int buf_size = strlen(str)+1;
    char *buf = (char *)malloc(buf_size);
    strcpy(buf, str);
    char **tokens = (char **)malloc(1024*sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while(token!= NULL){
        tokens[num_tokens] = (char *)malloc(strlen(token)+1);
        strcpy(tokens[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

int execute_command(char **args){
    pid_t pid;
    int status;
    if(args[0] == NULL){
        return 1;
    }
    if(strcmp(args[0], "exit") == 0){
        return 0;
    }
    pid = fork();
    if(pid == -1){
        printf("Error forking process\n");
        return 1;
    }
    else if(pid == 0){
        if(execvp(args[0], args) == -1){
            printf("Error executing command\n");
            return 1;
        }
    }
    else{
        waitpid(pid, &status, 0);
    }
    return 0;
}

int main(){
    char input[MAX_COMMAND_LENGTH];
    char **args;
    while(1){
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        if(execute_command(args)!= 0){
            break;
        }
    }
    return 0;
}