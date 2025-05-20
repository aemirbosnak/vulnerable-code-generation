//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_NUM_ARGS 100
#define PROMPT "ExcitingShell> "

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("ExcitingShell Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("ExcitingShell Error");
    } else {
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);
    }
}

void parse_command(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

int main() {
    char *input = NULL;
    char *args[MAX_NUM_ARGS];
    size_t len = 0;

    printf("Welcome to ExcitingShell! 🌟\n");
  
    while (1) {
        printf("%s", PROMPT);
        getline(&input, &len, stdin);

        // Handle special built-in commands
        if (strcmp(input, "exit\n")==0) {
            printf("Exiting ExcitingShell. Have a great day! 🌈\n");
            break;
        } else if (strncmp(input, "cd ", 3) == 0) {
            char *dir = strtok(input + 3, " \n");
            if (dir == NULL) {
                fprintf(stderr, "ExcitingShell Error: cd requires a directory argument\n");
                continue;
            }
            if (chdir(dir) != 0) {
                perror("ExcitingShell Error");
            }
            continue;
        } else if (strncmp(input, "help", 4) == 0) {
            printf("ExcitingShell Help:\n");
            printf(" - cd <directory>: Change the current directory\n");
            printf(" - exit: Exit the shell\n");
            printf(" - Type any command you wish to execute!\n");
            continue;
        }

        char *args[MAX_NUM_ARGS];
        parse_command(input, args);
        execute_command(args);
    }

    free(input);
    return 0;
}