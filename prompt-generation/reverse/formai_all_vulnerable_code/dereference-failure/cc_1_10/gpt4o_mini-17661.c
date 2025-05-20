//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// A structure to represent a URL, like a tale of two star-crossed lovers
typedef struct URL {
    char original[MAX_URL_LENGTH]; // The original URL, like Juliet's beauty
    char sanitized[MAX_URL_LENGTH]; // The sanitized URL, like Romeo's honor
} URL;

void fatal_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to initialize the URL
void init_url(URL *url, const char *raw_url) {
    strncpy(url->original, raw_url, MAX_URL_LENGTH);
    url->original[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination
    url->sanitized[0] = '\0'; // Start with an empty sanitized URL
}

// Function to sanitize the URL
void sanitize_url(URL *url) {
    char *source = url->original;
    char *dest = url->sanitized;
    
    // The tragic fate of untrusted characters
    while (*source) {
        if (isalnum((unsigned char)*source) || strchr("-_.~:/?#@!$&'()*+,;=", *source)) {
            *dest++ = *source; // Keep the trusted characters
        }
        source++;
    }
    *dest = '\0'; // Null-terminate the sanitized string
}

// Function to print the URL details like a sonnet
void print_url(const URL *url) {
    printf("O! What light through yonder window breaks?\n");
    printf("The original URL: %s\n", url->original);
    printf("The sanitized URL: %s\n", url->sanitized);
    printf("For every tear, a string set free,\n");
}

int main(int argc, char *argv[]) {
    // If the light of input is none, despair shall reign
    if (argc < 2) {
        fatal_error("No URL provided! Enter a URL to be sanitized.");
    }

    URL beloved;
    init_url(&beloved, argv[1]); // Take in the URL as Romeo takes in Juliet's beauty
    sanitize_url(&beloved); // Purify the URL to rid it of impurities
    print_url(&beloved); // Recite the beauty of the sanitized URL

    return EXIT_SUCCESS; // Like a tragic end, the curtain closes
}