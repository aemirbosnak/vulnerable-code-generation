//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100 //Maximum length of a command
#define MAX_NUM_ARGUMENTS 10 //Maximum number of arguments in a command

//Function to change the current directory
int changeDirectory(char *dir){
    if(chdir(dir) != 0){
        printf("Error: Directory not found\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//Function to execute a command
void executeCommand(char **args){

    //Check if the command is to change directory
    if(strcmp(args[0],"cd") == 0){
        if(args[1] == NULL){
            printf("Error: Please specify a directory\n");
        }
        else{
            changeDirectory(args[1]);
        }
        return;
    }

    //Fork the current process to run the command
    pid_t pid = fork();
    if(pid==0){
        if(execvp(args[0],args) == -1){
            printf("Error: Command not found\n");
        }
        exit(EXIT_SUCCESS);
    }
    else if(pid < 0){
        printf("Error: Fork failed\n");
    }
    else{
        //Wait for the child process to complete
        int status;
        waitpid(pid,&status,0);
    }
}

int main(){

    char *input; //Input by the user
    char *command; //Command present in the input
    char *args[MAX_NUM_ARGUMENTS]; //Arguments present in the input

    //Allocate memory to input
    input = (char*)malloc(MAX_COMMAND_LENGTH*sizeof(char));
    memset(input,0,MAX_COMMAND_LENGTH);

    //Shell Loop : Ask for input and execute commands until "exit" is entered
    while(1){
        printf("> ");
        if(!fgets(input,MAX_COMMAND_LENGTH,stdin)){
            break;
        }

        //Split the input into command and arguments
        int count = 0;
        char *token;

        token = strtok(input," \n");
        while(token != NULL && count < MAX_NUM_ARGUMENTS-1){
            args[count] = token;
            count++;
            token = strtok(NULL," \n");
        }
        args[count] = NULL;

        if(args[0] != NULL){

            //Check if the command is to exit
            if(strcmp(args[0],"exit") == 0){
                break;
            }

            //Execute the command
            executeCommand(args);
        }

        //Clear the input buffer
        memset(input,0,MAX_COMMAND_LENGTH);
    }

    //Free the memory allocated for input
    free(input);

    return EXIT_SUCCESS;
}