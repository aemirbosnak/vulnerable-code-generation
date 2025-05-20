//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define a configuration structure to store the desired behavior of the program.
typedef struct {
    int num_levels;     // The number of levels to recurse.
    int base_case;     // The base case for the recursion.
    int increment;     // The amount to increment the value at each level of recursion.
    int print_result;  // Whether to print the result of each level of recursion.
} config_t;

// Define a function to print the configuration.
void print_config(config_t config) {
    printf("Configuration:\n");
    printf("  Number of levels: %d\n", config.num_levels);
    printf("  Base case: %d\n", config.base_case);
    printf("  Increment: %d\n", config.increment);
    printf("  Print result: %d\n", config.print_result);
}

// Define a function to recursively calculate the value of the expression.
int calculate_value(config_t config, int level) {
    // If the base case is reached, return the base case value.
    if (level == config.base_case) {
        return config.base_case;
    }
    // Otherwise, recursively calculate the value of the expression.
    else {
        int value = calculate_value(config, level - 1);
        // Increment the value by the specified amount.
        value += config.increment;
        // If the print result flag is set, print the result of this level of recursion.
        if (config.print_result) {
            printf("Level %d: %d\n", level, value);
        }
        // Return the value of the expression.
        return value;
    }
}

// Define a function to run the program.
int main(int argc, char** argv) {
    // Parse the command line arguments.
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <num_levels> <base_case> <increment> <print_result>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the configuration values.
    config_t config;
    config.num_levels = atoi(argv[1]);
    config.base_case = atoi(argv[2]);
    config.increment = atoi(argv[3]);
    config.print_result = atoi(argv[4]);

    // Print the configuration.
    print_config(config);

    // Calculate and print the value of the expression.
    int result = calculate_value(config, config.num_levels);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}