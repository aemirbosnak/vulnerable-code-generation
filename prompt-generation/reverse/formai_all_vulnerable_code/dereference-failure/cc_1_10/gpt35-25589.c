//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url) {
    // Remove whitespace characters from the beginning and end of the URL
    while (*url == ' ') {
        url++;
    }
    int len = strlen(url);
    while (len > 0 && url[len - 1] == ' ') {
        url[--len] = '\0';
    }

    // Remove the "http://" or "https://" prefix (if present)
    char *prefix = "http://";
    if (strstr(url, prefix) == url) {
        url += strlen(prefix);
    } else {
        prefix = "https://";
        if (strstr(url, prefix) == url) {
            url += strlen(prefix);
        }
    }

    // Remove consecutive slashes
    char *prev = NULL;
    char *curr = url;
    while (*curr != '\0') {
        if (prev != NULL && *prev == '/' && *curr == '/') {
            // Skip this character (effectively removing the second slash)
            curr++;
        } else {
            // Move to the next character
            if (prev != curr) {
                *prev = *curr;
            }
            prev = curr;
            curr++;
        }
    }
    if (prev != NULL && *prev == '/') {
        // Remove trailing slash
        *prev = '\0';
    }
}

int main() {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}