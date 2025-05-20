//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

#define MAX_COMMANDS 10
#define BUFFER_SIZE 1024

int main(){
    printf("Unix-like shell, type 'exit' to terminate.\n");
    char buffer[BUFFER_SIZE];
    char *commands[MAX_COMMANDS];
    int in, out;
    while(1){
        //getting user input
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        //removing newline character
        buffer[strcspn(buffer, "\n")] = 0;
        //checking for exit command
        if(strcmp(buffer, "exit")==0)
            break;
        //Parsing commands
        int index=0;
        char *token = strtok(buffer, " ");
        while(token != NULL){
            commands[index++] = token;
            token = strtok(NULL, " ");
        }
        //Checking for input and output redirection
        int i=0;
        while(commands[i] != NULL){
            if(strcmp(commands[i], "<")==0){
                commands[i] = NULL;
                in = open(commands[i+1], O_RDONLY);
                dup2(in, STDIN_FILENO);
                close(in);
                break;
            }
            if(strcmp(commands[i], ">")==0){
                commands[i] = NULL;
                out = open(commands[i+1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
                dup2(out, STDOUT_FILENO);
                close(out);
                break;
            }
            i++;
        }
        //Setting last command to null for execvp
        commands[index] = NULL;
        //Creating child process and executing command
        pid_t pid = fork();
        if(pid==0){//child process
            execvp(commands[0], commands);
            printf("Command not found!\n");
            exit(0);
        }
        else{//parent process
            wait(NULL);
        }
    }
    printf("Exiting Unix-like shell\n");
    return 0;
}