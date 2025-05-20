//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void print_prompt(char *prompt);

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *command_line = NULL;
    size_t command_line_length = 0;
    char **args = NULL;
    int status;

    print_prompt("> ");

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (command_line!= NULL) {
            strcat(command_line, input_buffer);
        } else {
            command_line = strdup(input_buffer);
        }
        command_line_length += strlen(input_buffer);

        if (command_line_length >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: Command too long.\n");
            exit(1);
        }

        if (input_buffer[strlen(input_buffer) - 1] == '\n') {
            input_buffer[strlen(input_buffer) - 1] = '\0';
            args = split_line(command_line);
            status = execute_command(args);
            free(command_line);
            command_line = NULL;
            command_line_length = 0;
        }
    }

    return 0;
}

char **split_line(char *line) {
    char **args = malloc(sizeof(char *));
    args[0] = strtok(line, DELIM);
    int count = 1;

    while ((args[count] = strtok(NULL, DELIM))!= NULL) {
        count++;
        args = realloc(args, sizeof(char *) * count);
    }

    args[count] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void print_prompt(char *prompt) {
    fprintf(stdout, "%s", prompt);
    fflush(stdout);
}