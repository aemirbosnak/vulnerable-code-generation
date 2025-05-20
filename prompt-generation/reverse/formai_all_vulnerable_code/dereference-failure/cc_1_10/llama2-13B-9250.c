//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int cmd_status;
    int fd;

    while (1) {
        printf("$ ");
        fgets(cmd_name, MAX_CMD_LEN, stdin);
        cmd_name[strcspn(cmd_name, "\n")] = 0;

        if (cmd_name[0] == '\0') {
            continue;
        }

        // Tokenize the command
        char *token = strtok(cmd_name, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            cmd_args[i++] = token;
            token = strtok(NULL, " ");
        }

        // Execute the command
        if (execvp(cmd_name, cmd_args) == -1) {
            perror("execvp");
            exit(1);
        }

        // Wait for the command to finish
        cmd_status = wait(&fd);
        if (cmd_status == -1) {
            perror("wait");
            exit(1);
        }

        // Display the command status
        printf("Command %s exited with status %d\n", cmd_name, cmd_status);
    }

    return 0;
}