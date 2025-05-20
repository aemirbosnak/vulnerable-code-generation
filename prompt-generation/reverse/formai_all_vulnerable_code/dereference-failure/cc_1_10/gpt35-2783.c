//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
/* C URL Sanitizer Program */
/* Written in the style of Dennis Ritchie */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048 /* Maximum length of a URL */

/* Function prototypes */
char* sanitize_url(char* url);
int is_valid_char(char c);
int is_hex_digit(char c);

/* Main program */
int main(void) {
    char url[MAX_URL_LENGTH];

    /* Prompt user for a URL */
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    /* Sanitize the URL */
    char* sanitized_url = sanitize_url(url);

    /* Display the sanitized URL */
    printf("Sanitized URL: %s\n", sanitized_url);

    /* Free dynamically allocated memory */
    free(sanitized_url);

    return 0;
}

/* Sanitize a given URL string by removing any invalid characters and URL encoding any reserved characters */
char* sanitize_url(char* url) {
    /* Allocate memory to store the sanitized URL */
    char* sanitized_url = (char*) malloc(sizeof(char) * (MAX_URL_LENGTH + 1));
    int sanitized_url_index = 0; /* Index variable for sanitized_url */

    /* Loop through each character in the original URL */
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        /* Check if the character is valid */
        if (is_valid_char(c)) {
            /* Add the character to the sanitized URL */
            sanitized_url[sanitized_url_index] = c;
            sanitized_url_index++;
        }
        else {
            /* URL encode the character and add it to the sanitized URL */
            sprintf(&sanitized_url[sanitized_url_index], "%%%02X", c);
            sanitized_url_index += 3;
        }

        /* Check if the sanitized URL has reached its maximum length */
        if (sanitized_url_index >= MAX_URL_LENGTH) {
            break;
        }
    }

    /* Null-terminate the sanitized URL */
    sanitized_url[sanitized_url_index] = '\0';

    return sanitized_url;
}

/* Check if a given character is valid for a URL */
int is_valid_char(char c) {
    /* Check if the character is an alphanumeric character or one of the following special characters: */
    /* -._~:/?#[]@!$&'()*+,;= */
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == ':' || c == '/' || c == '?' || c == '#' || c == '[' || c == ']' || c == '@' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=') {
        return 1;
    }

    return 0;
}

/* Check if a given character is a hexadecimal digit */
int is_hex_digit(char c) {
    if (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
        return 1;
    }

    return 0;
}