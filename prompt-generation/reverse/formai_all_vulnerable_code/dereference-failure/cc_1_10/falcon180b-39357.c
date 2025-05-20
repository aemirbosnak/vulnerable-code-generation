//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    char **tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int num_tokens = 0;
    char *token = strtok(command, DELIM);
    
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    
    tokens[num_tokens] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;
    
    if (tokens[0] == NULL) {
        return 1;
    }
    
    pid = fork();
    
    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
    
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int status;
    
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    
    tokens = split_command(input);
    status = execute_command(tokens);
    
    if (status == 0) {
        loop();
    }
}

int main(void) {
    loop();
    
    return 0;
}