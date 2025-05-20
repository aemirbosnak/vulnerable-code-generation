//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
#define MAX_COMMAND_LENGTH 1024
 
void executeCommand(char *command);
void showShellPrompt();
 
int main(){
    char command[MAX_COMMAND_LENGTH];
 
    while(1){
        showShellPrompt();
 
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if(strcmp(command, "exit\n") == 0){
            printf("Exiting shell...\n");
            break;
        }
 
        executeCommand(command);
    }
 
    return 0;
}
 
void showShellPrompt(){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s$ ", cwd);
}
 
void executeCommand(char *command){
    char *argv[10];
    int argc = 0;
 
    char *token = strtok(command, " \n");
    while(token != NULL){
        argv[argc++] = strdup(token);
        token = strtok(NULL, " \n");
    }
 
    argv[argc] = NULL;
 
    if(fork() == 0){
        execvp(*argv, argv);
        printf("Command not found: %s\n", command);
        exit(0);
    }
    else{
        wait(NULL);
    }   
}