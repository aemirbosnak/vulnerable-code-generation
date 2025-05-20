//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_LINE 80 // Maximum length of the command line
#define BUFFER_SIZE 50 // Maximum length of the history buffer
char* history[BUFFER_SIZE]; // history buffer
int count = 0; // count of the history buffer

/**
 * This function reads the command line from the user
 * and parse it into the arguments array.
 **/
void readCommand(char* args[])
{
    char *line;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    getline(&line, &bufsize, stdin);
    line[strlen(line) - 1] = '\0'; // remove the newline character
    if(strcmp(line, "") == 0) // if the user entered an empty command
    {
        args[0] = NULL;
        return;
    }
    history[count%BUFFER_SIZE] = strdup(line); // add the command to the history buffer
    count++;

    char* token = strtok(line, " ");
    int i = 0;
    while(token != NULL)
    {
        args[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // set the last argument to NULL
}

/**
 * This function prints the history buffer.
 **/
void printHistory()
{
    int idx = count - BUFFER_SIZE;
    if(idx < 0)
        idx = 0;
    for(int i = idx; i < count; i++)
    {
        printf("%d %s\n", i - idx + 1, history[i%BUFFER_SIZE]);
    }
}

/**
 * This function executes the command specified by the arguments array.
 **/
void executeCommand(char* args[])
{
    int pid = fork(); // fork a child process
    if(pid == 0) // child process
    {
        execvp(args[0], args); // execute the command
        printf("shell: command not found: %s\n", args[0]); // if exec fails, print an error message
        exit(0);
    }
    else if(pid < 0) // error forking the process
    {
        printf("Failed to fork process.\n");
        return;
    }
    else // parent process
    {
        int status;
        waitpid(pid, &status, 0); // wait for the child to exit
    }
}

int main(void)
{
    char *args[MAX_LINE/2 + 1]; // command line arguments
    int should_run = 1; // flag to determine when to exit program
    char command[MAX_LINE];

    while(should_run)
    {
        printf("osh> ");
        fflush(stdout);
        readCommand(args);
        
        if(strcmp(args[0], "exit") == 0) // if the user entered the exit command
        {
            should_run = 0;
            continue;
        }
        else if(strcmp(args[0], "history") == 0) // if the user entered the history command
        {
            printHistory();
            continue;
        }

        executeCommand(args); // execute the command
    }
    return 0;
}