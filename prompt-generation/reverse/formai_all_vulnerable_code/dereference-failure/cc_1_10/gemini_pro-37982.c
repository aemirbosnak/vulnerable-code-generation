//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
/*
 * A C program to sanitize URLs.
 *
 * The program takes a URL as input and checks if it is valid. If the URL is valid, the program prints a sanitized version of the URL. Otherwise, the program prints an error message.
 *
 * The program uses the following regular expression to check if a URL is valid:
 *
 * ^((https?|ftp)://)?(www\.)?[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,6}(:[0-9]+)?(/?([a-zA-Z0-9\-\._\?\,\'\/\\\+&amp;%\$#\=~])*)$
 *
 * The program uses the following regular expression to sanitize a URL:
 *
 * ^((https?|ftp)://)?(www\.)?[a-zA-Z0-9\-\._~:\/?#[\]@!$&'()*+,;=]*$
 *
 * The program uses the following functions to check if a URL is valid and to sanitize a URL:
 *
 * - `is_valid_url()`: This function checks if a URL is valid. The function returns `1` if the URL is valid, and `0` otherwise.
 * - `sanitize_url()`: This function sanitizes a URL. The function returns a sanitized version of the URL.
 *
 * The program uses the following headers:
 *
 * - `<stdio.h>`: This header contains the `printf()` and `scanf()` functions.
 * - `<stdlib.h>`: This header contains the `malloc()` and `free()` functions.
 * - `<string.h>`: This header contains the `strlen()` and `strcpy()` functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function to check if a URL is valid.
 *
 * The function takes a URL as input and checks if it is valid. The function returns `1` if the URL is valid, and `0` otherwise.
 *
 * The function uses the following regular expression to check if a URL is valid:
 *
 * ^((https?|ftp)://)?(www\.)?[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,6}(:[0-9]+)?(/?([a-zA-Z0-9\-\._\?\,\'\/\\\+&amp;%\$#\=~])*)$
 */
int is_valid_url(char *url) {
    char *regex = "^((https?|ftp)://)?(www\\.)?[a-zA-Z0-9\\-\\.]+\\.[a-zA-Z]{2,6}(:[0-9]+)?(/?([a-zA-Z0-9\\-\\._\\?\,\'\/\\\\\\+&amp;%\\$#\\=~])*)$";
    int result = regexec(regex, url, 0, NULL, 0);
    return result == 0;
}

/*
 * Function to sanitize a URL.
 *
 * The function takes a URL as input and sanitizes it. The function returns a sanitized version of the URL.
 *
 * The function uses the following regular expression to sanitize a URL:
 *
 * ^((https?|ftp)://)?(www\.)?[a-zA-Z0-9\-\._~:\/?#[\]@!$&'()*+,;=]*$
 */
char *sanitize_url(char *url) {
    char *regex = "^((https?|ftp)://)?(www\\.)?[a-zA-Z0-9\\-\\._~:\\/?#[\\]@!$&'()*+,;=]*$";
    char *sanitized_url = malloc(strlen(url) + 1);
    int result = regexec(regex, url, 0, NULL, 0);
    if (result == 0) {
        strcpy(sanitized_url, url);
    } else {
        strcpy(sanitized_url, "");
    }
    return sanitized_url;
}

/*
 * Main function.
 */
int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("The URL is valid.\n");
        printf("The sanitized URL is: %s\n", sanitize_url(url));
    } else {
        printf("The URL is invalid.\n");
    }
    return 0;
}