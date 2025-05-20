//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

#define MAX_CHAR 100
#define MAX_ARGS 10

void parse_command(char* command, char** args, int* args_count){
    *args_count = 0;
    while(*command != '\0'){
        while(*command == ' ' || *command == '\t' || *command == '\n')
            *command++ = '\0';
        *args++ = command;
        (*args_count)++;
        while(*command != '\0' && *command != ' ' && *command != '\t' && *command != '\n')
            command++;
    }
    *args = '\0'; // last argument should be NULL
}

void execute(char** args, int args_count, int input_fd, int output_fd){
    pid_t pid = fork();
    if(pid == 0){
        if(input_fd != STDIN_FILENO){
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if(output_fd != STDOUT_FILENO){
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }
        if(execvp(args[0], args) == -1){
            printf("Unknown command: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else if(pid < 0){
        printf("Forking failed\n");
        exit(EXIT_FAILURE);
    }
    else{
        wait(NULL);
    }
}

void handle_pipes(char*** commands, int command_count){
    int input_fd = STDIN_FILENO;
    int output_fd;
    for(int i=0; i<command_count-1; i++){
        int pipe_fd[2];
        pipe(pipe_fd);
        output_fd = pipe_fd[1];
        execute(commands[i], MAX_ARGS, input_fd, output_fd);
        close(pipe_fd[1]);
        input_fd = pipe_fd[0];
    }
    output_fd = STDOUT_FILENO;
    execute(commands[command_count-1], MAX_ARGS, input_fd, output_fd);
}

void execute_command(char** args, int args_count){
    if(strcmp(args[0], "cd") == 0){
        if(chdir(args[1]) == -1){
            printf("Change directory failed\n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        int command_count = 1;
        char*** commands = (char***)malloc(sizeof(char**)*command_count);
        int command_index = 0;
        commands[command_index] = (char**)malloc(sizeof(char*)*MAX_ARGS);
        for(int i=0; i<args_count; i++){
            if(strcmp(args[i], "|") == 0){
                commands[command_index][i] = '\0';
                command_index++;
                commands[command_index] = (char**)malloc(sizeof(char*)*MAX_ARGS);
                command_count++;
            }
            else{
                commands[command_index][i] = args[i];
            }
        }
        commands[command_index+1] = '\0';
        handle_pipes(commands, command_count);
        for(int i=0; i<=command_index; i++)
            free(commands[i]);
        free(commands);
    }
}

int main(){
    char* command = (char*)malloc(sizeof(char)*MAX_CHAR);
    char** args = (char**)malloc(sizeof(char*)*MAX_ARGS);
    int args_count;
    while(1){
        printf(">> ");
        fgets(command, MAX_CHAR, stdin);
        parse_command(command, args, &args_count);
        if(args_count == 0)
            continue;
        if(strcmp(args[0], "exit") == 0)
            break;
        execute_command(args, args_count);
    }
    free(command);
    free(args);
    return 0;
}