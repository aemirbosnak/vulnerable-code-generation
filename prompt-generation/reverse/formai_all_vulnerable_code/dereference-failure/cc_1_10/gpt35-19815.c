//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url) {
    int i, j;
    char temp[strlen(url)];

    // Copy the URL to a temp buffer
    strcpy(temp, url);

    // Check for and remove any leading whitespace
    i = 0;
    while (temp[i] == ' ') {
        i++;
    }
    if (i > 0) {
        strcpy(temp, &temp[i]);
    }

    // Check for and remove any trailing whitespace
    i = strlen(temp) - 1;
    while (temp[i] == ' ') {
        i--;
    }
    temp[i+1] = '\0';

    // Check for and remove any "http://" or "https://" prefixes
    if (strncmp(temp, "http://", 7) == 0) {
        i = 7;
    } else if (strncmp(temp, "https://", 8) == 0) {
        i = 8;
    } else {
        i = 0;
    }
    if (i > 0) {
        strcpy(temp, &temp[i]);
    }

    // Remove any trailing slashes
    i = strlen(temp) - 1;
    while (temp[i] == '/') {
        temp[i] = '\0';
        i--;
    }

    // Remove any unnecessary query strings or fragments
    i = strlen(temp) - 1;
    while (temp[i] != '/' && i >= 0) {
        if (temp[i] == '?' || temp[i] == '#') {
            temp[i] = '\0';
        }
        i--;
    }

    // Copy the sanitized URL back into the original buffer
    strcpy(url, temp);
}

int main() {
    char url[1000];

    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}