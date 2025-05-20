//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* maximum length of command */
#define PROMPT "sherlock@221b:" /* prompt that appears in the shell */

char *read_command(void); /* function that reads user input */
char **split_command(char *command); /* function that splits user input in tokens */
int execute_command(char **args); /* function that executes the command entered by the user */

int main(void)
{
    char *command; /* user input */
    char **args; /* tokens obtained from user input */
    int status = 1; /* exit status of executed command */

    while(status)
    {
        printf("%s$", PROMPT); /* display prompt */
        command = read_command(); /* read user input */
        args = split_command(command); /* split user input in tokens */
        status = execute_command(args); /* execute command and get exit status */
        free(command); /* free memory */
        free(args); /* free memory */
    }

    return 0;
}

char *read_command(void)
{
    char *commandline = malloc(MAX_LINE*sizeof(char)); /* allocate memory for user input */
    fgets(commandline, MAX_LINE, stdin); /* read user input */
    commandline[strlen(commandline)-1] = '\0'; /* replace newline character with null terminator */
    return commandline; /* return pointer to string */
}

char **split_command(char *command)
{
    char **args = malloc(MAX_LINE*sizeof(char*)); /* allocate memory for tokens */
    char *delimiters = " "; /* delimiters used to separate tokens */
    char *token = strtok(command, delimiters); /* get first token */
    int i = 0;

    while(token != NULL)
    {
        args[i] = token; /* store token */
        token = strtok(NULL, delimiters); /* get next token */
        i++;
    }

    args[i] = NULL; /* set last argument to NULL */
    return args; /* return array of strings */
}

int execute_command(char **args)
{
    pid_t pid;
    int status;

    if(args[0] == NULL) /* if no command entered, repeat prompt */
    {
        return 1;
    }

    if(strcmp(args[0], "exit") == 0) /* if command is exit, exit shell */
    {
        return 0;
    }

    pid = fork(); /* create child process */

    if(pid < 0) /* if error occurred, display message */
    {
        fprintf(stderr, "Error: Forking failed\n");
        return 1;
    }
    else if(pid == 0) /* if child process, execute command */
    {
        if(execvp(args[0], args) == -1) /* execute command */
        {
            fprintf(stderr, "Error: Execution failed\n");
        }
        exit(EXIT_FAILURE); /* if command failed to execute, exit child process with failure status */
    }
    else if(pid > 0) /* if parent process, wait for child to terminate */
    {
        do {
            waitpid(pid, &status, WUNTRACED); /* wait for child to terminate */
        } while(!WIFEXITED(status) && !WIFSIGNALED(status)); /* loop until child process terminates */
    }

    return 1; /* repeat prompt */
}