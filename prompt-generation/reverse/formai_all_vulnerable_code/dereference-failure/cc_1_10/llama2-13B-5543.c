//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: authentic
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
    struct command *cmd;
    int status;

    // Example 1: Running a command and capturing its output
    cmd = malloc(sizeof(struct command));
    cmd->name = "ls";
    cmd->args[0] = "-l";
    cmd->args[1] = "-t";

    printf("Running command: %s %s\n", cmd->name, cmd->args[0]);
    if (execv(cmd->name, cmd->args) == -1) {
        perror("execv failed");
        exit(1);
    }

    wait(&status);
    printf("Command completed with status %d\n", status);

    // Example 2: Running a command and redirecting its output
    cmd = malloc(sizeof(struct command));
    cmd->name = "grep";
    cmd->args[0] = "-E";
    cmd->args[1] = "\\b(foo|bar)";
    cmd->args[2] = "-H";
    cmd->args[3] = "-n";

    printf("Running command: %s %s %s %s\n", cmd->name, cmd->args[0], cmd->args[1], cmd->args[2]);
    if (execv(cmd->name, cmd->args) == -1) {
        perror("execv failed");
        exit(1);
    }

    wait(&status);
    printf("Command completed with status %d\n", status);

    // Example 3: Running a command and capturing its output to a file
    cmd = malloc(sizeof(struct command));
    cmd->name = "curl";
    cmd->args[0] = "http://www.example.com";

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        perror("fopen failed");
        exit(1);
    }

    cmd->args[1] = "-o";
    cmd->args[2] = "output.txt";

    printf("Running command: %s %s\n", cmd->name, cmd->args[1]);
    if (execv(cmd->name, cmd->args) == -1) {
        perror("execv failed");
        exit(1);
    }

    wait(&status);
    fclose(out);
    printf("Command completed with status %d\n", status);

    return 0;
}