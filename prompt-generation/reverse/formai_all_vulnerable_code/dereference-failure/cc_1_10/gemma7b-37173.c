//Gemma-7B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct CmdRecord {
    char **cmd_args;
    int cmd_argc;
    struct CmdRecord *next;
} CmdRecord;

CmdRecord *insert_cmd(char **args, int argc, CmdRecord *head) {
    CmdRecord *new_cmd = malloc(sizeof(CmdRecord));
    new_cmd->cmd_args = args;
    new_cmd->cmd_argc = argc;
    new_cmd->next = head;
    return new_cmd;
}

void execute_cmds(CmdRecord *head) {
    for (CmdRecord *curr = head; curr; curr = curr->next) {
        printf("Command: %s\n", curr->cmd_args[0]);
        for (int i = 0; i < curr->cmd_argc; i++) {
            printf("Arg: %s\n", curr->cmd_args[i]);
        }
        printf("\n");
    }
}

int main() {
    CmdRecord *cmd_head = NULL;

    char **args1 = malloc(MAX_CMD_LEN * sizeof(char *));
    args1[0] = "ls";
    args1[1] = "-l";
    insert_cmd(args1, 2, cmd_head);

    char **args2 = malloc(MAX_CMD_LEN * sizeof(char *));
    args2[0] = "pwd";
    insert_cmd(args2, 1, cmd_head);

    char **args3 = malloc(MAX_CMD_LEN * sizeof(char *));
    args3[0] = "echo";
    args3[1] = "Hello, world!";
    insert_cmd(args3, 2, cmd_head);

    execute_cmds(cmd_head);

    return 0;
}