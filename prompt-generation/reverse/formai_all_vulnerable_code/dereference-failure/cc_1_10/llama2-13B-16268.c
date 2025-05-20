//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    struct command *cmd;
    int pid;

    // Example 1: Running a command and capturing its output
    cmd = malloc(sizeof(struct command));
    cmd->name = "ls";
    cmd->args[0] = "-l";
    cmd->args[1] = "/usr/bin/ls";
    pid = fork();
    if (pid == 0) {
        execv("/usr/bin/ls", cmd->args);
    } else {
        wait(NULL);
    }
    free(cmd);

    // Example 2: Running a command and redirecting its output
    cmd = malloc(sizeof(struct command));
    cmd->name = "grep";
    cmd->args[0] = "-E";
    cmd->args[1] = "'(^| )net( |$)'";
    cmd->args[2] = "-H";
    cmd->args[3] = "/etc/hosts";
    cmd->args[4] = "-n";
    pid = fork();
    if (pid == 0) {
        dup2(1, 2);
        execv("/bin/grep", cmd->args);
    } else {
        wait(NULL);
    }
    free(cmd);

    // Example 3: Running a command and capturing its error
    cmd = malloc(sizeof(struct command));
    cmd->name = "rm";
    cmd->args[0] = "-rf";
    cmd->args[1] = "/tmp";
    pid = fork();
    if (pid == 0) {
        execv("/bin/rm", cmd->args);
    } else {
        wait(NULL);
    }
    free(cmd);

    return 0;
}