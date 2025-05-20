//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char *error_msg;
    int error_code;
} error_t;

error_t *create_error(const char *error_msg, int error_code) {
    error_t *error = malloc(sizeof(error_t));
    if (error == NULL) {
        return NULL;
    }

    error->error_msg = malloc(strlen(error_msg) + 1);
    if (error->error_msg == NULL) {
        free(error);
        return NULL;
    }

    strcpy(error->error_msg, error_msg);
    error->error_code = error_code;

    return error;
}

void free_error(error_t *error) {
    free(error->error_msg);
    free(error);
}

void print_error(error_t *error) {
    printf("Error: %s (code %d)\n", error->error_msg, error->error_code);
}

int main(void) {
    char *input = NULL;
    size_t input_len = 0;
    ssize_t bytes_read;

    printf("Enter a string: ");
    bytes_read = getline(&input, &input_len, stdin);
    if (bytes_read == -1) {
        error_t *error = create_error("Error reading input", 1);
        print_error(error);
        free_error(error);
        return EXIT_FAILURE;
    }

    if (strlen(input) > MAX_STR_LEN) {
        error_t *error = create_error("Input string too long", 2);
        print_error(error);
        free_error(error);
        return EXIT_FAILURE;
    }

    printf("Input string: %s", input);

    free(input);

    return EXIT_SUCCESS;
}