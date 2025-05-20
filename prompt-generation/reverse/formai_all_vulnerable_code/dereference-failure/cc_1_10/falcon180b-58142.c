//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    char* input;
    char* sanitized_input;
    bool is_sanitized;
} input_t;

void* sanitize_input(void* arg) {
    input_t* input = (input_t*) arg;

    if (!input->is_sanitized) {
        input->sanitized_input = malloc(MAX_INPUT_SIZE);
        if (input->sanitized_input == NULL) {
            fprintf(stderr, "Error: Could not allocate memory for sanitized input.\n");
            exit(1);
        }

        strcpy(input->sanitized_input, input->input);

        for (int i = 0; i < strlen(input->sanitized_input); i++) {
            if (!isalnum(input->sanitized_input[i])) {
                input->sanitized_input[i] = '_';
            }
        }

        input->is_sanitized = true;
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    input_t input;

    printf("Enter some text to sanitize: ");
    fgets(input.input, MAX_INPUT_SIZE, stdin);

    input.is_sanitized = false;

    pthread_create(&thread_id, NULL, sanitize_input, &input);

    pthread_join(thread_id, NULL);

    printf("Sanitized input: %s\n", input.sanitized_input);

    free(input.sanitized_input);

    return 0;
}