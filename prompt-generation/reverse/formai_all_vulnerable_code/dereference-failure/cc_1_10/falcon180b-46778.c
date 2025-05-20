//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;
    
    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    
    return argv;
}

int main_loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int status;
    
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    
    argv = split_command(input);
    status = system(argv[0]);
    
    free(argv[0]);
    free(argv);
    
    return status;
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    
    if (argc == 1) {
        printf("Welcome to the Basic Unix-like Shell!\n");
        printf("Type 'help' for a list of available commands.\n");
        printf("Type 'exit' to quit.\n");
    } else {
        main_loop();
    }
    
    return 0;
}