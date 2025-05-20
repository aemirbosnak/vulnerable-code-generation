//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 4096

// Function prototypes
void sanitize_url(const char *url, char *sanitized_url);
int is_valid_character(char c);
void print_usage();

int main(int argc, char *argv[]) {
    // Check if URL is provided.
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char sanitized_url[SANITIZED_URL_LENGTH];
    sanitize_url(argv[1], sanitized_url);
    
    printf("Original URL: %s\n", argv[1]);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}

// Function to sanitize the input URL.
void sanitize_url(const char *url, char *sanitized_url) {
    char *ptr = sanitized_url;
    const char *url_end = url + strlen(url);
    
    while (url < url_end) {
        char current_char = *url;
        
        // Check if the current character is valid
        if (is_valid_character(current_char)) {
            *ptr++ = current_char; // Copy valid character to sanitized URL
        } else {
            // If not valid and within certain characters, encode or skip
            if (current_char == ' ') {
                *ptr++ = '%';
                *ptr++ = '2';
                *ptr++ = '0'; // Encode space as %20
            } else {
                *ptr++ = '%'; // Begin percent-encoding
                sprintf(ptr, "%02X", (unsigned char)current_char); // Encode non-allowed characters
                ptr += 2; // Move pointer forward by 2 for the encoded hex value
            }
        }
        url++;
    }
    *ptr = '\0'; // Null-terminate the sanitized URL
}

// Function to determine if a character is valid in a URL
int is_valid_character(char c) {
    // Allow alphanumeric characters and a few select symbols
    return isalnum(c) || strchr("-_.~", c) != NULL;
}

// Function to print the program usage
void print_usage() {
    fprintf(stderr, "Usage: url-sanitizer <URL>\n");
    fprintf(stderr, "Sanitize a URL by removing illegal characters and encoding spaces.\n");
}