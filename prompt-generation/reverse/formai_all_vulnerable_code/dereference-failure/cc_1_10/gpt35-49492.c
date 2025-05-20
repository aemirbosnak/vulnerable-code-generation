//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LENGTH 256

void print_prompt(){
    printf("retro-shell: ");
}

void execute(char *command[]){
    char *output_file = NULL;
    int input_file = STDIN_FILENO;
    int output = STDOUT_FILENO;

    for (int i = 0; command[i] != NULL; i++){
        if(strcmp(command[i], "<") == 0){
            input_file = open(command[i+1], O_RDONLY);
        }
        else if(strcmp(command[i], ">") == 0){
            output_file = command[i+1];
            output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
    }
    if(output_file != NULL){
        dup2(output, STDOUT_FILENO);
        close(output);
    }
    if(input_file != STDIN_FILENO){
        dup2(input_file, STDIN_FILENO);
        close(input_file);
    }
    if(execvp(command[0], command) < 0){
        printf("Invalid command! \n");
        exit(1);
    }   
}

void parse_input(char *input, char *command[]){
    input[strlen(input)-1] = '\0';
    int arg_count = 0;
    char *arg_value;

    arg_value = strtok(input, " ");

    while(arg_value != NULL && arg_count < MAX_ARGS){
        command[arg_count++] = arg_value;
        arg_value = strtok(NULL, " ");
    } 
    command[arg_count] = NULL;
}

int main(int argc, char *argv[]){
    char input[MAX_LENGTH];
    char *command[MAX_ARGS];
    int status;

    while(1){
        print_prompt();
        fgets(input, MAX_LENGTH, stdin);

        if(strcmp(input, "exit\n") == 0){
            exit(0);
        }

        parse_input(input, command);

        if(fork() == 0){
            execute(command);
        }
        else{
           waitpid(-1, &status, 0);
        }
    }
    return 0;
}