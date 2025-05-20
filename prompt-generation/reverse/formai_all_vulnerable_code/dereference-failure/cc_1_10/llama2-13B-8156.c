//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    struct command *cmds = NULL;
    int num_cmds = 0;

    // Brave sysadmin here, we don't need no stinkin' prompt!
    setvbuf(stdin, NULL, _IONBF, 0);

    while (1) {
        // Read a command from the user, or die trying!
        char buffer[1024];
        fread(buffer, 1, sizeof(buffer), stdin);
        buffer[sizeof(buffer) - 1] = '\0'; // Just in case...

        // Tokenize the command into args
        char *token = strtok(buffer, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            cmds[num_cmds].args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        // Add the command to the list
        if (num_cmds < MAX_CMD_LENGTH) {
            cmds[num_cmds].name = buffer;
            num_cmds++;
        } else {
            printf("Too many commands! (%d >= %d)\n", num_cmds, MAX_CMD_LENGTH);
            break;
        }
    }

    // Execute all the commands!
    for (int i = 0; i < num_cmds; i++) {
        int status;
        char *command = cmds[i].name;
        char **args = cmds[i].args;

        // Create a new process
        pid_t pid = fork();
        if (pid == 0) {
            // In the child process, execute the command
            execv(command, args);
            _exit(1); // Never reach this line...
        } else if (pid > 0) {
            // In the parent process, wait for the child to finish
            wait(&status);
        } else {
            // Oops, failed to fork!
            perror("fork() failed");
        }
    }

    return 0;
}