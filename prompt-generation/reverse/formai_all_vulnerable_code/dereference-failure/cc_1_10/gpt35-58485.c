//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url);

int main()
{
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to be sanitized: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char *sanitized_url = sanitize_url(url);
    printf("The sanitized URL is: %s\n", sanitized_url);

    return 0;
}

char *sanitize_url(char *url)
{
    // Remove any leading or trailing spaces
    char *start = url;
    char *end = url + strlen(url) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
    }
    end[1] = '\0';

    // Remove any anchor portion of the URL
    char *anchor = strchr(start, '#');
    if (anchor != NULL) {
        *anchor = '\0';
    }

    // Remove any query parameters from the URL
    char *query = strchr(start, '?');
    if (query != NULL) {
        char *fragment = strchr(query, '#');
        if (fragment != NULL) {
            *fragment = '\0';
        }
        *query = '\0';
    }

    // Remove any slash at the end of the URL
    size_t url_length = strlen(start);
    if (url_length > 0 && start[url_length - 1] == '/') {
        start[url_length - 1] = '\0';
    }

    // Check and add http protocol prefix
    char *http_prefix = "http://";
    char *https_prefix = "https://";
    if (strncmp(start, http_prefix, strlen(http_prefix)) != 0 && strncmp(start, https_prefix, strlen(https_prefix)) != 0) {
        char *new_url = malloc(sizeof(char) * (url_length + strlen(http_prefix) + 1));
        if (new_url == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        strcpy(new_url, http_prefix);
        strcat(new_url, start);
        return new_url;
    }

    return start;
}