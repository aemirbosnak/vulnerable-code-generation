//FormAI DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

void prompt() {
    printf(">>> ");
}

int main() {
    while(1) {
        prompt();

        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error: fork failed\n");
            continue;
        } else if (pid == 0) {
            // child process
            char* command_args[MAX_COMMAND_LENGTH];
            char* token;
            char* saveptr;

            int i = 0;
            token = strtok_r(command, " ", &saveptr);
            while (token != NULL) {
                command_args[i++] = token;
                token = strtok_r(NULL, " ", &saveptr);
            }
            command_args[i] = NULL;

            int exec_error = execvp(command_args[0], command_args);
            if (exec_error == -1) {
                printf("Error: %s\n", strerror(errno));
            }

            exit(0);
        } else {
            // parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}