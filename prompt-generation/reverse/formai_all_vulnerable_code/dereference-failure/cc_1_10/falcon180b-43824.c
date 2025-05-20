//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/*
 * Check if a character is a valid URL character.
 * Returns 1 if it is, 0 otherwise.
 */
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '@') {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Check if a string is a valid URL.
 * Returns 1 if it is, 0 otherwise.
 */
int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

/*
 * Sanitize a URL by removing any invalid characters.
 * Returns a pointer to the sanitized URL.
 */
char* sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

/*
 * Example usage of the URL sanitizer.
 */
int main() {
    char* url = "https://example.com/path/to/page?query=string&foo=bar";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}