//Falcon-180B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096

char *get_shell(void) {
    const char *shell = getenv("SHELL");
    if (shell == NULL) {
        shell = "/bin/sh";
    }
    return strdup(shell);
}

int execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        char *args[4];
        args[0] = get_shell();
        args[1] = "-c";
        args[2] = command;
        args[3] = NULL;

        execvp(args[0], args);
        perror("execvp");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (strlen(token) > MAX_LINE_LENGTH) {
            printf("Error: Command too long.\n");
            return 1;
        }
        token = strtok(NULL, " ");
    }

    int result = execute_command(command);
    if (result == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Error executing command.\n");
    }

    return result;
}