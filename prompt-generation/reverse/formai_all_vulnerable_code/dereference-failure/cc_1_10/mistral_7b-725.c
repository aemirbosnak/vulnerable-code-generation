//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void sanitize_url(char *url) {
    int i, j;
    char safe[MAX_LEN];

    // Initialize safe buffer with slash and null terminator
    safe[0] = '/';
    safe[1] = '\0';

    // Iterate through URL, copying safe characters to safe buffer
    for (i = 0; url[i] && i < MAX_LEN; i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == '~') {
            safe[i + 1] = url[i];
        }

        // If we've reached the end of safe buffer, add a null terminator and continue
        if (safe[i + 1] == '\0') {
            safe[i++] = '\0';
            break;
        }
    }

    // Copy sanitized URL to output buffer
    strcpy(url, safe);

    // Append query string if present
    size_t query_pos = strchr(url, '?') - url;
    if (query_pos) {
        char query[MAX_LEN];
        strncpy(query, url + query_pos, sizeof(query) - 1);
        query[sizeof(query) - 1] = '\0';

        char query_safe[MAX_LEN];
        memset(query_safe, 0, sizeof(query_safe));

        for (i = 0; query[i] && i < MAX_LEN; i++) {
            if (isalnum(query[i]) || query[i] == '.' || query[i] == '&' || query[i] == '=' || query[i] == '+' || query[i] == '-' || query[i] == '_') {
                query_safe[i] = query[i];
            }
        }

        // Copy sanitized query string to output URL
        strncat(url, query_safe, sizeof(url) - strlen(url) - query_pos);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_LEN];
    strcpy(url, argv[1]);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}