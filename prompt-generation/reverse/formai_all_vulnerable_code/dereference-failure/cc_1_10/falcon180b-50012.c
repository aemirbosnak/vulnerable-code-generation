//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

/* Function to sanitize a URL */
char* sanitize_url(const char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (url[k]!= '\0') {
        if (isalpha(url[k]) || isdigit(url[k]) || url[k] == '-') {
            sanitized_url[j] = tolower(url[k]);
            j++;
        }
        k++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

/* Function to check if a URL is valid */
int is_valid_url(const char* url) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (url[k]!= '\0') {
        if (isalpha(url[k]) || isdigit(url[k]) || url[k] == '-') {
            k++;
        } else if (url[k] == '.') {
            k++;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* url = malloc(MAX_URL_LENGTH * sizeof(char));
    if (url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);
    char* sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL.\n");
    }
    free(url);
    free(sanitized_url);
    return 0;
}