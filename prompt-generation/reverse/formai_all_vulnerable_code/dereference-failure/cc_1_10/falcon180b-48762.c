//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

#define MAX_URL_LEN 2048

/*
 * This function checks if a character is a valid URL character
 * according to RFC 3986.
 *
 * Returns: 1 if the character is valid, 0 otherwise.
 */
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == ':' || c == '/' || c == '?' || c == '#' || c == '[' || c == ']' || c == '@' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }

    return 0;
}

/*
 * This function sanitizes a URL by removing any invalid characters.
 *
 * Parameters:
 * - url: the URL to sanitize
 * - sanitized_url: a buffer to store the sanitized URL
 * - sanitized_url_len: the length of the sanitized_url buffer
 *
 * Returns: the length of the sanitized URL, or -1 if the URL is invalid.
 */
int sanitize_url(const char *url, char *sanitized_url, size_t sanitized_url_len) {
    int i = 0;
    char c;

    while ((c = url[i])!= '\0') {
        if (!is_valid_url_char(c)) {
            return -1;
        }

        if (i >= sanitized_url_len - 1) {
            return -1;
        }

        sanitized_url[i] = c;
        i++;
    }

    sanitized_url[i] = '\0';
    return i;
}

/*
 * This function prints an error message to stderr.
 *
 * Parameters:
 * - msg: the error message to print
 */
void error_msg(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        error_msg("Usage:./sanitize_url <URL>");
        return 1;
    }

    char sanitized_url[MAX_URL_LEN];
    int sanitized_url_len = sanitize_url(argv[1], sanitized_url, MAX_URL_LEN);

    if (sanitized_url_len == -1) {
        error_msg("Invalid URL");
        return 1;
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    return 0;
}