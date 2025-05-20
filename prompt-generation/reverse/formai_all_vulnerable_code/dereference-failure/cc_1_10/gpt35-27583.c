//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

//Buffer size
#define BUFFER_SIZE 1024

//Command maximum length
#define COMMAND_MAX_LENGTH 256

//Function to get command line input
char * get_input(){
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if(buffer == NULL){
        perror("Unable to allocate buffer");
    }

    printf(">> ");
    fgets(buffer, BUFFER_SIZE, stdin);

    return buffer;
}

//Function to execute command
int execute_command(char **args){

    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0){
        if(execvp(args[0], args) == -1){
            perror("Command execution failed");
        }

        exit(EXIT_FAILURE);
    }else if(pid < 0){
        perror("Failed to create child process");
    }else{
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

void signal_handler(int sig){
    printf("\nExiting myshell...\n");
}

//Main function
int main(){
    char *input;
    char *token;
    char **args = malloc(sizeof(char*) * COMMAND_MAX_LENGTH);
    int arg_count;

    printf("Hello! Welcome to myshell\n");
    signal(SIGINT, signal_handler);

    while(1){
        input = get_input();

        arg_count = 0;
        token = strtok(input, " \n");

        while(token != NULL){
            args[arg_count++] = token;
            token = strtok(NULL, " \n");
        }

        args[arg_count] = NULL;

        if(arg_count > 0){
            if(strcmp(args[0], "exit") == 0){
                printf("Exiting myshell...\n");
                return EXIT_SUCCESS;
            }

            execute_command(args);
        }

        free(input);
    }

    return EXIT_SUCCESS;
}