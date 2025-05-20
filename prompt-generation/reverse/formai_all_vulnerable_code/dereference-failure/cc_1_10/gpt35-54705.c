//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define LINE_BUF_SIZE 1024 // maximum length of each command line
#define ARG_BUF_SIZE 64 // maximum number of arguments
#define DELIM " \t\r\n" // delimiters for command and arguments

/*
 * Split the user input into arguments array
 */
char **split_args(char *line){
    int arg_buf_size = ARG_BUF_SIZE, position = 0;
    char **args = malloc(arg_buf_size * sizeof(char*));
    char *arg;

    if(!args){
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    arg = strtok(line, DELIM);

    while(arg != NULL){
        args[position++] = arg;

        if(position >= arg_buf_size){
            arg_buf_size += ARG_BUF_SIZE;
            args = realloc(args, arg_buf_size * sizeof(char*));

            if(!args){
                perror("realloc error");
                exit(EXIT_FAILURE);
            }
        }

        arg = strtok(NULL, DELIM);
    }

    args[position] = NULL;
    return args;
}

/*
 * Main loop to prompt and execute commands
 */
void shell_loop(){
    char *line, **args;
    int status;

    do {
        printf("> ");
        line = malloc(LINE_BUF_SIZE * sizeof(char));
        fgets(line, LINE_BUF_SIZE, stdin);
        args = split_args(line);
        status = execute(args);

        free(line);
        free(args);
    } while(status);
}

/*
 * Handle the built-in commands, and execute other commands using the system call.
 */
int execute(char **args){
    if(args[0] == NULL){
        return 1;
    }

    if(strcmp(args[0], "cd") == 0){
        if(args[1] == NULL){
            fprintf(stderr, "cd: expected argument to \"cd\"\n");
        } else {
            if(chdir(args[1]) != 0){
                perror("chdir error");
            }
        }
        return 1;
    } else if(strcmp(args[0], "exit") == 0){
        return 0;
    }

    pid_t pid, wpid;
    int status;

    pid = fork();

    if(pid == 0){
        // Child process
        if(execvp(args[0], args) == -1){
            perror("execute error");
        }
        exit(EXIT_FAILURE);
    } else if(pid < 0){
        // Fork failed
        perror("fork error");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/*
 * Main function to start the shell program
 */
int main(int argc, char **argv){
    printf("=== UNIX-LIKE SHELL PROGRAM ===\n");
    shell_loop();
    return EXIT_SUCCESS;
}