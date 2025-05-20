//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024

void sanitizeURL(char *url) {
    int i, j;
    bool isValid = true;

    // Happy message when function starts
    printf("\nHey there! I'm about to make this URL shine!\n");

    // Sanitizing the URL
    for (i = 0; url[i] && i < MAX_URL_LENGTH; i++) {
        if (url[i] == '?') {
            for (j = i; url[j] && j < MAX_URL_LENGTH; j++) {
                if (url[j] == '&') {
                    url[j] = '\0';
                    break;
                }
            }
            i = j; // Move the index back to the beginning of the query string
            break;
        }
        if (!isalnum(url[i]) && url[i] != '/' && url[i] != '?' && url[i] != '&') {
            isValid = false;
            url[i] = '\0';
            break;
        }
    }

    // Happy message when function finishes its task
    if (isValid) {
        printf("\nYay! The URL is valid and has been sanitized.\n");
    } else {
        printf("\nOops! The URL is not valid and could not be sanitized.\n");
    }
}

int main(int argc, char *argv[]) {
    // Happy message when program starts
    printf("\nHello sunshine! I'm your happy-style C URL Sanitizer.\n");

    if (argc != 2) {
        printf("\nError: Please provide a URL as a command-line argument.\n");
        return 1;
    }

    sanitizeURL(argv[1]);

    return 0;
}