//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url);

int main()
{
    char url[MAX_URL_LENGTH];
    
    printf("Please enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    
    // Remove the trailing newline character from the URL
    url[strcspn(url, "\n")] = '\0';
    
    sanitize_url(url);
    
    printf("Your sanitized URL is: %s\n", url);
    
    return 0;
}

void sanitize_url(char *url)
{
    char *http_prefix = "http://";
    char *https_prefix = "https://";
    int has_http_prefix = strncmp(url, http_prefix, strlen(http_prefix)) == 0;
    int has_https_prefix = strncmp(url, https_prefix, strlen(https_prefix)) == 0;
    
    if (!has_http_prefix && !has_https_prefix)
    {
        // Add the http:// prefix if it is not present
        char *new_url = malloc(strlen(http_prefix) + strlen(url) + 1);
        strcpy(new_url, http_prefix);
        strcat(new_url, url);
        strcpy(url, new_url);
        free(new_url);
    }
    
    // Remove query string parameters from the URL
    char *query_string_start = strchr(url, '?');
    if (query_string_start)
    {
        *query_string_start = '\0';
    }
    
    // Remove the fragment identifier from the URL
    char *fragment_identifier_start = strchr(url, '#');
    if (fragment_identifier_start)
    {
        *fragment_identifier_start = '\0';
    }
    
    // Remove any trailing slash character from the URL
    char *last_char = &url[strlen(url) - 1];
    if (*last_char == '/')
    {
        *last_char = '\0';
    }
}