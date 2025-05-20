//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/**
 * Function to remove any non-alphanumeric characters from a string
 *
 * @param str The string to sanitize
 * @param length The length of the string
 * @return The sanitized string
 */
char* sanitize_url(char* str, int length) {
    char* sanitized_str = (char*) malloc(length + 1);
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            sanitized_str[j++] = str[i];
        }
    }

    sanitized_str[j] = '\0';
    return sanitized_str;
}

/**
 * Function to check if a string is a valid URL
 *
 * @param str The string to check
 * @return 1 if the string is a valid URL, 0 otherwise
 */
int is_valid_url(char* str) {
    int length = strlen(str);

    // Check if the string starts with "http://" or "https://"
    if (strncmp(str, "http://", 7)!= 0 && strncmp(str, "https://", 8)!= 0) {
        return 0;
    }

    // Check if the string contains any non-alphanumeric characters
    char* sanitized_str = sanitize_url(str, length);
    if (strcmp(sanitized_str, str)!= 0) {
        free(sanitized_str);
        return 0;
    }

    free(sanitized_str);
    return 1;
}

int main() {
    char* url = "https://example.com/path?query=string#fragment";

    if (is_valid_url(url)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}