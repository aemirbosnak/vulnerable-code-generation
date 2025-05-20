//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to clean URL */
char* clean_url(char* url) {
    int i = 0, j = 0, len = strlen(url);
    char* new_url = malloc(sizeof(len + 1));

    while (i < len) {
        /* Check for protocol in URL */
        if (url[i] == ':') {
            if (url[i+1] == '/') {
                if (url[i+2] == '/') {
                    /* Reset string for new URL */
                    memset(new_url, 0, len + 1);
                    j = 0;
                    i += 3; /* Move i to start of domain */
                } else {
                    /* Invalid protocol for URL */
                    return "Invalid URL";
                }
            } else {
                /* Invalid protocol for URL */
                return "Invalid URL";
            }
        }

        /* Remove extra slashes */
        if (url[i] == '/' && url[i+1] == '/') {
            i++;
        }

        new_url[j] = url[i];
        i++;
        j++;
    }

    /* Check if URL ends with a slash */
    if (new_url[j-1] == '/') {
        new_url[j-1] = '\0';
    }

    return new_url;
}

int main() {
    /* Input URL */
    char url[] = "http://www.google.com//search?q=example//";

    /* Clean URL */
    char* cleaned_url = clean_url(url);

    /* Output cleaned URL */
    printf("Cleaned URL: %s", cleaned_url);

    return 0;
}