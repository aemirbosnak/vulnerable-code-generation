//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define TRUE 1
#define FALSE 0

int execute_command(char **args, int is_background) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
    } else {
        // Parent process
        if (is_background) {
            printf("[%d]\n", pid); // print process ID of background process
        } else {
            do {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            // wait for child process to terminate
        }
    }

    return 1;
}

int main(void) {
    char *args[MAX_LINE/2 + 1]; // command line arguments
    char input_buffer[MAX_LINE]; // input command buffer
    int should_run = TRUE; // flag to determine when to exit program
    int is_background = FALSE; // flag to determine if command is run in background

    while (should_run) {
        printf("shell> ");
        fflush(stdout);

        fgets(input_buffer, MAX_LINE, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; // remove newline character

        int arg_index = 0;
        char *arg = strtok(input_buffer, " ");
        while (arg != NULL) {
            args[arg_index++] = arg;
            arg = strtok(NULL, " ");
        }
        args[arg_index] = NULL;

        // check for background processing using &
        if (arg_index > 0 && strcmp(args[arg_index-1], "&") == 0) {
            is_background = TRUE;
            args[arg_index-1] = NULL;
        } else {
            is_background = FALSE;
        }

        if (strcmp(args[0], "exit") == 0) {
            should_run = FALSE; // exit shell program
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (arg_index > 1) {
                if (chdir(args[1]) != 0) {
                    perror("shell");
                }
            } else {
                chdir(getenv("HOME")); // change to home directory if no arguments
            }
        } else {
            execute_command(args, is_background); // execute shell command
        }
    }

    return EXIT_SUCCESS;
}