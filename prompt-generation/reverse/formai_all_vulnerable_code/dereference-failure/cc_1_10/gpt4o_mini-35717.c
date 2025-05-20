//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ENCODED_MAX_LENGTH (3 * MAX_URL_LENGTH)

char *url_encode(const char *url) {
    char *encoded = malloc(ENCODED_MAX_LENGTH);
    char *pstr = encoded;

    for (; *url; url++) {
        if (isalnum((unsigned char)*url) || strchr("-_.~", *url)) {
            *pstr++ = *url;
        } else {
            pstr += sprintf(pstr, "%%%02X", (unsigned char)*url);
        }
    }
    *pstr = '\0';
    return encoded;
}

int is_valid_scheme(const char *url) {
    const char *valid_schemes[] = {"http", "https", "ftp", "mailto", NULL};
    const char *scheme = strtok(strdup(url), ":");
    
    for (int i = 0; valid_schemes[i]; i++) {
        if (strcmp(valid_schemes[i], scheme) == 0) {
            return 1;
        }
    }
    return 0;
}

int has_invalid_characters(const char *url) {
    while (*url) {
        if (!(isalnum((unsigned char)*url) || strchr(":/?#[]@!$&'()*+,;=", *url))) {
            return 1;
        }
        url++;
    }
    return 0;
}

void sanitize_url(const char *url, char *sanitized_url) {
    if (!url || strlen(url) == 0) {
        strcpy(sanitized_url, "Invalid URL: empty or NULL");
        return;
    }

    if (has_invalid_characters(url)) {
        strcpy(sanitized_url, "Invalid URL: contains invalid characters");
        return;
    }
    
    if (!is_valid_scheme(url)) {
        strcpy(sanitized_url, "Invalid URL: unsupported scheme");
        return;
    }

    char *encoded = url_encode(url);
    snprintf(sanitized_url, MAX_URL_LENGTH, "Sanitized URL: %s", encoded);
    free(encoded);
}

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    if (fgets(url, sizeof(url), stdin) == NULL) {
        fprintf(stderr, "Failed to read URL\n");
        return EXIT_FAILURE;
    }

    // Remove trailing newline character
    url[strcspn(url, "\n")] = 0;

    sanitize_url(url, sanitized_url);
    printf("%s\n", sanitized_url);

    return EXIT_SUCCESS;
}