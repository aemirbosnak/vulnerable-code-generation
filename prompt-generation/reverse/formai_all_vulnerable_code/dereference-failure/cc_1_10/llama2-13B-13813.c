//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESS_COUNT 10

int main(void) {
    int pid[MAX_PROCESS_COUNT];
    char **command_array;
    char line[1024];

    // Create a list of commands to run
    command_array = (char **) malloc(MAX_PROCESS_COUNT * sizeof(char *));
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        command_array[i] = (char *) malloc(1024 * sizeof(char));
        printf("Enter command %d: ", i + 1);
        fgets(line, 1024, stdin);
        command_array[i] = line;
    }

    // Fork and execute the commands
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            // Child process
            execvp(command_array[i], command_array[i]);
            perror("execvp failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    // Print the output of the last command
    if (pid[MAX_PROCESS_COUNT - 1] > 0) {
        wait(NULL);
        printf("Last command output: %s\n", command_array[MAX_PROCESS_COUNT - 1]);
    }

    // Clean up
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        free(command_array[i]);
    }
    free(command_array);

    return 0;
}