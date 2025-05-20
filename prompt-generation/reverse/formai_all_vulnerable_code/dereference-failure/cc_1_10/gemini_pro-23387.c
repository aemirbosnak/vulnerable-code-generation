//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    int size;
    int capacity;
} Buffer;

void buffer_init(Buffer *buffer, int capacity) {
    buffer->buffer = malloc(capacity);
    if (buffer->buffer == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    buffer->size = 0;
    buffer->capacity = capacity;
}

void buffer_free(Buffer *buffer) {
    free(buffer->buffer);
}

bool buffer_append(Buffer *buffer, char *string) {
    int length = strlen(string);
    if (buffer->size + length + 1 > buffer->capacity) {
        fprintf(stderr, "Error: buffer full\n");
        exit(EXIT_FAILURE);
    }
    strcpy(buffer->buffer + buffer->size, string);
    buffer->size += length;
    buffer->buffer[buffer->size] = '\0';
    return true;
}

bool buffer_isdigit(Buffer *buffer) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        if (buffer->buffer[i] < '0' || buffer->buffer[i] > '9') {
            return false;
        }
    }
    return true;
}

double buffer_to_double(Buffer *buffer) {
    double value;
    if (buffer->size == 0) {
        return 0.0;
    }
    value = strtod(buffer->buffer, NULL);
    return value;
}

int main(int argc, char **argv) {
    Buffer buffer;
    char input[MAX_BUFFER_SIZE];
    double value1, value2;
    int operator;

    buffer_init(&buffer, MAX_BUFFER_SIZE);

    while (true) {
        printf("> ");
        fgets(input, MAX_BUFFER_SIZE, stdin);
        if (feof(stdin)) {
            break;
        }
        buffer_append(&buffer, input);

        if (buffer_isdigit(&buffer)) {
            value1 = buffer_to_double(&buffer);
        } else {
            operator = input[0];
            value1 = buffer_to_double(&buffer);
            fgets(input, MAX_BUFFER_SIZE, stdin);
            buffer_append(&buffer, input);
            value2 = buffer_to_double(&buffer);
        }

        switch (operator) {
            case '+':
                printf("%f\n", value1 + value2);
                break;
            case '-':
                printf("%f\n", value1 - value2);
                break;
            case '*':
                printf("%f\n", value1 * value2);
                break;
            case '/':
                printf("%f\n", value1 / value2);
                break;
            case '^':
                printf("%f\n", pow(value1, value2));
                break;
            default:
                printf("Unknown operator\n");
                break;
        }

        buffer_init(&buffer, MAX_BUFFER_SIZE);
    }

    buffer_free(&buffer);

    return 0;
}