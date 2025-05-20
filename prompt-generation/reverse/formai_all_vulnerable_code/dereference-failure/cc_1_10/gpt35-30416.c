//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
// Welcome to URL Sanitizer!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Callable function to sanitize a given URL
void sanitizeURL(char *url) {
    int len = strlen(url);
    char *newURL = malloc(len + 1); // Memory allocation for new URL
    int i, j = 0;

    // Copying the given URL to new URL while sanitizing
    for(i = 0; i < len; i++) {
        if(url[i] == '\r' || url[i] == '\n') {
            continue;
        }
        if(url[i] == ' ') {
            newURL[j++] = '+'; // Replace spaces with +
        } else if(isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/'){
            newURL[j++] = url[i];
        } else {
            // Encodes all other characters in URL with % sign
            sprintf(&newURL[j], "%%%02X", (unsigned int) url[i]);
            j += 3;
        }
    }
    newURL[j] = '\0'; // Set end of the new URL

    // Copying the new URL back to the given URL
    for(i = 0; i <= j; i++) {
        url[i] = newURL[i];
    }

    free(newURL); // Free memory allocated for new URL
}

int main() {

    printf("Welcome to URL Sanitizer!\n\n");

    // Sample URL
    char url[] = "https://www.example website.com/path/to/page with spaces.html?name=John&age=25\n";

    printf("Before sanitizing: %s\n", url);

    sanitizeURL(url); // Sanitize the given URL

    printf("After sanitizing: %s\n", url);

    return 0;
}