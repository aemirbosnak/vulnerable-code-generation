//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char *input;
    char *ptr;
    char *args[10];
    int status;
    pid_t pid;
    int i;

    while (1) {
        printf("shapeshift> ");
        input = malloc(sizeof(char) * 256); // allocate memory for input
        fgets(input, 256, stdin);  // read input

        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0'; // remove new line character
        }

        ptr = strtok(input, " "); // split input into tokens
        i = 0;

        while (ptr != NULL) {
            args[i] = ptr;
            ptr = strtok(NULL, " ");
            i++;
        }

        args[i] = NULL; // mark the end of array with NULL

        if (strcmp(args[0], "exit") == 0) { // exit command
            printf("Exiting shell...\n");
            exit(0);
        }

        pid = fork(); // create child process

        if (pid < 0) { // error handling
            printf("Error forking child process\n");
            exit(1);
        }
        else if (pid == 0) { // child process
            execvp(args[0], args);
            printf("Command not found!\n");
            exit(1);
        }
        else { // parent process
            waitpid(pid, &status, 0);
        }

        free(input); // free memory
    }
    return 0;
}