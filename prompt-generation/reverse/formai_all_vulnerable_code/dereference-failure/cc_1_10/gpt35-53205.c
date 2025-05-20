//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declaring a function to check if a string is a valid URL
bool validate_url(char* url) {
    // Validating the URL according to some criteria
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return false;
    }
    if (strchr(url, ' ') != NULL) {
        return false;
    }
    if (strstr(url, "..") != NULL) {
        return false;
    }
    return true;
}

// Declaring the main function
int main(void) {
    // Allocating memory for the input URL
    char* input_url = malloc(sizeof(char) * 256);
    if (input_url == NULL) {
        printf("Error: Memory allocation failed!");
        return 1;
    }

    // Prompting the user to enter a URL
    printf("Enter a URL to sanitize: ");
    scanf("%255s", input_url);

    // Validating the URL
    if (!validate_url(input_url)) {
        printf("Error: Invalid URL!\n");
        return 1;
    }

    // Allocating memory for the sanitized URL
    char* sanitized_url = malloc(sizeof(char) * 256);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed!");
        return 1;
    }

    // Sanitizing the URL
    int input_url_length = strlen(input_url);
    int sanitized_url_length = 0;
    for (int i = 0; i < input_url_length; i++) {
        char current_char = input_url[i];
        if (current_char >= 'A' && current_char <= 'Z') {
            current_char += 'a' - 'A';
        }
        if (current_char != '\r' && current_char != '\n') {
            sanitized_url[sanitized_url_length] = current_char;
            sanitized_url_length++;
        }
    }
    sanitized_url[sanitized_url_length] = '\0';

    // Printing the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Freeing the memory
    free(input_url);
    free(sanitized_url);

    return 0;
}