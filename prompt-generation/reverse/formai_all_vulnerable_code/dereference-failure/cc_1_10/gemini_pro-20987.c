//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int type; // 0 = string, 1 = number
    char *value;
} input_t;

pthread_t threads[10];
input_t inputs[10];
int num_inputs = 0;

void *sanitize_input(void *arg) {
    input_t *input = (input_t *)arg;

    if (input->type == 0) {
        // Sanitize string input
        for (int i = 0; i < strlen(input->value); i++) {
            if (!isalnum(input->value[i]) && input->value[i] != ' ') {
                input->value[i] = '\0';
                break;
            }
        }
    } else if (input->type == 1) {
        // Sanitize number input
        for (int i = 0; i < strlen(input->value); i++) {
            if (!isdigit(input->value[i])) {
                input->value[i] = '\0';
                break;
            }
        }
    }

    return NULL;
}

int main() {
    // Create input threads
    for (int i = 0; i < 10; i++) {
        inputs[i].type = rand() % 2;
        inputs[i].value = (char *)malloc(1024);
        sprintf(inputs[i].value, "Input %d", i);
        pthread_create(&threads[i], NULL, sanitize_input, &inputs[i]);
    }

    // Join input threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sanitized inputs
    for (int i = 0; i < 10; i++) {
        printf("Sanitized input %d: %s\n", i, inputs[i].value);
    }

    return 0;
}