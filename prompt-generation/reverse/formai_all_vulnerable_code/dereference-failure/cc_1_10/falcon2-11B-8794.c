//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

// Function to sanitize a URL
void sanitize_url(char* url) {
    // Split the URL into its components
    char* scheme = strstr(url, "://");
    char* netloc = strstr(url, "@");
    char* path = strstr(url, "/");
    char* query = strstr(url, "?");
    char* fragment = strstr(url, "#");

    // Sanitize each component
    if (scheme!= NULL) {
        *scheme = '\0';
    }

    if (netloc!= NULL) {
        *netloc = '\0';
    }

    if (path!= NULL) {
        *path = '\0';
    }

    if (query!= NULL) {
        *query = '\0';
    }

    if (fragment!= NULL) {
        *fragment = '\0';
    }

    // Reconstruct the sanitized URL
    char sanitized_url[strlen(url) + 1];
    strcpy(sanitized_url, url);

    // Remove any trailing slash from the path
    if (strstr(sanitized_url, "/") == sanitized_url + strlen(sanitized_url) - 1) {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }

    // Append the sanitized components to the sanitized URL
    char* sanitized_scheme = "http";
    char* sanitized_netloc = "";
    char* sanitized_path = "/";
    char* sanitized_query = "";
    char* sanitized_fragment = "";

    if (strlen(scheme) > 0) {
        strcat(sanitized_url, sanitized_scheme);
    }

    if (strlen(netloc) > 0) {
        strcat(sanitized_url, "@");
        strcat(sanitized_url, sanitized_netloc);
    }

    if (strlen(path) > 0) {
        strcat(sanitized_url, path);
    }

    if (strlen(query) > 0) {
        strcat(sanitized_url, "?");
        strcat(sanitized_url, sanitized_query);
    }

    if (strlen(fragment) > 0) {
        strcat(sanitized_url, "#");
        strcat(sanitized_url, sanitized_fragment);
    }

    // Print the sanitized URL
    printf("%s\n", sanitized_url);
}

int main() {
    char url[100];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}