//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char* url) {
    // Remove leading and trailing whitespace
    char* start = url;
    char* end = url + strlen(url);
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*(end - 1))) {
        end--;
        *end = '\0';
    }

    // Remove invalid characters
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    sanitized_url[0] = '\0';
    char* current_pos = sanitized_url;
    for (char* pos = start; pos < end; pos++) {
        if (isalnum(*pos) || *pos == '-') {
            current_pos += sprintf(current_pos, "%c", tolower(*pos));
        }
    }

    // Add leading and trailing slashes if needed
    if (strlen(sanitized_url) > 0 && sanitized_url[0]!= '/') {
        strcat(sanitized_url, "/");
    }
    if (strlen(sanitized_url) > 0 && sanitized_url[strlen(sanitized_url) - 1]!= '/') {
        strcat(sanitized_url, "/");
    }

    // Copy sanitized URL back to original buffer
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}