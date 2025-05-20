//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to sanitize the URL
void sanitize_url(char *url) {

    // Identify and remove the protocol substring
    char *temp = strstr(url, "://");
    if (temp != NULL) {
        memmove(url, temp + 3, strlen(temp));
    }

    // Remove all trailing slashes
    int len = strlen(url);
    while (url[len-1] == '/') {
        url[len-1] = '\0';
        len--;
    }

    // Remove all occurrences of the query string
    char *query = strstr(url, "?");
    while (query != NULL) {
        *query = '\0';
        query = strstr(url, "?");
    }

    // Remove the hash substring
    char *hash = strstr(url, "#");
    if (hash != NULL) {
        *hash = '\0';
    }

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any illegal characters
    char *illegal_chars = "<>[]{}|\\^`";
    for (int i = 0; i < strlen(illegal_chars); i++) {
        char *illegal = strchr(url, illegal_chars[i]);
        while (illegal != NULL)
        {
            memmove(illegal, illegal+1, strlen(illegal));
            illegal = strchr(url, illegal_chars[i]);
        }
    }

    // Remove any duplicated slashes
    for (int i = 0; i < strlen(url) - 1; i++) {
        if (url[i] == '/' && url[i+1] == '/') {
            memmove(&url[i], &url[i+1], strlen(&url[i]));
            i--;
        }
    }
}

int main() {

    // Get the URL from the user
    char url[1000];
    printf("Please enter the URL: ");
    fgets(url, 1000, stdin);

    // Remove the newline character from the end of the string
    url[strcspn(url, "\n")] = 0;

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", url);

    return 0;
}