//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to handle system calls
int system_call(char *command) {
    // Create a child process
    int pid = fork();
    if (pid == 0) {
        // Child process
        execlp("/bin/sh", "sh", "-c", command, NULL);
        _exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        int status;
        wait(&status);
        return status;
    } else {
        // Error
        perror("fork");
        return EXIT_FAILURE;
    }
}

// Function to check for suspicious activity
int check_activity(char *command) {
    // Check if the command is suspicious
    if (strstr(command, "rm -rf") != NULL ||
        strstr(command, "dd if=/dev/zero of=/dev/sda") != NULL ||
        strstr(command, "wget http://example.com/malware.exe") != NULL) {
        return 1;
    }

    // Recursively check for suspicious activity in the command's arguments
    char **args = malloc(sizeof(char *) * 10);
    int argc = 0;
    char *ptr = strtok(command, " ");
    while (ptr != NULL) {
        args[argc++] = ptr;
        ptr = strtok(NULL, " ");
    }
    if (args[0] != NULL) {
        for (int i = 0; i < argc; i++) {
            if (check_activity(args[i])) {
                free(args);
                return 1;
            }
        }
    }
    free(args);

    // No suspicious activity found
    return 0;
}

int main() {
    // Main loop
    while (1) {
        // Get the current command from the user
        char command[1024];
        printf("Enter a command: ");
        scanf("%s", command);

        // Check for suspicious activity in the command
        int suspicious = check_activity(command);

        // If the command is suspicious, terminate the program
        if (suspicious) {
            printf("Suspicious activity detected!\n");
            exit(EXIT_FAILURE);
        }

        // Otherwise, execute the command
        else {
            system_call(command);
        }
    }

    return 0;
}