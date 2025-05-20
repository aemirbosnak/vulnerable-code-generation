//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_LENGTH 1000

void sanitize(char *input) {
    int i, j;
    char sanitized[MAX_LENGTH];
    char allowed_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";
    sanitized[0] = '\0';

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        input++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    for (i = 0, j = 0; input[i]; i++) {
        if (strchr(allowed_chars, input[i])) {
            sanitized[j++] = tolower(input[i]);
        }
    }
    sanitized[j] = '\0';

    // Replace multiple underscores with single underscore
    char *underscores = strstr(sanitized, "__");
    while (underscores) {
        *underscores = '_';
        underscores = strstr(underscores + 1, "__");
    }

    // Check for valid length
    if (strlen(sanitized) > MAX_LENGTH) {
        printf("Error: Input is too long.\n");
        exit(1);
    }

    // Copy sanitized input to original input
    strcpy(input, sanitized);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter some text to sanitize: ");
    fgets(input, MAX_LENGTH, stdin);
    sanitize(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}