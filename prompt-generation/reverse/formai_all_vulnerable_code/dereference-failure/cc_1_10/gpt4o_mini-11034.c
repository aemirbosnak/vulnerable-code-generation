//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

void mangle(char *raw, char *clean) {
    int j = 0;

    for (int i = 0; raw[i] != '\0'; i++) {
        // Keep only valid characters: alphanumeric + some punctuation
        if (isalnum(raw[i]) || raw[i] == '_' || raw[i] == '-' || raw[i] == '.') {
            clean[j++] = raw[i];
        } else {
            // Replace invalid character with an underscore
            clean[j++] = '_';
        }
    }
    clean[j] = '\0'; // Null-terminate the sanitized string
}

void surrealOutput(char *sanitized) {
    if (strlen(sanitized) == 0) {
        printf("Output: [empty]\n");
    } else {
        printf("Sanitized Output: %s\n", sanitized);
    }
}

int main() {
    char *tickTock = malloc(MAX_INPUT * sizeof(char)); // User input
    char *whisper = malloc(MAX_INPUT * sizeof(char));  // Sanitized output
    
    if (tickTock == NULL || whisper == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE; 
    }

    printf("Whisper your secrets (max %d characters): ", MAX_INPUT - 1);
    fgets(tickTock, MAX_INPUT, stdin);

    // Remove trailing newline if it exists
    size_t len = strlen(tickTock);
    if (len > 0 && tickTock[len - 1] == '\n') {
        tickTock[len - 1] = '\0';
    }

    mangle(tickTock, whisper); // Sanitize input
    surrealOutput(whisper); // Display sanitized output

    free(tickTock); // Clean up
    free(whisper); // Clean up

    return EXIT_SUCCESS;
}