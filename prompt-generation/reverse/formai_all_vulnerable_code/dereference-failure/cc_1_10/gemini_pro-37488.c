//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef enum {
    INPUT_TYPE_UNKNOWN,
    INPUT_TYPE_INTEGER,
    INPUT_TYPE_FLOAT,
    INPUT_TYPE_STRING,
} input_type_t;

typedef struct {
    input_type_t type;
    union {
        int integer;
        float floating_point;
        char *string;
    } value;
} input_value_t;

typedef struct {
    char *buffer;
    size_t size;
} input_buffer_t;

input_type_t get_input_type(const char *input)
{
    if (strspn(input, "0123456789") == strlen(input)) {
        return INPUT_TYPE_INTEGER;
    } else if (strspn(input, "0123456789.") == strlen(input)) {
        return INPUT_TYPE_FLOAT;
    } else {
        return INPUT_TYPE_STRING;
    }
}

input_value_t parse_input(const char *input)
{
    input_value_t value;

    switch (get_input_type(input)) {
        case INPUT_TYPE_INTEGER:
            value.type = INPUT_TYPE_INTEGER;
            value.value.integer = atoi(input);
            break;
        case INPUT_TYPE_FLOAT:
            value.type = INPUT_TYPE_FLOAT;
            value.value.floating_point = atof(input);
            break;
        case INPUT_TYPE_STRING:
            value.type = INPUT_TYPE_STRING;
            value.value.string = strdup(input);
            break;
        default:
            value.type = INPUT_TYPE_UNKNOWN;
            break;
    }

    return value;
}

void free_input_value(input_value_t value)
{
    if (value.type == INPUT_TYPE_STRING) {
        free(value.value.string);
    }
}

int main()
{
    input_buffer_t buffer;
    input_value_t value;

    buffer.size = MAX_INPUT_SIZE;
    buffer.buffer = malloc(buffer.size);

    printf("Enter a value: ");
    if (fgets(buffer.buffer, buffer.size, stdin) == NULL) {
        fprintf(stderr, "Error: could not read input\n");
        return EXIT_FAILURE;
    }

    value = parse_input(buffer.buffer);

    switch (value.type) {
        case INPUT_TYPE_INTEGER:
            printf("You entered an integer: %d\n", value.value.integer);
            break;
        case INPUT_TYPE_FLOAT:
            printf("You entered a floating-point number: %f\n", value.value.floating_point);
            break;
        case INPUT_TYPE_STRING:
            printf("You entered a string: %s\n", value.value.string);
            break;
        default:
            printf("You entered an invalid value\n");
            break;
    }

    free_input_value(value);
    free(buffer.buffer);

    return EXIT_SUCCESS;
}