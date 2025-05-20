//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1024

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} input_type;

typedef struct {
    input_type type;
    union {
        int ival;
        float fval;
        char *sval;
    };
} input_data;

input_data *sanitize_input(const char *input, input_type type) {
    input_data *data = malloc(sizeof(input_data));
    if (!data) {
        fprintf(stderr, "Error allocating memory for input data\n");
        return NULL;
    }

    data->type = type;
    switch (type) {
        case TYPE_INT:
            data->ival = atoi(input);
            break;
        case TYPE_FLOAT:
            data->fval = atof(input);
            break;
        case TYPE_STRING:
            data->sval = strdup(input);
            break;
        default:
            fprintf(stderr, "Invalid input type\n");
            free(data);
            return NULL;
    }

    return data;
}

void free_input_data(input_data *data) {
    if (!data) {
        return;
    }

    switch (data->type) {
        case TYPE_STRING:
            free(data->sval);
            break;
        default:
            break;
    }

    free(data);
}

int main(void) {
    char input[MAX_INPUT_LEN];
    input_data *data = NULL;

    printf("Enter an integer: ");
    if (fgets(input, MAX_INPUT_LEN, stdin)) {
        data = sanitize_input(input, TYPE_INT);
        if (data) {
            printf("Integer: %d\n", data->ival);
        } else {
            fprintf(stderr, "Error parsing integer\n");
        }
    } else {
        fprintf(stderr, "Error getting input\n");
    }

    printf("Enter a float: ");
    if (fgets(input, MAX_INPUT_LEN, stdin)) {
        data = sanitize_input(input, TYPE_FLOAT);
        if (data) {
            printf("Float: %f\n", data->fval);
        } else {
            fprintf(stderr, "Error parsing float\n");
        }
    } else {
        fprintf(stderr, "Error getting input\n");
    }

    printf("Enter a string: ");
    if (fgets(input, MAX_INPUT_LEN, stdin)) {
        data = sanitize_input(input, TYPE_STRING);
        if (data) {
            printf("String: %s\n", data->sval);
        } else {
            fprintf(stderr, "Error parsing string\n");
        }
    } else {
        fprintf(stderr, "Error getting input\n");
    }

    free_input_data(data);

    return 0;
}