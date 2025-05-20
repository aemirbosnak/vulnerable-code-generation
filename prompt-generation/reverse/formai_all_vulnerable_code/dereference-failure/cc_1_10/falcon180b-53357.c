//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url);

int main(int argc, char *argv[]) {
    char input_url[MAX_URL_LENGTH];
    char *sanitized_url;

    printf("Enter a URL to sanitize: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    input_url[strcspn(input_url, "\n")] = '\0';

    sanitized_url = sanitize_url(input_url);

    if (sanitized_url!= NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH + 1);
    char *p = sanitized_url;
    int i;

    if (url == NULL) {
        return NULL;
    }

    // Remove leading and trailing whitespace
    while (isspace(*url)) {
        url++;
    }
    i = strlen(url) - 1;
    while (isspace(url[i])) {
        url[i] = '\0';
        i--;
    }

    // Check if the URL is valid
    if (strlen(url) <= 7 || strncmp(url, "http://", 7)!= 0 || strncmp(url, "https://", 8)!= 0) {
        free(sanitized_url);
        return NULL;
    }

    // Copy the URL to the sanitized buffer, replacing invalid characters with % signs
    while (*url) {
        if (isalnum(*url) || *url == '-') {
            *p++ = *url;
        } else {
            *p++ = '%';
            *p++ = hex_digit(*url >> 4);
            *p++ = hex_digit(*url & 0x0f);
        }
        url++;
    }
    *p = '\0';

    return sanitized_url;
}

int hex_digit(int c) {
    if (c >= 0 && c <= 9) {
        return c + '0';
    } else {
        return c + 'A' - 10;
    }
}