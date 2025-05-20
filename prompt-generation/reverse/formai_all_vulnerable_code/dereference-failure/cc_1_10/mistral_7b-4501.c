//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 256

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

bool is_hex(char c) {
    return (isdigit(c) || (isalpha(c) && (tolower(c) >= 'a' && tolower(c) <= 'f')));
}

bool is_valid_hex(char *hex) {
    int len = strlen(hex);
    if (len % 2 != 0) return false;

    for (int i = 0; i < len; i += 2) {
        if (!is_hex(hex[i]) || !is_hex(hex[i+1])) {
            return false;
        }
    }

    return true;
}

void sanitize_url(char *url) {
    int len = strlen(url);
    int i, j;

    // Remove leading whitespaces
    for (i = 0; i < len && isspace(url[i]); i++);

    if (i >= len) {
        printf("Empty URL\n");
        return;
    }

    // Store the start of the URL
    char *start = url + i;

    // Remove trailing whitespaces
    for (len = strlen(url + i); len > 0 && isspace(url[len+i]); len--);

    // Copy the sanitized URL to a new buffer
    char *sanitized_url = malloc(len + 1 + i);
    strncpy(sanitized_url, start, len + 1);

    // Perform the sanitization
    for (i = 0, j = i; j < len + i; i++, j++) {
        if (url[i+i] == '+') {
            sanitized_url[j] = ' ';
            i++;
        } else if (isalnum(url[i+i]) || url[i+i] == '.' || url[i+i] == '/') {
            sanitized_url[j] = url[i+i];
        } else if (url[i+i] == '%' && i+i+1 < len && is_valid_hex(url+i+i+1)) {
            sanitized_url[j] = strtol(url+i+i+1, NULL, 16);
            i += 3;
        } else {
            sanitized_url[j] = '_';
        }
    }

    // Null-terminate the sanitized URL
    sanitized_url[j] = '\0';

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    sanitize_url(argv[1]);

    return 0;
}