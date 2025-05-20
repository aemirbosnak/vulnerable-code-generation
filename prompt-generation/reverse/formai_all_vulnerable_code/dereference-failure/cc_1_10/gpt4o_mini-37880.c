//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define DELIMITER " \t\r\n\a"

void execute_command(char **args);
char **split_line(char *line);
void loop(void);
int cd(char **args);
int exit_shell(char **args);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("introspective-shell> ");
        line = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
            free(line);
            break;
        }
        
        args = split_line(line);
        if (args[0] != NULL) { // Only execute if there is a command
            execute_command(args);
        }
        
        free(line);
        free(args);
    } while (1);
}

char **split_line(char *line) {
    int bufsize = TOKEN_SIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += TOKEN_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMITER);
    }
    tokens[position] = NULL;
    return tokens;
}

void execute_command(char **args) {
    if (args[0] == NULL) {
        // An empty command was entered.
        return;
    }

    if (strcmp(args[0], "cd") == 0) {
        cd(args);
        return;
    }
    if (strcmp(args[0], "exit") == 0) {
        exit_shell(args);
        return;
    }

    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Error");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "introspective-shell: cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("introspective-shell");
        }
    }
    return 1; // Return to the shell loop
}

int exit_shell(char **args) {
    return 0; // Exit signal to the shell loop
}