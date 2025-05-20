//Falcon-180B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024

// Function to execute a command and return its output as a string
char *execute_command(char *command) {
    char *output = NULL;
    size_t size = 0;

    FILE *pipe = popen(command, "r");

    if (pipe!= NULL) {
        while (fgets(command, MAX_COMMAND_LENGTH, pipe)!= NULL) {
            size += strlen(command);
            output = realloc(output, size + 1);
            strcat(output, command);
        }

        pclose(pipe);
    }

    return output;
}

// Function to fork a new process and execute a command in it
void execute_in_new_process(char *command) {
    pid_t pid = fork();

    if (pid == 0) {
        system(command);
        exit(0);
    } else if (pid < 0) {
        perror("Fork Failed");
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char *output = execute_command(input);

    if (output!= NULL) {
        printf("Output:\n%s", output);
        free(output);
    } else {
        printf("Error executing command\n");
    }

    return 0;
}