//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

// Converts a given character to its hexadecimal equivalent
char* to_hex(char c) {
    static char hex[] = "0123456789ABCDEF";
    char* result = (char*) malloc(sizeof(char) * 3);
    result[0] = '%';
    result[1] = hex[(c >> 4) & 0xF];
    result[2] = hex[c & 0xF];
    return result;
}

// Replaces a given character with its hexadecimal equivalent
char* sanitize_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~') {
        char* result = (char*) malloc(sizeof(char) * 2);
        result[0] = c;
        result[1] = '\0';
        return result;
    }
    else {
        return to_hex(c);
    }
}

// Sanitizes a given URL
void sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
    int i = 0, j = 0;
    while (url[i]) {
        char* sanitized_char = sanitize_char(url[i]);
        strcpy(&sanitized_url[j], sanitized_char);
        j += strlen(sanitized_char);
        free(sanitized_char);
        i++;
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    // Remove new line character
    url[strlen(url) - 1] = '\0';
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}