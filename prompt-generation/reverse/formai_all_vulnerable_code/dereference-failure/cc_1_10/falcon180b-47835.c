//Falcon-180B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 1024
#define DELIM " "

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char *command = NULL;
    char *args[MAX_ARGS];
    int num_args = 0;
    int status;

    printf("Welcome to the world of system administration!\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        command = strtok(input, DELIM);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("- help: Displays this message\n");
            printf("- exit: Terminates the program\n");
        } else if (strcmp(command, "love") == 0) {
            printf("I love you!\n");
        } else {
            num_args = 0;
            args[num_args] = strtok(input, DELIM);

            while (args[num_args]!= NULL) {
                num_args++;
                args[num_args] = strtok(NULL, DELIM);
            }

            status = system(args[0]);

            if (status == -1) {
                perror("Error");
            }
        }
    }

    return 0;
}