//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char *url) {
    // Remove any leading or trailing white spaces
    char *ptr = url;
    while (isspace(*ptr)) {
        ptr++;
    }
    int len = strlen(ptr);
    while (isspace(ptr[len-1])) {
        len--;
        ptr[len] = '\0';
    }

    // Remove any illegal characters
    char *illegal_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?/\\";
    for (int i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i]) && strchr(illegal_chars, url[i]) == NULL) {
            memmove(ptr + i, ptr + i + 1, strlen(ptr) - i - 1);
        }
    }

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }
}

int main() {
    // Prompt the user to enter a URL
    printf("Enter a URL: ");
    char input[MAX_URL_LENGTH];
    fgets(input, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(input);
    strcpy(sanitized_url, input);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}