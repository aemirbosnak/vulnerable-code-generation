//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Function to check if a character is safe for a URL
int is_safe_for_url(char c) {
    return isalpha(c) || isdigit(c) || c == '.' || c == '_' || c == '-' || c == '~';
}

// Function to sanitize a URL
char *sanitize_url(const char *url) {
    size_t url_length = strlen(url);
    char *sanitized_url = (char *)malloc(url_length + 1);

    for (size_t i = 0; i < url_length; i++) {
        char c = url[i];
        if (is_safe_for_url(c)) {
            sanitized_url[i] = c;
        } else {
            sanitized_url[i] = '%';
            sprintf(sanitized_url + i + 1, "%02X", (unsigned char)c);
            i += 2;
        }
    }

    sanitized_url[url_length] = '\0';
    return sanitized_url;
}

// Function to print a surprise message
void print_surprise() {
    printf("Surprise! I sanitized your URL for you! :)\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    char *sanitized_url = sanitize_url(url);
    print_surprise();
    printf("%s\n", sanitized_url);

    free(sanitized_url);
    return EXIT_SUCCESS;
}