//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    struct command *cmd;

    while (1) {
        printf(" Peaceful system administration console...\n");

        cmd_name = malloc(MAX_CMD_LENGTH);
        printf("Enter a command (type 'help' for list of commands): ");
        fgets(cmd_name, MAX_CMD_LENGTH, stdin);

        // Parse command and arguments
        char *token;
        token = strtok(cmd_name, " ");
        cmd->name = token;
        int i = 0;
        while ((token = strtok(NULL, " ")) != NULL) {
            cmd->args[i] = token;
            i++;
        }

        // Execute command
        if (strcmp(cmd->name, "help") == 0) {
            printf("Commands available:\n");
            printf("  help                  Show this message and exit\n");
            printf("  status                Show system status\n");
            printf("  reboot               Reboot the system\n");
            printf("  shutdown             Shut down the system\n");
            printf("  logout               Log out current user\n");
        } else if (strcmp(cmd->name, "status") == 0) {
            printf("System status: UP\n");
        } else if (strcmp(cmd->name, "reboot") == 0) {
            printf("Rebooting system...\n");
            reboot(0);
        } else if (strcmp(cmd->name, "shutdown") == 0) {
            printf("Shutting down system...\n");
            shutdown(0);
        } else if (strcmp(cmd->name, "logout") == 0) {
            printf("Logging out current user...\n");
            logout();
        } else {
            printf("Invalid command\n");
        }

        free(cmd_name);
    }

    return 0;
}