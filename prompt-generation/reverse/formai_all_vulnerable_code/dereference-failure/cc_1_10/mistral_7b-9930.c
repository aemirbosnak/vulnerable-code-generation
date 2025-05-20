//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_NUM_COMMANDS 32

char **tokens;
int num_tokens;
char **commands;
int num_commands;

void sigint_handler(int sig){
    printf("\n");
    for(int i = 0; i < num_commands; i++){
        waitpid(commands[i], NULL, 0);
    }
    num_commands = 0;
}

void execute_command(char **command){
    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0){
        // child process
        if(execvp(command[0], command) < 0){
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    }else if(pid > 0){
        // parent process
        waitpid(pid, &status, 0);
    }else{
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
}

void parse_input(char *input){
    char *token;
    char *save_ptr;
    int i = 0;

    num_tokens = 0;

    tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));

    token = strtok_r(input, " ", &save_ptr);

    while(token != NULL){
        tokens[num_tokens] = token;
        num_tokens++;

        token = strtok_r(NULL, " ", &save_ptr);
    }

    tokens[num_tokens] = NULL;
}

void parse_command_line(){
    char input[MAX_INPUT_SIZE];
    int i = 0;

    printf("> ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    parse_input(input);

    num_commands = num_tokens;

    commands = malloc(num_commands * sizeof(char *));

    for(i = 0; i < num_commands; i++){
        commands[i] = malloc(strlen(tokens[i]) + 1);
        strcpy(commands[i], tokens[i]);
    }

    execute_command(commands);
}

int main(int argc, char **argv){
    signal(SIGINT, sigint_handler);

    while(1){
        parse_command_line();
    }

    for(int i = 0; i < num_commands; i++){
        free(commands[i]);
    }
    free(commands);

    for(int i = 0; i < num_tokens; i++){
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}