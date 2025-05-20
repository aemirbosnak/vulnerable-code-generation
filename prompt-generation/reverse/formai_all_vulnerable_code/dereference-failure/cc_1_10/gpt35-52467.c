//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_LINE 80 //maximum length of command
#define MAX_HISTORY 10 //maximum length of history list

char* history[MAX_HISTORY]; //array to hold last 10 commands
int count = 0; //keep track of number of commands in history array

//function to add command to history array
void addToHistory(char* input){
    if(count == MAX_HISTORY){
        //if history array is already full, remove the oldest command
        free(history[0]);
        for(int i=0; i<MAX_HISTORY-1; i++){
            history[i] = history[i+1];
        }
        count--; //decrement count since we removed one command from history
    }
    //add newest command to end of history array
    history[count] = strdup(input);
    count++;
}

//function to print last 10 commands in history array
void printHistory(){
    printf("History:\n");
    for(int i=0; i<count; i++){
        printf("%d. %s\n", i+1, history[i]);
    }
}

//function to execute command entered by user
void executeCommand(char* args[]){
    pid_t pid;
    int status;

    pid = fork();
    if(pid < 0){
        printf("Error forking process\n");
        exit(1);
    }
    else if(pid == 0){
        //execute command in child process
        if(execvp(args[0], args) == -1){
            printf("Error executing command\n");
        }
        exit(1);
    }
    else{
        //parent process waits for child process to complete
        do{
            waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main(void){
    char *args[MAX_LINE/2 + 1]; //array to hold command and arguments
    int should_run = 1; //flag to determine when to exit program

    while (should_run){
        printf("osh> ");
        fflush(stdout);

        char* input = NULL;
        size_t len = 0;
        getline(&input, &len, stdin); //get command input from user

        //trim trailing newline character from input
        int inputLen = strlen(input);
        if(input[inputLen-1] == '\n'){
            input[inputLen-1] = '\0';
        }

        addToHistory(input); //add command to history array

        //parse input into array of arguments
        char* token;
        int i = 0;
        token = strtok(input," ");
        while(token != NULL){
            args[i] = token;
            token = strtok(NULL," ");
            i++;
        }
        args[i] = NULL;

        if(args[0] == NULL){
            //if no command entered, loop again
            continue;
        }
        else if(strcmp(args[0], "exit") == 0){
            //if exit command entered, set flag to exit program
            should_run = 0;
            continue;
        }
        else if(strcmp(args[0], "history") == 0){
            //if history command entered, print last 10 commands entered
            printHistory();
            continue;
        }

        executeCommand(args); //execute command
    }

    //free memory allocated for history commands
    for(int i=0; i<count; i++){
        free(history[i]);
    }

    return 0;
}