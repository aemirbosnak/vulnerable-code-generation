//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    char *new_url = malloc(MAX_URL_LENGTH);
    if (!new_url) {
        fprintf(stderr, "Error: Could not allocate memory for new URL (%s).\n", strerror(errno));
        return NULL;
    }

    // Copy the URL to the new buffer, replacing any unsafe characters with their HTML-encoded equivalents.
    int new_url_index = 0;
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];
        switch (c) {
            case '<':
                strcpy(&new_url[new_url_index], "&lt;");
                new_url_index += 4;
                break;
            case '>':
                strcpy(&new_url[new_url_index], "&gt;");
                new_url_index += 4;
                break;
            case '&':
                strcpy(&new_url[new_url_index], "&amp;");
                new_url_index += 5;
                break;
            case '"':
                strcpy(&new_url[new_url_index], "&quot;");
                new_url_index += 6;
                break;
            case '\'':
                strcpy(&new_url[new_url_index], "&#39;");
                new_url_index += 5;
                break;
            default:
                new_url[new_url_index++] = c;
                break;
        }
    }

    new_url[new_url_index] = '\0';

    return new_url;
}

int main() {
    // Get the input URL from the user.
    char url[MAX_URL_LENGTH];
    printf("Enter the URL you want to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL.
    char *sanitized_url = sanitize_url(url);
    if (!sanitized_url) {
        return EXIT_FAILURE;
    }

    // Print the sanitized URL.
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL.
    free(sanitized_url);

    return EXIT_SUCCESS;
}