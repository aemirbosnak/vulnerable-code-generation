//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
/*
 *  url_sanitize.c - A Unique C URL sanitizer program
 *  
 *  Written by [Your Name]
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

// Function to sanitize URL
void sanitize_url(char *url);

int main(void) {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}

/*
 * Function to sanitize URL
 * 
 * This function removes any whitespace characters from the URL
 * and converts all alphabetic characters in the hostname to lowercase,
 * as per the domain name resolution protocol (DNS).
 */
void sanitize_url(char *url) {
    char *orig_url = url;
    char *c = url;

    while (*c != '\0') {

        // Convert characters in the hostname to lowercase
        if (*c == '/') {
            break;
        } else if (*c == '.') {
            int i = 1;

            // Convert the characters in the hostname to lowercase
            while (*(c - i) != '/') {
                *(c - i) = tolower(*(c - i));
                i++;
            }
        }

        // Remove any whitespace characters
        if (isspace((unsigned char)*c)) {
            int i = 0;

            // Shift the string left for each whitespace character
            while (*(c + i) != '\0') {
                *(c + i) = *(c + i + 1);
                i++;
            }

            // Move the pointer back one position to account for the shifted string
            c--;
        } else {
            *c = *c;
        }

        c++;
    }

    // Remove any trailing slash character after the hostname
    if (*(c - 1) == '/') {
        *(c - 1) = '\0';
    }

    // Fix the null terminator at the end of the string
    if (strlen(orig_url) < MAX_URL_LENGTH - 1) {
        *(orig_url + strlen(orig_url) - 1) = '\0';
    }
}