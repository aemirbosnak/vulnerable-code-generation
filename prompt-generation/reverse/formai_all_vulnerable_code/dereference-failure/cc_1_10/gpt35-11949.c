//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

void welcome_message() {
    printf("\nWelcome to MyShell!\n");
    printf("Use 'exit' to exit the shell\n");
    printf("Use 'help' for more information\n\n");
}

void show_help() {
    printf("MyShell is a simple Unix-like shell\n");
    printf("Supported commands:\n");
    printf("  cd [directory]                       Change current working directory\n");
    printf("  pwd                                  Print current working directory\n");
    printf("  echo [args...]                       Print arguments to console\n");
    printf("  exit                                 Exit MyShell\n");
}

void change_dir(char *path) {
    if (chdir(path) != 0) {
        perror("Error while changing directory");
    }
}

char **parse_arguments(char *line) {
    int index = 0;
    char *token;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(line, " ");
    while (token != NULL) {
        arguments[index] = token;
        index++;
        token = strtok(NULL, " ");
    }

    arguments[index] = NULL;
    return arguments;
}

void run_command(char **arguments) {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0) { // child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error while running command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // fork error
        perror("Error while forking");
    } else { // parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char *command_line;
    char **arguments;
    size_t command_length = MAX_COMMAND_LENGTH;
    ssize_t chars_read;

    welcome_message();

    while (1) {
        printf("myshell> ");
        command_line = (char *) malloc(command_length * sizeof(char));
        chars_read = getline(&command_line, &command_length, stdin);

        if (chars_read == -1) {
            perror("Error while reading input");
        }

        command_line[strcspn(command_line, "\n")] = '\0'; // remove newline character

        if (strcmp(command_line, "exit") == 0) { // exit command
            free(command_line);
            printf("\nBye!\n");
            exit(EXIT_SUCCESS);
        } else if (strcmp(command_line, "help") == 0) { // help command
            show_help();
        } else if (strncmp(command_line, "cd", 2) == 0) { // cd command
            char *path = strtok(command_line + 3, " ");
            if (path == NULL) {
                path = getenv("HOME"); // change to home directory if no argument is provided
            }
            change_dir(path);
        } else { // other command
            arguments = parse_arguments(command_line);
            run_command(arguments);
            free(arguments);
        }

        free(command_line);
    }

    return EXIT_SUCCESS;
}