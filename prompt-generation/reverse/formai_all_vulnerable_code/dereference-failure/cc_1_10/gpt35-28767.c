//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAX_LINE 80 /* maximum length of command */
#define MAX_HISTORY 5 /* maximum number of commands stored in history */

/* Function prototypes */
void parse_command(char *command, char **args);
void execute_command(char** args);

/* Global variables */
char* history[MAX_HISTORY]; /* array of commands stored in history */
int num_commands = 0; /* number of commands stored in history */
int current_command_pos = 0; /* position of current command in history */

int main(void) {
    char command[MAX_LINE]; /* user input buffer */
    char* args[MAX_LINE/2 + 1]; /* array of arguments passed to command */
    int should_run = 1; /* flag to determine if program should continue running */

    while (should_run) {
        printf("osh> "); /* print prompt */
        fflush(stdout); /* flush output stream */

        /* read user input */
        fgets(command,MAX_LINE,stdin);

        /* remove newline character from user input */
        command[strcspn(command,"\n")] = 0;

        /* check if user input is a built-in command */
        if (strcmp(command,"exit") == 0) {
            should_run = 0; /* exit program */
        } else if (strcmp(command,"history") == 0) {
            /* print command history */
            int i;
            for (i=0; i<num_commands; i++) {
                printf("%d: %s\n",i+1,history[i]);
            }
        } else {
            /* user input is not a built-in command, so execute it */
            parse_command(command,args); /* parse command into arguments */
            execute_command(args); /* execute command */
        }

        /* add command to history */
        history[num_commands % MAX_HISTORY] = strdup(command);
        num_commands++; /* increment number of commands stored in history */
    }

    return 0;
}

/* Function to parse command into arguments */
void parse_command(char *command, char **args) {
    int i = 0;
    char *token;

    token = strtok(command," "); /* get first token */
    while (token != NULL) {
        args[i] = token; /* store token in argument array */
        i++;
        token = strtok(NULL," "); /* get next token */
    }
    args[i] = NULL; /* set last argument to NULL */
}

/* Function to execute command */
void execute_command(char** args) {
    if (args[0] == NULL) {
        return; /* do nothing if command is empty */
    }

    /* check if command is "cd" */
    if (strcmp(args[0],"cd") == 0) {
        /* change current directory */
        if (chdir(args[1]) != 0) {
            perror("Error changing directory");
        }
        return;
    }

    /* fork child process to execute command */
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Error forking");
    } else if (pid == 0) {
        /* child process */
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else {
        /* parent process */
        wait(NULL);
    }
}