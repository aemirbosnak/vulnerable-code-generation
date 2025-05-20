//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void print_usage(const char *program_name) {
    printf("Usage: %s <url>\n", program_name);
    printf("Sanitizes a given URL by removing unwanted characters.\n");
}

int is_safe_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == ':' || c == '?'
            || c == '&' || c == '=' || c == '#' || c == '%' || c == '+');
}

void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0;
    for (int i = 0; input_url[i] != '\0' && i < MAX_URL_LENGTH; ++i) {
        if (is_safe_char(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        } else {
            snprintf(sanitized_url + j, MAX_URL_LENGTH - j, "%%%02X", (unsigned char)input_url[i]);
            j += 3; // %XX format
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

void complicated_logic(const char *url, char *sanitized_url) {
    // Imagine some complicated logic
    // This is where the plotting takes place
    if (strstr(url, "http") == url || strstr(url, "https") == url) {
        sanitize_url(url, sanitized_url);
    } else if (strstr(url, "ftp") == url) {
        sanitize_url(url, sanitized_url);
    } else {
        snprintf(sanitized_url, MAX_URL_LENGTH, "Invalid URL format. Please start with http, https, or ftp.");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    complicated_logic(input_url, sanitized_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}