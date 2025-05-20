//Falcon-180B DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_COMMANDS 10

typedef struct {
    char *command;
    int fd[2];
    pid_t pid;
} Command;

int main() {
    int num_commands = 0;
    Command commands[MAX_NUM_COMMANDS];

    while (num_commands < MAX_NUM_COMMANDS) {
        printf("Enter command (or type 'done' when finished): ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "done") == 0) {
            break;
        }

        commands[num_commands].command = strdup(command);
        pipe(commands[num_commands].fd);

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            close(commands[num_commands].fd[0]);
            dup2(commands[num_commands].fd[1], STDOUT_FILENO);
            close(commands[num_commands].fd[1]);

            char *argv[3];
            argv[0] = "sh";
            argv[1] = "-c";
            argv[2] = commands[num_commands].command;

            execvp("sh", argv);
            perror("execvp");
            exit(1);
        } else {
            close(commands[num_commands].fd[1]);
            commands[num_commands].pid = pid;
            num_commands++;
        }
    }

    for (int i = 0; i < num_commands; i++) {
        int status;
        waitpid(commands[i].pid, &status, 0);

        close(commands[i].fd[0]);
        close(commands[i].fd[1]);
        free(commands[i].command);
    }

    return 0;
}