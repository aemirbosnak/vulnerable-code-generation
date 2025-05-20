//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
/* This program creates a simple Unix-like shell that can execute commands.
   The program reads input from the user, parses the input, and executes the command
   using the execvp() system call.
   The program also supports background processes and input/output redirection.
   Author: AI Bot */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE 80
#define MAX_ARGS 10

/* Function prototypes */
int parse_command(char* input, char* args[]);
int execute_command(char* args[], int background, char* in_file, char* out_file);

int main(void) {
    char* args[MAX_ARGS];
    char input[MAX_LINE];
    int running = 1;
    pid_t pid;

    while(running) {
        printf("osh> ");
        fflush(stdout);

        // Read input from user
        fgets(input, MAX_LINE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove new line character

        // Parse input into command and arguments
        int background = parse_command(input, args);

        // Check for exit command
        if(strcmp(args[0], "exit") == 0) {
            running = 0;
            continue;
        }

        // Check for empty command
        if(args[0] == NULL) {
            continue;
        }

        // Check for I/O redirection
        char* in_file = NULL;
        char* out_file = NULL;
        int in_flag = 0;
        int out_flag = 0;
        int i = 0;
        while(args[i] != NULL) {
            if(strcmp(args[i], "<") == 0 && args[i+1] != NULL) {
                in_file = args[i+1];
                in_flag = 1;
            }
            else if(strcmp(args[i], ">") == 0 && args[i+1] != NULL) {
                out_file = args[i+1];
                out_flag = 1;
            }
            i++;
        }

        // Fork process to execute command
        pid = fork();
        if(pid < 0) {
            printf("Fork failed.\n");
            exit(1);
        }
        else if(pid == 0) {
            // Child process

            // Set up I/O redirection
            if(in_flag) {
                int fd_in = open(in_file, O_RDONLY);
                if(fd_in < 0) {
                    printf("Failed to open input file.\n");
                    exit(1);
                }
                dup2(fd_in, STDIN_FILENO);
                close(fd_in);
            }
            if(out_flag) {
                int fd_out = open(out_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
                if(fd_out < 0) {
                    printf("Failed to open output file.\n");
                    exit(1);
                }
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
            }

            // Execute command
            int ret = execute_command(args, background, in_file, out_file);
            if(ret < 0) {
                printf("Invalid command.\n");
                exit(1);
            }
            exit(0);
        }
        else {
            // Parent process

            // Wait for child to finish (if not background process)
            if(!background) {
                wait(NULL);
            }
        }
    }

    return 0;
}

/* Function to parse user input into command and arguments */
int parse_command(char* input, char* args[]) {
    int background = 0;
    args[0] = strtok(input, " ");
    int i = 1;
    while(args[i-1] != NULL && i < MAX_ARGS) {
        args[i] = strtok(NULL, " ");
        if(args[i] != NULL && strcmp(args[i], "&") == 0) {
            background = 1;
            args[i] = NULL;
        }
        i++;
    }
    return background;
}

/* Function to execute the command */
int execute_command(char* args[], int background, char* in_file, char* out_file) {
    int ret = execvp(args[0], args);
    return ret;
}