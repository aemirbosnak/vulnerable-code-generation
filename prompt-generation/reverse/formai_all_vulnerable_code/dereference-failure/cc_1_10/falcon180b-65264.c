//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

void sanitize_input(char* input) {
    int i, j;
    char buffer[MAX_INPUT_LENGTH];

    // Remove leading and trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    strcpy(buffer, input);
    for (i = 0; buffer[i]!= '\0'; i++) {
        if (!isalnum(buffer[i])) {
            buffer[i] = '\0';
        }
    }

    // Remove consecutive whitespace
    for (i = 0, j = 0; buffer[i]!= '\0'; i++) {
        if (!isspace(buffer[i])) {
            input[j++] = buffer[i];
        }
    }
    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}