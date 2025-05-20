//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void prompt(char *user) {
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));
    printf("%s@%s:%s$ ", user, "localhost", pwd);
}

int main() {
    char *user = getenv("USER");
    if (!user) {
        printf("Error: Unable to get username\n");
        exit(1);
    }

    int status = 0;
    char input[1024];
    prompt(user);
    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == '\n') {
            // No command given, prompt again
            prompt(user);
            continue;
        }
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Split command and arguments
        char *command = strtok(input, " ");
        char *args[1024];
        int i = 0;
        while ((args[i++] = strtok(NULL, " ")));

        // Check for built-in commands
        if (strcmp(command, "cd") == 0) {
            // Change directory
            if (args[0]) {
                status = chdir(args[0]);
                if (status == -1) {
                    printf("Error: Unable to change directory\n");
                }
            } else {
                printf("Error: No directory specified\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            // Exit shell
            exit(0);
        } else {
            // Execute command
            int pid = fork();
            if (pid == 0) {
                // Child process
                status = execvp(command, args);
                if (status == -1) {
                    printf("Error: Unable to execute command\n");
                }
                exit(status);
            } else {
                // Parent process
                wait(&status);
            }
        }

        prompt(user);
    }

    return 0;
}