//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program sanitizes a URL by removing any malicious or unnecessary characters that could lead to security
 * vulnerabilities. The sanitized URL will only contain allowed characters: alphanumeric, forward slash, colon, dot, hyphen,
 * underscore and percent sign.
 */

// Define allowed characters in a URL
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/:.-_%"

// Function to check if a character is allowed in a URL
int is_allowed(char c) {
    char allowed[65] = ALLOWED_CHARS; // cast allowed characters to a string
    return (strchr(allowed, c) != NULL);
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1); // allocate memory for sanitized URL
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_allowed(url[i])) { // if character is allowed
            sanitized_url[j++] = url[i]; // add it to the sanitized URL
        }
        else if (url[i] == ' ') { // if character is a space
            sanitized_url[j++] = '+'; // replace it with a plus sign
        }
        else { // if character is not allowed
            char hex[4]; // store the hexadecimal representation of the character
            sprintf(hex, "%%%02x", url[i]); // format the hexadecimal string
            strcat(sanitized_url, hex); // add the hexadecimal string to the sanitized URL
            j += 3; // increment the index by three positions for the added characters
        }
    }
    sanitized_url[j] = '\0'; // add null character at the end of the sanitized URL
    return sanitized_url;
}

int main() {
    char url[256];
    printf("Enter a URL to sanitize: ");
    fgets(url, 256, stdin); // read input from user
    // remove newline character from input
    if ((strlen(url) > 0) && (url[strlen(url)-1] == '\n')) {
        url[strlen(url)-1] = '\0';
    }
    char* sanitized_url = sanitize_url(url); // sanitize the input
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url); // free the memory allocated for the sanitized URL
    return 0;
}