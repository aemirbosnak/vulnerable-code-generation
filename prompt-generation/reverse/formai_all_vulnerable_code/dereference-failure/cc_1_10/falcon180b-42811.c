//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_LENGTH 1024
#define MAX_ENV_LENGTH 1024

typedef struct {
    char **argv;
    char **envp;
    int argc;
    int envc;
} command_t;

void execute_command(command_t *cmd) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork()\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(cmd->argv[0], cmd->argv) == -1) {
            fprintf(stderr, "Failed to execvp()\n");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument]...\n", argv[0]);
        exit(1);
    }

    command_t cmd = {NULL, NULL, 0, 0};
    cmd.argv = malloc((argc - 1) * sizeof(char *));
    cmd.envp = malloc(MAX_ENV_LENGTH);

    int i;
    for (i = 0; i < argc - 1; i++) {
        if (strlen(argv[i + 1]) >= MAX_ARG_LENGTH) {
            fprintf(stderr, "Argument too long\n");
            exit(1);
        }
        cmd.argv[i] = argv[i + 1];
    }
    cmd.argc = argc - 1;

    execute_command(&cmd);

    return 0;
}