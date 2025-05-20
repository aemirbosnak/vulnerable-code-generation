//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int length;
} URL;

int is_valid_url(const char *url) {
    regex_t regex;
    int ret;

    ret = regcomp(&regex, "^https?://[a-zA-Z0-9.-]*$", REG_EXTENDED);
    if (ret!= 0) {
        fprintf(stderr, "Error: Invalid regular expression.\n");
        exit(1);
    }

    ret = regexec(&regex, url, 0, NULL, 0);
    regfree(&regex);

    return ret == 0;
}

int sanitize_url(URL *url, const char *input) {
    char *sanitized_url = NULL;
    int sanitized_url_length = 0;

    if (strlen(input) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL is too long.\n");
        return 0;
    }

    sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 0;
    }

    sanitized_url_length = 0;
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (isalnum(c) || c == '.' || c == '-') {
            sanitized_url[sanitized_url_length++] = tolower(c);
        } else {
            fprintf(stderr, "Error: Invalid character in URL.\n");
            free(sanitized_url);
            return 0;
        }
    }

    sanitized_url[sanitized_url_length] = '\0';

    if (!is_valid_url(sanitized_url)) {
        fprintf(stderr, "Error: Invalid URL.\n");
        free(sanitized_url);
        return 0;
    }

    free(url->url);
    url->url = sanitized_url;
    url->length = sanitized_url_length;

    return 1;
}

int main() {
    URL url;
    char input[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize:\n");
    fgets(input, MAX_URL_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    url.url = strdup(input);
    url.length = strlen(input);

    if (sanitize_url(&url, input)) {
        printf("Sanitized URL: %s\n", url.url);
    } else {
        printf("Sanitization failed.\n");
    }

    free(url.url);
    return 0;
}