//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command)
{
    int argc = 0;
    char **argv = NULL;
    char delimiter = '\0';
    char *token = strtok_r(command, DELIM, &delimiter);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok_r(NULL, DELIM, &delimiter);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main(int argc, char *argv[])
{
    char input_buffer[MAX_COMMAND_LENGTH];
    FILE *input_file;
    char **arguments;
    int command_status;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <script_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, input_file)!= NULL) {
        arguments = split_command(input_buffer);
        command_status = execute_command(arguments);

        if (command_status == -1) {
            fprintf(stderr, "Error: Child process terminated abnormally.\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(input_file);
    exit(EXIT_SUCCESS);
}