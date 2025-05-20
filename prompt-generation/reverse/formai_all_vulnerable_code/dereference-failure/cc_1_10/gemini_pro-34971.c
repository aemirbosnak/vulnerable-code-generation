//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_STRING_SIZE 256
#define DEFAULT_MAX_ITERATIONS 100

typedef struct {
    char *string;
    size_t string_size;
    size_t max_iterations;
} palindrome_checker_config;

// Allocate and initialize a palindrome checker configuration with default values.
palindrome_checker_config *palindrome_checker_config_init() {
    palindrome_checker_config *config = malloc(sizeof(palindrome_checker_config));
    if (config == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for palindrome checker configuration.\n");
        return NULL;
    }
    config->string_size = DEFAULT_STRING_SIZE;
    config->max_iterations = DEFAULT_MAX_ITERATIONS;
    config->string = malloc(config->string_size);
    if (config->string == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for palindrome checker string.\n");
        free(config);
        return NULL;
    }
    return config;
}

// Free the resources allocated by a palindrome checker configuration.
void palindrome_checker_config_free(palindrome_checker_config *config) {
    if (config != NULL) {
        free(config->string);
        free(config);
    }
}

// Set the string to be checked for palindromicity.
void palindrome_checker_config_set_string(palindrome_checker_config *config, const char *string) {
    if (config != NULL) {
        strncpy(config->string, string, config->string_size);
    }
}

// Set the maximum number of iterations to perform when checking for palindromicity.
void palindrome_checker_config_set_max_iterations(palindrome_checker_config *config, size_t max_iterations) {
    if (config != NULL) {
        config->max_iterations = max_iterations;
    }
}

// Check whether a given string is a palindrome.
int is_palindrome(const char *string, size_t max_iterations) {
    size_t i = 0;
    size_t j = strlen(string) - 1;
    while (i < j && i < max_iterations) {
        if (string[i] != string[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Check whether the string specified in a palindrome checker configuration is a palindrome.
int palindrome_checker_check(palindrome_checker_config *config) {
    if (config != NULL) {
        return is_palindrome(config->string, config->max_iterations);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    palindrome_checker_config *config = palindrome_checker_config_init();
    if (config == NULL) {
        return EXIT_FAILURE;
    }
    if (argc > 1) {
        palindrome_checker_config_set_string(config, argv[1]);
    }
    if (argc > 2) {
        palindrome_checker_config_set_max_iterations(config, atoi(argv[2]));
    }
    int is_palindrome = palindrome_checker_check(config);
    printf("%s is %sa palindrome.\n", config->string, is_palindrome ? "" : "not ");
    palindrome_checker_config_free(config);
    return EXIT_SUCCESS;
}