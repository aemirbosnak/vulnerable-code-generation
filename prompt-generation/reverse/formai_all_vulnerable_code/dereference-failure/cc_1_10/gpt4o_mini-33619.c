//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function prototypes
char *sanitize_url(const char *url);
void make_it_funny(char *url);
void swap_specials(char *url);
void print_warning(const char *url);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>...\n", argv[0]);
        printf("Please provide at least one URL to sanitize. Preferably a real one, not a unicorn.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Processing URL: %s\n", argv[i]);

        // Sanitize the provided URL
        char *sanitized_url = sanitize_url(argv[i]);

        // Print warning for funny URLs
        print_warning(sanitized_url);

        // Display sanitized URL
        printf("Sanitized URL: %s\n\n", sanitized_url);

        // Clean-up, because nobody likes mess
        free(sanitized_url);
    }
    
    return 0;
}

char *sanitize_url(const char *url) {
    char *sanitized = (char *)malloc(MAX_URL_LENGTH);
    if (!sanitized) {
        fprintf(stderr, "Memory allocation failed! Looks like the gremlins got us!\n");
        exit(1);
    }

    // Start with a friendly message
    printf("Sanitizing your URL, hold on...\n");

    // Replace unwanted characters with 'happy' ones.
    strcpy(sanitized, url);
    swap_specials(sanitized);
    
    // Let's make it funny.
    make_it_funny(sanitized);
    
    return sanitized;
}

void make_it_funny(char *url) {
    // Poke fun at some common URLs
    if (strstr(url, "google") != NULL) {
        strcat(url, " - Are you searching for the meaning of life?");
    } else if (strstr(url, "facebook") != NULL) {
        strcpy(url, "Oops! You've fallen into the endless scroll!");
    } else if (strstr(url, "twitter") != NULL) {
        strcat(url, " - Follow the chirps, but beware the cat memes!");
    }
}

void swap_specials(char *url) {
    // Let's replace bad characters with good alternatives
    char *ptr = url;

    while (*ptr) {
        if (!isalnum(*ptr) && *ptr != ':' && *ptr != '/' && *ptr != '.' && *ptr != '-') {
            if (*ptr == ' ') {
                *ptr = '_'; // We replace spaces with underscores because spaces are too mainstream.
            } else {
                *ptr = '~'; // Special characters will turn into tilde because why not?
            }
        }
        ptr++;
    }
}

void print_warning(const char *url) {
    // Warn if the URL is suspiciously funny
    if (strstr(url, "unicorn") != NULL) {
        printf("Warning: This URL contains unicorns! Proceed with caution!\n");
    } else if (strstr(url, "404") != NULL) {
        printf("Alert! This URL is probably lost. Just like me on Mondays.\n");
    } else if (strstr(url, "cats") != NULL) {
        printf("Caution: This URL is related to cats! Expect cuteness overload.\n");
    }
}