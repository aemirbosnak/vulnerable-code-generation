//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a URL
void parse_url(char *url, char **scheme, char **host, char **path, char **query) {
    *scheme = strtok(*url, "://");
    *host = strtok(*scheme, "/");
    *path = strtok(*host, "/");
    *query = strtok(*path, "?");
}

// Function to validate a URL
int validate_url(char *url) {
    // Check for special characters
    if (strstr(url, "javascript:alert('XSS');")!= NULL ||
        strstr(url, "javascript:prompt('XSS');")!= NULL ||
        strstr(url, "javascript:confirm('XSS');")!= NULL ||
        strstr(url, "javascript:location.href='http://evil.com/';")!= NULL ||
        strstr(url, "javascript:history.go(-1);")!= NULL) {
        return 0; // URL is not safe
    }
    // Check for other potential exploits
    return 1; // URL is safe
}

// Main function
int main() {
    char url[1000];
    char *scheme;
    char *host;
    char *path;
    char *query;
    int is_safe;

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove newline character if present

    parse_url(url, &scheme, &host, &path, &query);

    is_safe = validate_url(url);

    if (is_safe) {
        printf("%s\n", url);
    } else {
        printf("URL is not safe!\n");
    }

    return 0;
}