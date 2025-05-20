//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input;
    size_t bufsize = 32;
    ssize_t characters;

    input = (char *)malloc(bufsize * sizeof(char));
    if (!input) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    printf(">> ");

    while ((characters = getline(&input, &bufsize, stdin)) != -1) {
        input[strcspn(input, "\n")] = '\0';
        char *command = strtok(input, " ");
        char *args[32];
        int i = 0;
        while (command != NULL) {
            args[i] = command;
            command = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("Error executing command.");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("Forking error.");
            exit(EXIT_FAILURE);
        }
        else {
            wait(NULL);
        }

        printf(">> ");
    }

    free(input);

    return EXIT_SUCCESS;
}