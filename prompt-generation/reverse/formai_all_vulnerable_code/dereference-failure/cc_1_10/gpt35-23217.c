//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

/*
This is a basic Unix-like shell, which can execute simple commands with or without arguments.
It allows input and output redirection and piping between multiple commands.
*/

#define MAX_CMD_LEN 256 //Maximum length of a command
#define MAX_ARGS 20 //Maximum number of arguments in a command

void print_prompt(){
    printf("$ ");
}

void execute_command(char** args, int num_args, int* fd_in, int* fd_out){
	// Redirect input/output
	if(fd_in!=NULL){
		dup2(fd_in[0], STDIN_FILENO);
		close(fd_in[0]);
		close(fd_in[1]);
	}
	if(fd_out!=NULL){
		dup2(fd_out[1], STDOUT_FILENO);
		close(fd_out[0]);
		close(fd_out[1]);
	}

	// Execute command
	execvp(args[0], args);
	perror("execvp error");
	exit(EXIT_FAILURE);
}

void execute_pipe(char*** commands, int num_commands){
	int i, fd_in[2], fd_out[2];
	pid_t pid;

	// First command
	pipe(fd_out);
	execute_command(commands[0], strlen(commands[0]), NULL, fd_out);

	// Middle commands
	for(i=1; i<num_commands-1; i++){
		fd_in[0] = fd_out[0];
		fd_in[1] = fd_out[1];
		pipe(fd_out);
		execute_command(commands[i], strlen(commands[i]), fd_in, fd_out);
		close(fd_in[0]);
		close(fd_in[1]);
	}

	// Last command
	fd_in[0] = fd_out[0];
	fd_in[1] = fd_out[1];
	execute_command(commands[num_commands-1], strlen(commands[num_commands-1]), fd_in, NULL);
	close(fd_in[0]);
	close(fd_in[1]);
}

void parse_command(char* cmd, char*** args, int* num_args){
    char* token;
    int i;

    // Allocate memory for args array
    *args = (char**) malloc(MAX_ARGS*sizeof(char*));

    // Parse command into arguments
    token = strtok(cmd, " \t");
    for(i=0; i<MAX_ARGS && token!=NULL; i++){
        (*args)[i] = token;
        token = strtok(NULL, " \t");
    }
    (*args)[i] = NULL; //Set last element to NULL for execvp

    *num_args = i;
}

void parse_pipe(char* cmd, char**** commands, int* num_commands){
    char* token;
    int i;

    // Allocate memory for commands array
    *commands = (char***) malloc(MAX_ARGS*sizeof(char**));

    // Parse command into multiple commands on pipe symbol
    token = strtok(cmd, "|");
    for(i=0; i<MAX_ARGS && token!=NULL; i++){
        parse_command(token, &((*commands)[i]), NULL);
        token = strtok(NULL, "|");
    }

    *num_commands = i;
}

int main(){
    char cmd[MAX_CMD_LEN];
    char** args;
    char*** commands;
    int num_args, num_commands;
    pid_t pid;

    while(1){
        // Print prompt and get command
        print_prompt();
        fgets(cmd, MAX_CMD_LEN, stdin);
        if(strlen(cmd)>0 && cmd[strlen(cmd)-1]=='\n')
            cmd[strlen(cmd)-1] = '\0';

        // Check for exit command
        if(strcmp(cmd, "exit")==0)
            break;

        // Parse command
        parse_pipe(cmd, &commands, &num_commands);

        // Fork and execute command
        pid = fork();
        if(pid==0){
            if(num_commands>1)
                execute_pipe(commands, num_commands);
            else{
                parse_command(cmd, &args, &num_args);
                execute_command(args, num_args, NULL, NULL);
            }
        }
        else{
            wait(NULL); // Wait for child process to finish
        }
    }

    // Clean up memory
    free(args);
    free(commands);

    return EXIT_SUCCESS;
}