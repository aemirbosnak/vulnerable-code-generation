//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%"

bool is_valid_char(char ch) {
    return strchr(ALLOWED_CHARS, ch) != NULL;
}

void encode_char(char ch, char *output, int *pos) {
    sprintf(output + *pos, "%%%02X", (unsigned char)ch);
    *pos += 3; // Because we're adding three characters for each encoded character
}

void sanitize_url(const char *url, char *sanitized_url) {
    int pos = 0;
    for (int i = 0; url[i] != '\0'; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[pos++] = url[i];
        } else {
            encode_char(url[i], sanitized_url, &pos);
        }
    }
    sanitized_url[pos] = '\0'; // Null-terminate the sanitized URL
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <URL to sanitize>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    
    if (strlen(url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LENGTH * 3]; // Allocate more space to handle potential encoding

    sanitize_url(url, sanitized_url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}