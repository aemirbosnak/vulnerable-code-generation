//Falcon-180B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);
    
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    
    argv[argc] = NULL;
    return argv;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **argv;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        
        argv = split_command(input_buffer);
        if (argv[0] == NULL) {
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}