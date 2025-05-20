//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%"
#define REPLACEMENT_CHARACTER '_'

// Function to sanitize the URL by removing all characters that are not allowed
void sanitize_url(char *url) {
    int i = 0;
    int j = 0;
    while (url[i]!= '\0') {
        if (strchr(ALLOWED_CHARACTERS, url[i])!= NULL) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
}

// Function to check if the given string is a valid URL
int is_valid_url(char *url) {
    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7)!= 0 && strncmp(url, "https://", 8)!= 0) {
        return 0;
    }
    // Sanitize the URL
    sanitize_url(url);
    // Check if the URL contains any invalid characters
    if (strpbrk(url, " \"\'<>")!= NULL) {
        return 0;
    }
    return 1;
}

// Function to print an error message and exit the program
void error_exit(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        error_exit("Invalid number of arguments");
    }
    if (!is_valid_url(argv[1])) {
        error_exit("Invalid URL");
    }
    printf("Valid URL: %s\n", argv[1]);
    return 0;
}