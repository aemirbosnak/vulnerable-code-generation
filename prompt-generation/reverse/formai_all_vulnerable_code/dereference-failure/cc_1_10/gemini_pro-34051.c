//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    char *sanitized_url = malloc(strlen(url) + 1);
    strcpy(sanitized_url, url);

    // Replace all occurrences of "//" with "/"
    char *pos = sanitized_url;
    while ((pos = strstr(pos, "//")) != NULL) {
        *pos++ = '/';
        *pos++ = '/';
    }

    // Replace all occurrences of "/./" with "/"
    pos = sanitized_url;
    while ((pos = strstr(pos, "/./")) != NULL) {
        *pos++ = '/';
        *pos++ = '/';
    }

    // Replace all occurrences of "/../" with "/"
    pos = sanitized_url;
    while ((pos = strstr(pos, "/../")) != NULL) {
        *pos++ = '/';
        *pos++ = '/';
    }

    // Remove leading and trailing slashes
    if (*sanitized_url == '/') {
        sanitized_url++;
    }
    pos = strlen(sanitized_url) - 1;
    if (*pos == '/') {
        *pos = '\0';
    }

    // Check if the sanitized URL is valid
    regex_t regex;
    int status = regcomp(&regex, "^https://[a-zA-Z0-9.-]+(:[0-9]+)?(/[a-zA-Z0-9.-]+(/([a-zA-Z0-9.-]+)?)?)?$", REG_EXTENDED);
    if (status != 0) {
        regfree(&regex);
        fprintf(stderr, "Error compiling regex: %s\n", strerror(status));
        free(sanitized_url);
        return EXIT_FAILURE;
    }

    status = regexec(&regex, sanitized_url, 0, NULL, 0);
    regfree(&regex);
    if (status != 0) {
        fprintf(stderr, "Invalid sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
        return EXIT_FAILURE;
    }

    // Print the sanitized URL
    printf("%s\n", sanitized_url);

    free(sanitized_url);
    return EXIT_SUCCESS;
}