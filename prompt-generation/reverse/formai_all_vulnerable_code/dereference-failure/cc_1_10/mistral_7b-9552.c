//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 256

bool is_alphanumeric(char c) {
    return (isalnum((unsigned char)c) != 0);
}

bool is_hexadecimal(char c) {
    return (isxdigit((unsigned char)c) != 0);
}

void sanitize_url(char *url) {
    int len = strlen(url);
    int i, j;

    // Remove leading and trailing whitespaces
    for (i = 0; i < len && isspace((unsigned char)url[i]); i++);
    for (len -= 1; len >= 0 && isspace((unsigned char)url[len]); len--);

    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc((len + 1) * sizeof(char));
    if (sanitized_url == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    i = j = 0;

    // Process the URL character by character
    while (i < len) {
        char c = url[i];

        if (is_alphanumeric(c) || c == '.' || c == '-' || c == '_' || (c >= 0x21 && c <= 0x23) || (c >= 0x25 && c <= 0x27) || (c >= 0x2A && c <= 0x2F) || (c == '~')) {
            sanitized_url[j++] = c;
            i++;
        } else if (c == '%' && i < len - 1 && is_hexadecimal(url[i+1]) && is_hexadecimal(url[i+2])) {
            char hex[3];
            hex[0] = url[i+1];
            hex[1] = url[i+2];
            sanitized_url[j++] = (char)strtol(hex, NULL, 16);
            i += 2;
        } else {
            i++;
        }
    }

    // Null-terminate the sanitized URL
    sanitized_url[j] = '\0';

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the allocated memory
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

// This is a comment, it does not affect the program execution