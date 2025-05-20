//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to determine if a character is allowed in a URL
int is_allowed_char(char c) {
    // Allowed characters in a URI segment as per RFC 3986
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' ||
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || 
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']');
}

// Function to URL-encode a character
void url_encode_char(char c, char *output) {
    sprintf(output, "%%%02X", (unsigned char)c);
}

// Main function to sanitize a URL
void sanitize_url(const char *input_url, char *sanitized_url) {
    // Initialize output URL
    sanitized_url[0] = '\0';

    // Length of the input URL
    size_t len = strlen(input_url);
    char encoded_char[4]; // 3 characters for hex code + null terminator

    // Iterating over each character in the input URL
    for (size_t i = 0; i < len; i++) {
        char c = input_url[i];
        if (is_allowed_char(c)) {
            strncat(sanitized_url, &c, 1); // Append allowed character
        } else {
            url_encode_char(c, encoded_char);
            strcat(sanitized_url, encoded_char); // Append URL-encoded character
        }
    }
}

int main() {
    // Input URL
    const char *input_url = "https://example.com/hello world?name=John & Jane#test";
    char sanitized_url[512]; // Output buffer

    // Perform URL sanitization
    sanitize_url(input_url, sanitized_url);

    // Output sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}