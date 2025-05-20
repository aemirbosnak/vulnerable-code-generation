//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// Function to execute command
void executeCommand(char *command) {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Executing command: %s\n", command);
        system(command);
        exit(0);
    }
    else if (pid < 0) {
        printf("Error forking child process!\n");
    }
    else {
        wait(NULL);
    }
}

int main() {
    char command[100];
    char *args[10];
    int i = 0;
    while (1) {
        printf("$ ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove trailing newline character
        char *token = strtok(command, " ");
        while (token != NULL) {
            args[i] = strdup(token);
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(args[0], "help") == 0) {
            printf("List of available commands:\n");
            printf("help - Display this help message\n");
            printf("ls - List contents of current directory\n");
            printf("clear - Clear the terminal\n");
            printf("pwd - Print working directory\n");
            printf("mkdir [directory name] - Create a new directory\n");
            printf("rmdir [directory name] - Remove an empty directory\n");
            printf("touch [file name] - Create a new file\n");
            printf("rm [file name] - Remove a file\n");
            printf("exit - Exit the program\n");
        }
        else if (strcmp(args[0], "ls") == 0) {
            executeCommand("ls");
        }
        else if (strcmp(args[0], "clear") == 0) {
            executeCommand("clear");
        }
        else if (strcmp(args[0], "pwd") == 0) {
            executeCommand("pwd");
        }
        else if (strcmp(args[0], "mkdir") == 0) {
            if (args[1] == NULL) {
                printf("Error: Missing directory name!\n");
            }
            else {
                char mkdirCommand[100];
                sprintf(mkdirCommand, "mkdir %s", args[1]);
                executeCommand(mkdirCommand);
            }
        }
        else if (strcmp(args[0], "rmdir") == 0) {
            if (args[1] == NULL) {
                printf("Error: Missing directory name!\n");
            }
            else {
                char rmdirCommand[100];
                sprintf(rmdirCommand, "rmdir %s", args[1]);
                executeCommand(rmdirCommand);
            }
        }
        else if (strcmp(args[0], "touch") == 0) {
            if (args[1] == NULL) {
                printf("Error: Missing file name!\n");
            }
            else {
                char touchCommand[100];
                sprintf(touchCommand, "touch %s", args[1]);
                executeCommand(touchCommand);
            }
        }
        else if (strcmp(args[0], "rm") == 0) {
            if (args[1] == NULL) {
                printf("Error: Missing file name!\n");
            }
            else {
                char rmCommand[100];
                sprintf(rmCommand, "rm %s", args[1]);
                executeCommand(rmCommand);
            }
        }
        else {
            printf("Error: Unknown command!\n");
        }
        // Clear args array and reset index
        memset(args, 0, sizeof(args));
        i = 0;
    }
    return 0;
}