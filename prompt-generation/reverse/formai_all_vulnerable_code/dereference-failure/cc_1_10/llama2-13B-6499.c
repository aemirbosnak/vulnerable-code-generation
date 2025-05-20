//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    struct command *cmd;
    char *cmd_str;
    int status;

    // Example 1: Running a command and capturing the output
    cmd = malloc(sizeof(struct command));
    cmd->name = "ls";
    cmd->args[0] = "-l";
    cmd->args[1] = "-t";
    cmd_str = malloc(MAX_CMD_LENGTH);
    snprintf(cmd_str, MAX_CMD_LENGTH, "%s %s", cmd->name, cmd->args[0]);
    system(cmd_str);
    free(cmd_str);

    // Example 2: Running a command with arguments and capturing the output
    cmd = malloc(sizeof(struct command));
    cmd->name = "grep";
    cmd->args[0] = "-r";
    cmd->args[1] = "pattern";
    cmd_str = malloc(MAX_CMD_LENGTH);
    snprintf(cmd_str, MAX_CMD_LENGTH, "%s %s", cmd->name, cmd->args[0]);
    system(cmd_str);
    free(cmd_str);

    // Example 3: Running a command and capturing the exit status
    cmd = malloc(sizeof(struct command));
    cmd->name = "rm";
    cmd->args[0] = "-rf";
    cmd_str = malloc(MAX_CMD_LENGTH);
    snprintf(cmd_str, MAX_CMD_LENGTH, "%s %s", cmd->name, cmd->args[0]);
    status = system(cmd_str);
    free(cmd_str);
    printf("Command executed with status: %d\n", status);

    return 0;
}