//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url) {
    int i, j;
    char temp;

    // Convert first character to uppercase
    if (isalpha(*url))
        *url = toupper(*url);

    // Iterate through the URL string
    for (i = 0; url[i] != '\0' && i < MAX_URL_LENGTH; i++) {
        // Check if the current character is alphanumeric or a valid symbol
        if (isalnum(url[i]) || (url[i] == '_' || url[i] == '-' || url[i] == '.')) {
            continue;
        }

        // If not, replace it with an empty string
        for (j = i; url[j] != '\0'; j++) {
            temp = url[j];
            url[j] = url[j + 1];
            url[j + 1] = temp;
            i--;
        }

        // Decrement i since we replaced a character
        i--;
    }

    // Convert all subsequent occurrences of the first character to lowercase
    if (isalpha(*url)) {
        for (i = 0; url[i] != '\0' && i < MAX_URL_LENGTH; i++) {
            if (url[i] == *url && isupper(url[i])) {
                url[i] = tolower(url[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char url[MAX_URL_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}