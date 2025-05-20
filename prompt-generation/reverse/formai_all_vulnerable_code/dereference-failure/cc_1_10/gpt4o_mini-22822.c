//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to determine if a character is valid in a URL.
int is_valid_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' ||
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' ||
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']' || c == '%');
}

// Function to sanitize the URL and encode any invalid characters.
void sanitize_url(const char *input_url, char *output_url) {
    size_t input_length = strlen(input_url);
    size_t index = 0;

    for (size_t i = 0; i < input_length; ++i) {
        char current_char = input_url[i];

        if (is_valid_char(current_char)) {
            output_url[index++] = current_char;  // Valid character, keep it.
        } else {
            // Invalid character, encode it as %XX
            index += snprintf(&output_url[index], MAX_URL_LENGTH - index, "%%%02X", (unsigned char)current_char);
        }
    }

    output_url[index] = '\0';  // Null-terminate the output string.
}

// Utilizes multi-line comment style for documentation.
void print_usage() {
    /* 
    * This function prints the usage instructions.
    * It details how to use the URL sanitizer program.
    */
    printf("Usage: ./url_sanitizer <url>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();  // Print usage if incorrect arguments given.
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    // Sanitize the input URL using the custom function.
    sanitize_url(input_url, sanitized_url);

    // Print out the original and sanitized URLs.
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;  // Indicate successful completion of the program.
}