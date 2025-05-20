//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    char *input;
    size_t length;
} input_t;

void sanitize(input_t *input) {
    char *p = input->input;
    size_t length = input->length;
    
    for (size_t i = 0; i < length; i++) {
        if (!isascii(p[i]) ||!isprint(p[i])) {
            p[i] = '\0';
        }
    }
    
    input->input = p;
    input->length = strlen(p);
}

input_t get_input() {
    input_t input = {0};
    
    printf("Enter some text: ");
    fgets(input.input, MAX_INPUT_SIZE, stdin);
    input.length = strlen(input.input);
    
    sanitize(&input);
    
    return input;
}

void print_sanitized_input(input_t input) {
    printf("Sanitized input: %s\n", input.input);
}

int main() {
    input_t input = get_input();
    print_sanitized_input(input);
    
    free(input.input);
    
    return 0;
}