//Falcon-180B DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

char **split_command(char *command, int *arguments_count) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    int current_argument = 0;
    char *token = strtok(command, " ");
    
    while (token!= NULL) {
        arguments[current_argument] = strdup(token);
        current_argument++;
        token = strtok(NULL, " ");
    }
    
    arguments[current_argument] = NULL;
    *arguments_count = current_argument;
    
    return arguments;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int arguments_count;
    
    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        
        arguments = split_command(input_buffer, &arguments_count);
        
        if (arguments_count == 0) {
            continue;
        }
        
        pid_t pid = fork();
        
        if (pid == 0) {
            execvp(arguments[0], arguments);
            perror("execvp");
            exit(1);
        } else if (pid < 0) {
            perror("fork");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
        
        for (int i = 0; i < arguments_count; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }
    
    return 0;
}