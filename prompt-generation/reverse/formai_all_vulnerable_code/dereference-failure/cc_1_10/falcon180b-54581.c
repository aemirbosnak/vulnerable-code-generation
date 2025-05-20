//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        args[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }

    args[count] = NULL;
    return args;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Sherlock Holmes' Unix-like Shell\n");
    printf("Enter your command: ");

    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    char **args = split_string(input);

    if (args[0] == NULL) {
        printf("Error: Empty command.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: Command not found.\n");
            return 1;
        }
    } else {
        wait(NULL);
    }

    return 0;
}