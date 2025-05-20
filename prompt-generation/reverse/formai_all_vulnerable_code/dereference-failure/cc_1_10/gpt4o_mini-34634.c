//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[\\]@!$&'()*+,;="

void displayHelp() {
    printf("-------------------------------------------------\n");
    printf("  URL Sanitizer Tool (v1.0)                     \n");
    printf("  Author: Code Wizard                             \n");
    printf("-------------------------------------------------\n");
    printf("Usage:\n");
    printf("  ./url_sanitizer <url>\n");
    printf("-------------------------------------------------\n");
}

bool isAllowedCharacter(char c) {
    return strchr(ALLOWED_CHARACTERS, c) != NULL;
}

bool isValidUrl(const char *url) {
    if (strlen(url) == 0 || strlen(url) > MAX_URL_LENGTH) {
        return false;
    }
    
    // Check for a valid scheme
    if (!(strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0)) {
        return false;
    }

    return true;
}

void sanitizeUrl(const char *inputUrl, char *sanitizedUrl) {
    int j = 0;
    int len = strlen(inputUrl);

    for (int i = 0; i < len; i++) {
        char c = inputUrl[i];
        if (isAllowedCharacter(c)) {
            sanitizedUrl[j++] = c;
        } else {
            // Convert to %XX Hex Value
            j += sprintf(sanitizedUrl + j, "%%%02X", (unsigned char)c);
        }
    }
    sanitizedUrl[j] = '\0'; // Null terminate the sanitized URL
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayHelp();
        return EXIT_FAILURE;
    }

    const char *inputUrl = argv[1];
    char sanitizedUrl[MAX_URL_LENGTH];

    printf("Processing URL: %s\n", inputUrl);

    if (!isValidUrl(inputUrl)) {
        fprintf(stderr, "⚠️  Error: Invalid URL!\n");
        return EXIT_FAILURE;
    }

    sanitizeUrl(inputUrl, sanitizedUrl);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    return EXIT_SUCCESS;
}