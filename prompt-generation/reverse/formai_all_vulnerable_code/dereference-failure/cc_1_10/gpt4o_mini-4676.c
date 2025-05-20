//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_SYMBOLS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    return strchr(ALLOWED_SYMBOLS, c) != NULL;
}

// Function to sanitize the URL by encoding invalid characters
void sanitize_url(const char *url, char *sanitized_url) {
    char *p = sanitized_url;
    const char *q = url;

    while (*q) {
        if (is_valid_url_char(*q)) {
            *p++ = *q;  // Copy valid character
        } else {
            // Encode invalid character
            p += sprintf(p, "%%%02X", *q);
        }
        q++;
    }
    *p = '\0';  // Null-terminate sanitized URL
}

// Function to trim leading and trailing whitespace
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';
}

// Main function
int main() {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize (max %d characters):\n", MAX_URL_LENGTH - 1);
    fgets(input_url, sizeof(input_url), stdin);

    // Remove the trailing newline character, if present
    size_t len = strlen(input_url);
    if (len > 0 && input_url[len - 1] == '\n') {
        input_url[len - 1] = '\0';
    }

    // Trim whitespace from the input URL
    trim_whitespace(input_url);

    if (strlen(input_url) == 0) {
        printf("No URL entered. Exiting...\n");
        return 1;
    }

    // Sanitize the input URL
    sanitize_url(input_url, sanitized_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}