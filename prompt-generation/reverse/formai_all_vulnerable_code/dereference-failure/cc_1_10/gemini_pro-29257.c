//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Paranoid macros
#define PARANOID_MALLOC(ptr, size) do { ptr = malloc(size); if (ptr == NULL) { fprintf(stderr, "FATAL: Out of memory!\n"); exit(EXIT_FAILURE); } } while (0)
#define PARANOID_FREE(ptr) do { if (ptr != NULL) { free(ptr); ptr = NULL; } } while (0)
#define PARANOID_STRDUP(ptr, str) do { ptr = strdup(str); if (ptr == NULL) { fprintf(stderr, "FATAL: Out of memory!\n"); exit(EXIT_FAILURE); } } while (0)

// Spam detection functions
int is_spam(char *str) {
    // Check for common spam keywords
    char *keywords[] = {"free", "money", "click", "offer", "win"};
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        if (strstr(str, keywords[i])) {
            return 1;
        }
    }

    // Check for excessive punctuation
    int punctuation_count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i])) {
            punctuation_count++;
        }
    }
    if (punctuation_count > strlen(str) / 10) {
        return 1;
    }

    // Check for suspicious links
    char *links[] = {"http://", "https://", "www."};
    for (int i = 0; i < sizeof(links) / sizeof(char *); i++) {
        if (strstr(str, links[i])) {
            return 1;
        }
    }

    // Check for suspicious sender addresses
    char *sender_addresses[] = {"@gmail.com", "@yahoo.com", "@hotmail.com"};
    for (int i = 0; i < sizeof(sender_addresses) / sizeof(char *); i++) {
        if (strstr(str, sender_addresses[i])) {
            return 1;
        }
    }

    // If no suspicious features are found, return 0
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Paranoid initialization
    srand(time(NULL));

    // Check if we were given a string to check
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if the given string is valid
    int len = strlen(argv[1]);
    if (len < 1 || len > 255) {
        fprintf(stderr, "ERROR: Invalid string length!\n");
        exit(EXIT_FAILURE);
    }

    // Paranoid string duplication
    char *str = NULL;
    PARANOID_STRDUP(str, argv[1]);

    // Check if the string is spam
    int is_spam_result = is_spam(str);

    // Paranoid cleanup
    PARANOID_FREE(str);

    // Print the result
    if (is_spam_result) {
        printf("The string is likely spam.\n");
    } else {
        printf("The string is not likely spam.\n");
    }

    return EXIT_SUCCESS;
}