//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *string);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char input_buffer[BUFFER_SIZE];
    char *command = NULL;
    size_t command_length = 0;

    while (1) {
        printf("> ");
        if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input.\n");
            exit(1);
        }

        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        strcat(command, input_buffer);
        command_length += strlen(input_buffer);

        if (command_length >= MAX_COMMAND_LENGTH) {
            printf("Command too long.\n");
            exit(1);
        }

        if (input_buffer[0] == '\n' || input_buffer[0] == ';') {
            command[command_length] = '\0';
            execute_command(split_string(command));
            command_length = 0;
            command = NULL;
        }
    }
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

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
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}