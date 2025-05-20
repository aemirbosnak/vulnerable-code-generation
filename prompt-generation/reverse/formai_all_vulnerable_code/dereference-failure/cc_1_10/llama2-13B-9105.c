//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
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
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int status;

    while (1) {
        printf("$ ");
        fgets(cmd_name, MAX_CMD_LEN, stdin);
        cmd_name[strcspn(cmd_name, "\n")] = 0; // trim newline

        char *token;
        char *args_ptr = cmd_name;
        int i = 0;

        while ((token = strtok_r(args_ptr, " \t", &i)) != NULL) {
            cmd_args[i] = token;
            args_ptr = NULL;
        }

        if (cmd_args[0] == NULL) {
            printf("Error: no command specified\n");
            continue;
        }

        // execute the command
        if (execv(cmd_name, cmd_args) == -1) {
            perror("execv");
            printf("Error: unable to execute %s\n", cmd_name);
            continue;
        }

        // wait for the command to finish
        wait(&status);

        // print the command's exit status
        printf("%s exited with status %d\n", cmd_name, status);
    }

    return 0;
}