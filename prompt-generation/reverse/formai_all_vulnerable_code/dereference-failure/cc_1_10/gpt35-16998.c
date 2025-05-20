//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
/*
 * C URL Sanitizer Example Program
 *
 * This program takes a potentially unsafe URL as input
 * and makes sure that it only contains safe characters.
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Function Prototypes */
bool is_char_safe(char);
char *sanitize_url(char *);

/* Main Function */
int main() {
    char url[1000];  // Buffer to store the unsafe URL
    char *sanitized_url;  // Pointer to the sanitized URL

    printf("Enter the URL: ");
    fgets(url, sizeof(url), stdin);  // Get the URL from the user

    sanitized_url = sanitize_url(url);  // Sanitize the URL

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}

/*
 * Function to check if a character is safe or not.
 * Returns true if the character is safe, and false otherwise.
 */
bool is_char_safe(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ||
        c == '-' || c == '_' || c == '.' || c == '~') {
        return true;
    }
    return false;
}

/*
 * Function to sanitize the given URL.
 * Returns a pointer to the sanitized URL.
 */
char *sanitize_url(char *url) {
    int len = strlen(url);
    char *sanitized_url = malloc(len + 1);  // Allocate memory for the sanitized URL
    int j = 0;  // Index of the next character in the sanitized URL

    // Loop through each character in the URL
    for (int i = 0; i < len; i++) {
        if (is_char_safe(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
        else {
            // Convert the unsafe character to its percent-encoded value
            int n = snprintf(NULL, 0, "%%%02X", url[i]);
            char *encoded = malloc(n + 1);
            sprintf(encoded, "%%%02X", url[i]);

            // Append the encoded character to the sanitized URL
            strcat(sanitized_url, encoded);
            j += n;
        }
    }

    return sanitized_url;
}