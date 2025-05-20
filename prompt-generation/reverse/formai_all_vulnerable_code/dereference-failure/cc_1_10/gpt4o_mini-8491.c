//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 4096

// Function prototypes
void display_intro();
void sanitize_url(const char *url, char *sanitized_url);
int is_valid_char(char c);
void print_usage();

// Main function
int main(int argc, char *argv[]) {
    char sanitized_url[SANITIZED_URL_LENGTH];
    
    display_intro();

    // Check if the user provided a URL
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Sanitize the input URL
    sanitize_url(argv[1], sanitized_url);

    // Display the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}

// Function to sanitize the input URL
void sanitize_url(const char *url, char *sanitized_url) {
    int i, j = 0;
    size_t url_length = strlen(url);
    
    for (i = 0; i < url_length && j < SANITIZED_URL_LENGTH - 1; i++) {
        char current_char = url[i];
        
        if (is_valid_char(current_char)) {
            sanitized_url[j++] = current_char;  // Copy valid characters
        } else {
            // Replace invalid characters with their encoded hex or deny
            j += snprintf(sanitized_url + j, SANITIZED_URL_LENGTH - j, "%%%02X", (unsigned char)current_char);
        }
    }

    sanitized_url[j] = '\0';  // Null-terminate the sanitized string
}

// Function to check if a character is valid in a URL context
int is_valid_char(char c) {
    // Allow alphanumeric characters, special characters and a few reserved ones
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' ||
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' ||
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' ||
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' ||
            c == '#' || c == '[' || c == ']');
}

// Function to display the program introductory message
void display_intro() {
    printf("====================================\n");
    printf("|  CyberPunk URL Sanitizer v1.0   |\n");
    printf("|  Author: Neon Coder              |\n");
    printf("|  Feed your URL to sanitize.      |\n");
    printf("====================================\n");
}

// Function to print usage instructions
void print_usage() {
    printf("Usage: ./url_sanitizer <URL>\n");
    printf("Example: ./url_sanitizer \"http://example.com/test?name=<John>\"\n");
    printf("This tool removes or encodes invalid characters from the given URL.\n");
}