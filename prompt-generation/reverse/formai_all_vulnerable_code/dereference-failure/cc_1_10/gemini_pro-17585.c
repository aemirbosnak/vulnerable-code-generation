//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    if (strlen(url) > MAX_URL_LENGTH) {
        printf("Error: URL is too long (%d characters, maximum allowed is %d).\n", strlen(url), MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    // Compile the regular expression.
    regex_t regex;
    int err = regcomp(&regex, "^(https?://)?(www\\.)?([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,6}(/.*)?$", REG_EXTENDED);
    if (err != 0) {
        char error_message[1024];
        regerror(err, &regex, error_message, sizeof(error_message));
        printf("Error: Failed to compile regular expression: %s\n", error_message);
        return EXIT_FAILURE;
    }

    // Match the URL against the regular expression.
    int matches = 0;
    err = regexec(&regex, url, 0, NULL, 0);
    if (err == 0) {
        matches = 1;
    } else if (err == REG_NOMATCH) {
        matches = 0;
    } else {
        char error_message[1024];
        regerror(err, &regex, error_message, sizeof(error_message));
        printf("Error: Failed to match URL against regular expression: %s\n", error_message);
        return EXIT_FAILURE;
    }

    // Free the compiled regular expression.
    regfree(&regex);

    if (matches) {
        printf("The URL '%s' is valid.\n", url);
    } else {
        printf("The URL '%s' is invalid.\n", url);
    }

    return EXIT_SUCCESS;
}