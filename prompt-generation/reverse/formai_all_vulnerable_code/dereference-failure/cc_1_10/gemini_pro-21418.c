//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    if (strlen(url) > MAX_URL_LENGTH) {
        printf("URL is too long\n");
        return EXIT_FAILURE;
    }

    // Remove any whitespace from the URL
    char *new_url = malloc(MAX_URL_LENGTH);
    int new_url_length = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (!isspace(url[i])) {
            new_url[new_url_length++] = url[i];
        }
    }
    new_url[new_url_length] = '\0';

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(new_url, "http://", 7) != 0 && strncmp(new_url, "https://", 8) != 0) {
        printf("URL must start with \"http://\" or \"https://\"\n");
        return EXIT_FAILURE;
    }

    // Remove any characters that are not allowed in a URL
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/";
    for (int i = 0; i < new_url_length; i++) {
        if (strchr(allowed_chars, new_url[i]) == NULL) {
            new_url[i] = '_';
        }
    }

    // Print the sanitized URL
    printf("%s\n", new_url);

    free(new_url);

    return EXIT_SUCCESS;
}