//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PARANOID_CHECK(condition, error_str)                                \
    do {                                                                       \
        if (!(condition)) {                                                    \
            fprintf(stderr, "Paranoid check failed: %s\n", error_str);       \
            abort();                                                          \
        }                                                                      \
    } while (0)

#define PARANOID_CHECK_RET(condition, error_str, ret_val)                     \
    do {                                                                       \
        if (!(condition)) {                                                    \
            fprintf(stderr, "Paranoid check failed: %s\n", error_str);       \
            abort();                                                          \
        }                                                                      \
    } while (0); return (ret_val)

#define PARANOID_CHECK_NO_RET(condition, error_str)                            \
    do {                                                                       \
        if (!(condition)) {                                                    \
            fprintf(stderr, "Paranoid check failed: %s\n", error_str);       \
            abort();                                                          \
        }                                                                      \
    } while (0)

int main(int argc, char **argv) {
    char *input_str = NULL;
    size_t input_len = 0;
    char *output_str = NULL;
    size_t output_len = 0;
    int i;

    PARANOID_CHECK(argc == 2, "Invalid number of arguments");
    PARANOID_CHECK(strlen(argv[1]) > 0, "Input string cannot be empty");

    // Allocate memory for input and output strings
    input_len = strlen(argv[1]);
    input_str = malloc(input_len + 1);
    PARANOID_CHECK(input_str != NULL, "Failed to allocate memory for input string");
    memcpy(input_str, argv[1], input_len);
    input_str[input_len] = '\0';

    // Perform some paranoid checks on the input string
    for (i = 0; i < input_len; i++) {
        PARANOID_CHECK((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == ' ', "Input string contains invalid characters");
    }

    // Convert the input string to an integer
    uint64_t input_int = 0;
    for (i = 0; i < input_len; i++) {
        if (input_str[i] != ' ') {
            input_int = input_int * 10 + (input_str[i] - '0');
        }
    }

    // Perform some more paranoid checks on the input integer
    PARANOID_CHECK(input_int > 0, "Input integer must be positive");
    PARANOID_CHECK_NO_RET(input_int <= UINT64_MAX, "Input integer is too large");

    // Allocate memory for the output string
    output_len = input_len + 1;
    output_str = malloc(output_len);
    PARANOID_CHECK(output_str != NULL, "Failed to allocate memory for output string");

    // Convert the input integer to a string
    sprintf(output_str, "%llu", input_int);

    // Print the output string
    printf("%s\n", output_str);

    // Free the allocated memory
    free(input_str);
    free(output_str);

    return 0;
}