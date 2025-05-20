//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 4096

// Function to sanitize a URL
void sanitize_url(char* url) {
    int i, j;
    int is_valid_char;

    // Convert to lowercase
    for (i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove leading and trailing spaces
    url[0] = toupper(url[0]);
    url[strlen(url) - 1] = toupper(url[strlen(url) - 1]);

    // Remove any spaces in the middle
    for (i = 1; i < strlen(url) - 1; i++) {
        is_valid_char = 0;
        for (j = 0; j < strlen("abcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="); j++) {
            if (url[i] == url[j]) {
                is_valid_char = 1;
                break;
            }
        }
        if (is_valid_char == 0) {
            url[i] = '%';
            url[i + 1] = '2';
            url[i + 2] = '0';
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}