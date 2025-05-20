//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SAFE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

void usage(const char *prog_name) {
    printf("Usage: %s <url>\n", prog_name);
}

int is_safe_char(char c) {
    return (strchr(SAFE_CHARS, c) != NULL);
}

void sanitize_url(const char *url, char *sanitized_url) {
    char *p = sanitized_url;
    while (*url) {
        if (is_safe_char(*url)) {
            *p++ = *url;
        } else {
            p += sprintf(p, "%%%02X", (unsigned char)*url);
        }
        url++;
    }
    *p = '\0'; // Null terminate the sanitized URL string
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];

    if (strlen(input_url) >= MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL too long. Must be less than %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(input_url, sanitized_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}