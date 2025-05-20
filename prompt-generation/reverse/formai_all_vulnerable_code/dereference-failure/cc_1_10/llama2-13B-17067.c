//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

// Function to execute a command and display the output
void execute_command(char *cmd) {
    int status;
    char *argv[MAX_ARGS];
    char *command = cmd;

    // Tokenize the command into individual arguments
    char *token = strtok(command, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS) {
        argv[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    // Execute the command
    if (execvp(command, argv) == -1) {
        perror("execvp failed");
        return;
    }

    // Wait for the command to complete
    wait(&status);

    // Display the command's output
    if (WIFEXITED(status)) {
        printf("Command completed with exit status %d\n", WEXITSTATUS(status));
    } else {
        printf("Command failed with status %d\n", status);
    }
}

int main() {
    // Example usage of the execute_command function
    execute_command("ls -l /");
    execute_command("cd /home");
    execute_command("pwd");
    execute_command("rm -rf /home/user/tempfile");
    execute_command("mkdir /home/user/newdir");
    execute_command("cp /home/user/file1 /home/user/newdir/file2");
    execute_command("cat /home/user/newdir/file2");

    return 0;
}