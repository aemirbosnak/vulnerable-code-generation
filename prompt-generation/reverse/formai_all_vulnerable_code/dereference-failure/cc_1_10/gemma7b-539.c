//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char *sanitize_user_input(char *input)
{
    char *sanitized_input = malloc(MAX_BUFFER_SIZE);
    memset(sanitized_input, 0, MAX_BUFFER_SIZE);

    // Remove all leading and trailing whitespace
    char *start = input;
    char *end = input + strlen(input) - 1;
    while (start < end && isspace(*start)) {
        start++;
    }
    while (start < end && isspace(*end)) {
        end--;
    }

    // Convert all uppercase letters to lowercase
    for (char *p = start; p <= end; p++) {
        if (isupper(*p)) {
            *p = tolower(*p);
        }
    }

    // Remove all special characters
    char blacklist[] = {"!@#$%^&*()"};
    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if (sanitized_input[i] && strchr(blacklist, sanitized_input[i]) != NULL) {
            sanitized_input[i] = 0;
        }
    }

    // Return the sanitized input
    return sanitized_input;
}

int main()
{
    char input[MAX_BUFFER_SIZE];
    printf("Enter your input: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    char *sanitized_input = sanitize_user_input(input);

    printf("Sanitized input: %s", sanitized_input);

    free(sanitized_input);

    return 0;
}