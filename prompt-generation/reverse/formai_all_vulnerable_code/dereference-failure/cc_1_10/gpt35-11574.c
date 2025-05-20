//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char** tokenize_input(char *input){
    char **tokens = calloc(MAX_NUM_TOKENS, sizeof(char*));
    char *token = strtok(input, " \n\t");
    int i = 0;
    while(token != NULL){
        tokens[i++] = token;
        token = strtok(NULL, " \n\t");
    }
    tokens[i] = NULL;
    return tokens;
}

int execute_command(char **tokens){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }
    else if(pid == 0){
        if(execvp(tokens[0], tokens) == -1){
            perror("execvp");
            return 1;
        }
        exit(EXIT_FAILURE);
    }
    else{
        int status;
        do{
            waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
        return 0;
    }
}

int main(){
    char line[MAX_INPUT_SIZE];
    while(1){
        printf("> ");
        fgets(line, MAX_INPUT_SIZE, stdin);

        char **tokens = tokenize_input(line);

        if(tokens[0] != NULL){
            int exit_shell = 0;
            if(strcmp(tokens[0], "exit") == 0){
                exit_shell = 1;
            }
            else{
                execute_command(tokens);
            }
            free(tokens);
            if(exit_shell){
                break;
            }
        }
    }
    return 0;
}