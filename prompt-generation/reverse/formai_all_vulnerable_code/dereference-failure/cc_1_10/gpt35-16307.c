//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a character is valid or not
int is_valid_char(char ch) {
    if (isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~') {
        return 1;
    }
    return 0;
}

// Function to sanitize the URL
void sanitize_url(char* url) {
    int len = strlen(url);
    int i, j;

    // Create a new URL buffer
    char* new_url = (char*) malloc ((len+1) * sizeof(char));

    // Copy the valid characters from the old URL to the new URL
    for (i = 0, j = 0; i < len; i++) {
        if (is_valid_char(url[i])) {
            new_url[j++] = url[i];
        }
    }

    // Null terminate the new URL
    new_url[j] = '\0';

    // Copy the new URL back to the old URL buffer
    strcpy(url, new_url);

    // Free the memory used by the new URL buffer
    free(new_url);
}

int main() {
    // Get the URL from the user
    char url[1000];
    printf("Enter a URL to sanitize: ");
    scanf("%[^\n]%*c", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}