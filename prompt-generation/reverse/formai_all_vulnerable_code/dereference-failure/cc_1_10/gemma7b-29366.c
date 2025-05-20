//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer) {
    char *ptr = *buffer;
    char *end = ptr + MAX_BUFFER_SIZE;
    char *start = ptr;

    // Normalize input to lowercase and remove non-alphanumeric characters
    while (ptr < end && *ptr) {
        *ptr = tolower(*ptr);
        if (!isalnum(*ptr)) {
            ptr++;
        } else {
            ptr++;
        }
    }

    // Trim trailing whitespace
    while (ptr > start && isspace(*ptr)) {
        ptr--;
    }

    // Reallocate buffer if necessary
    if (start != ptr) {
        *buffer = realloc(*buffer, (ptr - start + 1) * sizeof(char));
    }

    *buffer = ptr - start + 1;
}

int main() {
    char *buffer = NULL;
    size_t buffer_size = 0;
    char input[1024];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    sanitize_user_input(&buffer);

    if (buffer) {
        printf("Sanitized string: %s\n", buffer);
    } else {
        printf("Error sanitizing input.\n");
    }

    return 0;
}