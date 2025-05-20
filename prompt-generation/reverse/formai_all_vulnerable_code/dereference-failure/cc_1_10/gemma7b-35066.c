//Gemma-7B DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
    char **cmd_line;
    int cmd_size;
    struct Command *next;
} Command;

Command *create_command(char **cmd_line, int cmd_size) {
    Command *new_cmd = malloc(sizeof(Command));
    new_cmd->cmd_line = cmd_line;
    new_cmd->cmd_size = cmd_size;
    new_cmd->next = NULL;
    return new_cmd;
}

void execute_command(Command *cmd) {
    int i = 0;
    char **args = cmd->cmd_line;
    for (i = 0; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
}

int main() {
    Command *head = NULL;
    char cmd_line[MAX_CMD_LEN];

    while (1) {
        printf("Enter command: ");
        fgets(cmd_line, MAX_CMD_LEN, stdin);

        if (strcmp(cmd_line, "exit") == 0) {
            break;
        }

        char **args = malloc(MAX_CMD_LEN);
        int i = 0;
        args[i] = strtok(cmd_line, " ");
        while ((args[i] = strtok(NULL, " ")) != NULL) {
            i++;
        }

        head = create_command(args, i);
        execute_command(head);
    }

    return 0;
}