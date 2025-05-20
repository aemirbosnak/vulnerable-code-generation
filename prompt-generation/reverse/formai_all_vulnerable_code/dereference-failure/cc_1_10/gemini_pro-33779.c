//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 1024

// Define the maximum number of arguments that can be passed to the program
#define MAX_ARGS 10

// Define the structure of a single argument
typedef struct {
    char *name;
    char *value;
} argument_t;

// Define the structure of the program's configuration
typedef struct {
    int argc;
    argument_t *argv;
} config_t;

// Define the function to parse the command line arguments
config_t *parse_args(int argc, char **argv) {
    config_t *config = malloc(sizeof(config_t));
    config->argc = argc;
    config->argv = malloc(sizeof(argument_t) * argc);

    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        char *name = strtok(arg, "=");
        char *value = strtok(NULL, "=");

        config->argv[i].name = strdup(name);
        config->argv[i].value = strdup(value);
    }

    return config;
}

// Define the function to free the memory allocated by the program
void free_memory(config_t *config) {
    for (int i = 0; i < config->argc; i++) {
        free(config->argv[i].name);
        free(config->argv[i].value);
    }

    free(config->argv);
    free(config);
}

// Define the function to print the program's configuration
void print_config(config_t *config) {
    printf("Configuration:\n");
    for (int i = 0; i < config->argc; i++) {
        printf("%s = %s\n", config->argv[i].name, config->argv[i].value);
    }
}

// Define the main function
int main(int argc, char **argv) {
    // Parse the command line arguments
    config_t *config = parse_args(argc, argv);

    // Print the program's configuration
    print_config(config);

    // Free the memory allocated by the program
    free_memory(config);

    return 0;
}