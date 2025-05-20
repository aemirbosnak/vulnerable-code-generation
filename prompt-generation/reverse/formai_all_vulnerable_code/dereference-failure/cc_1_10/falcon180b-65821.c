//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 1024

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?'|| c == '&' || c == '=' || c == '+' || c == '%' || c == '@') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL by removing invalid characters and converting to lowercase
void sanitize_url(char* url) {
    int i = 0;
    while (i < strlen(url)) {
        if (!is_valid_url_char(url[i])) {
            memmove(url + i, url + i + 1, strlen(url) - i - 1);
            i--;
        } else {
            url[i] = tolower(url[i]);
            i++;
        }
    }
}

// Recursive function to generate all possible combinations of valid URL characters
void generate_valid_urls(char* url, int start, int length) {
    if (length == 0) {
        printf("%s\n", url);
        return;
    }
    for (int i = start; i <= 'z'; i++) {
        if (is_valid_url_char(i)) {
            url[length] = i;
            generate_valid_urls(url, i + 1, length + 1);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) > MAX_URL_LENGTH) {
        printf("Error: URL too long.\n");
        return 1;
    }
    char sanitized_url[MAX_URL_LENGTH];
    strcpy(sanitized_url, argv[1]);
    sanitize_url(sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    printf("Valid URLs:\n");
    generate_valid_urls(sanitized_url, 'a', 0);
    return 0;
}