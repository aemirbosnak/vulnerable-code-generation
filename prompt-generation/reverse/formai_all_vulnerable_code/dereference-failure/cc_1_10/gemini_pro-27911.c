//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define a macro to check for errors and handle them paranoidly.
#define CHECK_ERROR(expr) do {                                  \
    int32_t err = (expr);                                       \
    if (err != 0) {                                              \
        fprintf(stderr, "Error: %s (%d)\n", #expr, err);         \
        exit(EXIT_FAILURE);                                      \
    }                                                           \
} while (0)

// Define a type to represent a paranoid mathematician.
typedef struct {
    int32_t paranoia_level;
    char *name;
} paranoid_mathematician_t;

// Define a function to create a new paranoid mathematician.
paranoid_mathematician_t *new_paranoid_mathematician(int32_t paranoia_level, const char *name) {
    paranoid_mathematician_t *mathematician = malloc(sizeof(paranoid_mathematician_t));
    CHECK_ERROR(mathematician == NULL);

    mathematician->paranoia_level = paranoia_level;
    mathematician->name = malloc(strlen(name) + 1);
    CHECK_ERROR(mathematician->name == NULL);
    strcpy(mathematician->name, name);

    return mathematician;
}

// Define a function to free a paranoid mathematician.
void free_paranoid_mathematician(paranoid_mathematician_t *mathematician) {
    if (mathematician != NULL) {
        free(mathematician->name);
        free(mathematician);
    }
}

// Define a function to perform a paranoid mathematical operation.
int32_t paranoid_mathematical_operation(paranoid_mathematician_t *mathematician, int32_t a, int32_t b) {
    // Check the paranoia level of the mathematician.
    if (mathematician->paranoia_level < 1) {
        return a + b;
    }

    // Otherwise, perform the operation with paranoia.
    int32_t result = a + b;

    // Check the result for errors.
    if (result < 0) {
        fprintf(stderr, "Error: Result of operation overflowed (%d)\n", result);
        exit(EXIT_FAILURE);
    }

    // Check the result for reasonableness.
    if (abs(result) > 1000000) {
        fprintf(stderr, "Error: Result of operation is unreasonable (%d)\n", result);
        exit(EXIT_FAILURE);
    }

    // Return the result.
    return result;
}

// Define a function to write the result of a paranoid mathematical operation to a file.
void write_paranoid_mathematical_operation_result(paranoid_mathematician_t *mathematician, int32_t a, int32_t b, int32_t result, const char *filename) {
    // Open the file for writing.
    FILE *file = fopen(filename, "w");
    CHECK_ERROR(file == NULL);

    // Write the result to the file.
    fprintf(file, "Result of operation: %d (%s)\n", result, mathematician->name);

    // Close the file.
    CHECK_ERROR(fclose(file) != 0);
}

// Define a function to run a series of paranoid mathematical operations.
void run_paranoid_mathematical_operations(paranoid_mathematician_t *mathematician, int32_t a, int32_t b) {
    // Perform the operation with paranoia.
    int32_t result = paranoid_mathematical_operation(mathematician, a, b);

    // Write the result to a file.
    write_paranoid_mathematical_operation_result(mathematician, a, b, result, "result.txt");
}

// Define a function to main.
int main(void) {
    // Create a paranoid mathematician.
    paranoid_mathematician_t *mathematician = new_paranoid_mathematician(10, "Dr. Paranoia");

    // Run a series of paranoid mathematical operations.
    run_paranoid_mathematical_operations(mathematician, 1, 2);
    run_paranoid_mathematical_operations(mathematician, 10, 20);
    run_paranoid_mathematical_operations(mathematician, 100, 200);

    // Free the paranoid mathematician.
    free_paranoid_mathematician(mathematician);

    return EXIT_SUCCESS;
}