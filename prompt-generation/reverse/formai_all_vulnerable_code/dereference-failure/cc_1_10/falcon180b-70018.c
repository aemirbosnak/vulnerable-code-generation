//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);
int launch_shell(char **args);
int change_directory(char **args);
int print_working_directory(void);

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Welcome to the Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if(args[0] == NULL)
            continue;

        status = execute_command(args);

        if(status == 127) {
            printf("Command not found.\n");
        } else if(status == 126) {
            printf("Permission denied.\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int i, j, words = 0;
    char **tokens;
    char delimiter[] = DELIM;

    tokens = (char **) malloc((MAX_COMMAND_LENGTH / 4) * sizeof(char *));

    for(i=0, j=0; string[i]!= '\0'; i++) {
        if(strchr(delimiter, string[i])!= NULL) {
            string[i] = '\0';
            tokens[words] = &string[j];
            j = i + 1;
            words++;
        }
    }

    tokens[words] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL)
        return 1;

    if(strcmp(args[0], "cd") == 0) {
        return change_directory(args);
    } else if(strcmp(args[0], "shell") == 0) {
        return launch_shell(args);
    } else if(strcmp(args[0], "pwd") == 0) {
        return print_working_directory();
    } else {
        pid = fork();

        if(pid == -1) {
            perror("fork");
            return 127;
        } else if(pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(126);
        } else {
            waitpid(pid, &status, 0);
            return status;
        }
    }
}

int launch_shell(char **args) {
    char *new_args[3];

    new_args[0] = "shell";
    new_args[1] = NULL;

    return execute_command(new_args);
}

int change_directory(char **args) {
    if(args[1] == NULL) {
        printf("Expected argument to \"cd\".\n");
        return 1;
    }

    if(chdir(args[1])!= 0) {
        perror("chdir");
        return 1;
    }

    return 0;
}

int print_working_directory(void) {
    char cwd[1024];

    if(getcwd(cwd, sizeof(cwd))!= NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}