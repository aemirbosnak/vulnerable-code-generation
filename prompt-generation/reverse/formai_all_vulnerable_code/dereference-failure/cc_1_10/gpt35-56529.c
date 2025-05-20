//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

// function prototypes
void read_command(char** command, char** args);
int execute_command(char* command, char** args);

int main()
{
    char* command = NULL;
    char** args = malloc(MAX_ARGS * sizeof(char*));
    for(int i = 0; i < MAX_ARGS; i++)
    {
        args[i] = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    }
    
    while(1)
    {
        printf("Enter a command: ");
        read_command(&command, args); // read command and args from user
        
        if(strcmp(command, "quit") == 0) // check if user wants to quit
        {
            break;
        }
        
        int pid = fork(); // create child process
        if(pid == 0) // child process
        {
            int ret = execute_command(command, args); // execute the command
            if(ret == -1)
            {
                printf("Error executing command.\n");
            }
            exit(0);
        }
        else if(pid > 0) // parent process
        {
            wait(NULL); // wait for child process to finish
        }
        else
        {
            printf("Error creating child process.\n");
        }
    }
    
    // free memory
    free(command);
    for(int i = 0; i < MAX_ARGS; i++)
    {
        free(args[i]);
    }
    free(args);
    
    return 0;
}

void read_command(char** command, char** args)
{
    char* input = NULL;
    size_t len = 0;
    ssize_t nread;
    
    nread = getline(&input, &len, stdin); // read input from user
    input[strlen(input)-1] = '\0'; // remove newline character
    
    // split input into command and args
    char* token = strtok(input, " ");
    *command = token;
    int i = 0;
    token = strtok(NULL, " ");
    while(token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
}

int execute_command(char* command, char** args)
{
    if(strcmp(command, "add") == 0) // Add two numbers
    {
        int a = atoi(args[0]);
        int b = atoi(args[1]);
        printf("%d + %d = %d\n", a, b, a+b);
    }
    else if(strcmp(command, "multiply") == 0) // Multiply two numbers
    {
        int a = atoi(args[0]);
        int b = atoi(args[1]);
        printf("%d * %d = %d\n", a, b, a*b);
    }
    else if(strcmp(command, "echo") == 0) // Echo the input string
    {
        char* message = args[0];
        printf("%s\n", message);
    }
    else // Command not recognized
    {
        return -1;
    }
    
    return 0;
}