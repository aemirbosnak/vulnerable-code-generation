//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 100
#define MAX_PIPE_LENGTH 1000

typedef struct command_t {
    char *name;
    void (*function)(char **);
} command_t;

void execute_command(char **arguments) {
    printf("Executing command: %s\n", arguments[0]);
}

void help_command(char **) {
    printf("Available commands:\n");
    printf("  help\n");
    printf("  execute\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands].name = "help";
    commands[num_commands].function = help_command;
    num_commands++;

    commands[num_commands].name = "execute";
    commands[num_commands].function = execute_command;
    num_commands++;

    char *command_name = argv[1];
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            char **arguments = (char **) malloc(sizeof(char *) * (argc - 2));
            int j;
            for (j = 2; j < argc; j++) {
                arguments[j - 2] = argv[j];
            }
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, commands[i].function, arguments);
            free(arguments);
            return 0;
        }
    }

    printf("Invalid command: %s\n", command_name);
    return 1;
}