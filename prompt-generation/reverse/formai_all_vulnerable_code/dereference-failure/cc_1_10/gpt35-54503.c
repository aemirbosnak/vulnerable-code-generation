//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int get_input(char* str)
{
    printf("shell>> ");
    char* input = fgets(str, MAX_INPUT_SIZE, stdin);
    if(input == NULL)
        return 0;
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    return 1;
}

void tokenize(char* input, char** tokens, int* num_tokens)
{
    char* token = strtok(input, " ");
    int i = 0;
    while(token != NULL){
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    *num_tokens = i;
}

int main()
{
    char input_string[MAX_INPUT_SIZE];
    char* tokens[MAX_NUM_TOKENS];
    int num_tokens = 0;
    while(get_input(input_string)){
        tokenize(input_string, tokens, &num_tokens);
        
        // check for exit command
        if(strcmp(tokens[0], "exit") == 0){
            printf("Exiting Shell...\n");
            break;
        }
        
        // check for configurable commands
        if(strcmp(tokens[0], "configure") == 0){
            if(num_tokens == 1){
                printf("Error: Specify the configuration parameter.\n");
                continue;
            }
            if(num_tokens == 2){
                printf("Error: Specify the value of the configuration parameter.\n");
                continue;
            }
            // add handling for specific configuration parameters below
            char* parameter = tokens[1];
            char* value = tokens[2];
            if(strcmp(parameter, "prompt") == 0){
                printf("Changing prompt to %s.\n", value);
                // add code to change the prompt here
            }
            else if(strcmp(parameter, "path") == 0){
                printf("Changing path to %s.\n", value);
                // add code to change the path here
            }
            else{
                printf("Error: Unknown configuration parameter %s.\n", parameter);
            }
            continue;
        }
        
        // add handling for other commands that do not require forking below
        if(strcmp(tokens[0], "help") == 0){
            printf("Help documentation goes here.\n");
            continue;
        }
        
        // fork a child process to execute the command
        pid_t pid = fork();
        if(pid == -1){
            printf("Error: Failed to fork.\n");
            continue;
        }
        if(pid == 0){ // child process
            execvp(tokens[0], tokens);
            printf("Error: Failed to execute command %s.\n", tokens[0]);
            exit(1);
        }
        else{ // parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    
    return 0;
}