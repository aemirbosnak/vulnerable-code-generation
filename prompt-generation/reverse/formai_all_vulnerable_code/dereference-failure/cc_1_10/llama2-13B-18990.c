//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    struct command *cmds = NULL;
    int num_cmds = 0;

    // Initialize the command array
    cmds = calloc(MAX_CMD_LENGTH, sizeof(struct command));
    if (cmds == NULL) {
        printf("Error: unable to allocate memory for command array\n");
        return 1;
    }

    // Read commands from the user
    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Skip empty lines and comments
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Parse the command
        char *token = strtok(line, " ");
        struct command *cmd = calloc(1, sizeof(struct command));
        cmd->name = token;

        // Parse the arguments
        int i = 1;
        while ((token = strtok(NULL, " ")) != NULL) {
            cmd->args[i++] = token;
        }

        // Add the command to the list
        cmds = realloc(cmds, (num_cmds + 1) * sizeof(struct command));
        cmds[num_cmds++] = *cmd;

        // Free the command struct
        free(cmd);
    }

    // Execute the commands
    for (int i = 0; i < num_cmds; i++) {
        struct command *cmd = cmds + i;

        // Print the command
        printf("%s %s\n", cmd->name, cmd->args[0]);

        // Execute the command
        int status;
        if (execv(cmd->name, cmd->args) == -1) {
            perror(cmd->name);
        } else {
            wait(&status);
        }
    }

    // Free the command array
    free(cmds);

    return 0;
}