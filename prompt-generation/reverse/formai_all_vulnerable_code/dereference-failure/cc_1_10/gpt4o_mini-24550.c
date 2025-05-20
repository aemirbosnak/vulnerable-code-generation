//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function prototypes
void sanitize_url(const char *input, char *output);
int is_valid_character(char c);
void urlencode(const char *input, char *output);
int is_hex_digit(char c);
void decode_url(const char *input, char *output);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    // Check for valid argument count
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(argv[1], sanitized_url);
    
    // Display the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return EXIT_SUCCESS;
}

void print_usage(const char *program_name) {
    printf("Usage: %s <url>\n", program_name);
    printf("Sanitizes the input URL and prints the result.\n");
}

void sanitize_url(const char *input, char *output) {
    if (strlen(input) >= MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL length exceeds maximum limit of %d characters.\n", MAX_URL_LENGTH);
        exit(EXIT_FAILURE);
    }

    // Decode the URL first to handle encoded characters
    char decoded_url[MAX_URL_LENGTH];
    decode_url(input, decoded_url);
    
    // Now sanitize the decoded URL
    urlencode(decoded_url, output);
}

int is_valid_character(char c) {
    // Define valid characters according to RFC 3986
    return isalnum(c) ||
           c == '-' || c == '_' || c == '.' || c == '~' ||
           c == '!' || c == '*' || c == '\'' || c == '(' ||
           c == ')' || c == ';' || c == ':' || c == '@' ||
           c == '&' || c == '=' || c == '+' || c == '$' ||
           c == ',' || c == '/' || c == '?' || c == '#' ||
           c == '[' || c == ']';
}

void urlencode(const char *input, char *output) {
    char *p_output = output;

    while (*input) {
        if (is_valid_character(*input)) {
            *p_output++ = *input;
        } else {
            // Convert invalid characters to percent-encoded format
            sprintf(p_output, "%%%02X", (unsigned char)*input);
            p_output += 3; // Move past the 3 characters added
        }
        input++;
    }
    *p_output = '\0'; // Null-terminate the output string
}

void decode_url(const char *input, char *output) {
    char *p_output = output;
    const char *p_input = input;

    while (*p_input) {
        if (*p_input == '%') {
            // Get the next two characters and convert to the corresponding byte
            if (is_hex_digit(*(p_input + 1)) && is_hex_digit(*(p_input + 2))) {
                char hex[3] = { *(p_input + 1), *(p_input + 2), '\0' };
                *p_output++ = (char)strtol(hex, NULL, 16);
                p_input += 3; // Move past the percent and two hex digits
            } else {
                // Invalid percent encoding, leave the '%' and move on
                *p_output++ = *p_input++;
            }
        } else {
            *p_output++ = *p_input++;
        }
    }
    *p_output = '\0'; // Null-terminate the output string
}

int is_hex_digit(char c) {
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}