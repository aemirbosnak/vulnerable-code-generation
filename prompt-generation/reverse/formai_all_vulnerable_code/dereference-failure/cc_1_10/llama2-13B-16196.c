//LLAMA2-13B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAFE_MAX_INPUT_LENGTH 1024
#define SAFE_MIN_INPUT_LENGTH 1

// Safe version of gets()
char *safe_gets(char *buffer, int max_length) {
    int i, j;
    char c;

    // Check if the input length is valid
    if (max_length < SAFE_MIN_INPUT_LENGTH || max_length > SAFE_MAX_INPUT_LENGTH) {
        printf("Invalid input length! Please enter a value between %d and %d.\n", SAFE_MIN_INPUT_LENGTH, SAFE_MAX_INPUT_LENGTH);
        return NULL;
    }

    // Initialize the buffer with a null terminator
    buffer[0] = '\0';

    // Read input from the user
    for (i = 0; i < max_length; i++) {
        c = getchar();

        // Check if the user pressed enter
        if (c == '\n') {
            break;
        }

        // Append the character to the buffer
        buffer[i] = c;
    }

    // Check if the user pressed enter
    if (c == '\n') {
        buffer[i] = '\0';
    }

    return buffer;
}

int main() {
    char *name;

    // Get the user's name using safe_gets()
    name = safe_gets(NULL, SAFE_MAX_INPUT_LENGTH);

    // Print the user's name
    if (name != NULL) {
        printf("Your name is: %s\n", name);
    } else {
        printf("Invalid name! Please enter a value between %d and %d characters long.\n", SAFE_MIN_INPUT_LENGTH, SAFE_MAX_INPUT_LENGTH);
    }

    return 0;
}