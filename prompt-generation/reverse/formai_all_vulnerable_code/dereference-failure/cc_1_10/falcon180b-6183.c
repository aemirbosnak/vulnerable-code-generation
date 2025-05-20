//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

// Function to execute a command and return its output as a string
char* execute_command(char* command) {
    char* args[MAX_ARGUMENTS];
    char* output = NULL;
    int num_args = 0;
    pid_t pid;
    int status;

    // Parse the command into arguments
    args[num_args++] = strtok(command, DELIM);
    while (num_args < MAX_ARGUMENTS && (args[num_args] = strtok(NULL, DELIM))!= NULL) {
        num_args++;
    }

    // Fork a child process to execute the command
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        // Read the command's output from the pipe
        FILE* pipe = fdopen(dup(1), "r");
        if (pipe == NULL) {
            perror("fdopen");
            exit(1);
        }
        output = malloc(MAX_COMMAND_LENGTH);
        if (output == NULL) {
            perror("malloc");
            exit(1);
        }
        fgets(output, MAX_COMMAND_LENGTH, pipe);
        fclose(pipe);
    }

    return output;
}

int main(int argc, char* argv[]) {
    char* command;
    char* output;
    int i;

    // Check if the correct number of arguments were provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    // Execute the command and print its output
    command = argv[1];
    for (i = 2; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }
    output = execute_command(command);
    printf("%s", output);

    return 0;
}