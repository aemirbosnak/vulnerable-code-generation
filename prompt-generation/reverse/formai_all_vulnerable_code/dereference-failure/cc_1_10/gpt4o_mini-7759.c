//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// A structure to represent a URL
typedef struct {
    char scheme[10];
    char host[100];
    char path[MAX_URL_LENGTH];
} URL;

// Function to sanitize the URL by escaping special characters
void sanitize_url(const char *url, char *sanitized_url) {
    char hex[4];
    char *p = sanitized_url;

    while (*url) {
        if (isalnum((unsigned char)*url) || strchr("-._~", *url)) {
            *p++ = *url;
        } else {
            sprintf(hex, "%%%02X", (unsigned char)*url);
            strcpy(p, hex);
            p += 3; // move past the added hex code
        }
        url++;
    }
    *p = '\0'; // Null-terminate the string
}

// Function to parse the URL into its components
void parse_url(const char *url_str, URL *url) {
    char *url_copy = strdup(url_str);
    char *scheme_end = strstr(url_copy, "://");
    
    if (scheme_end) {
        strncpy(url->scheme, url_copy, scheme_end - url_copy);
        url->scheme[scheme_end - url_copy] = '\0';
        
        char *host_start = scheme_end + 3; // Move past '://'
        char *path_start = strchr(host_start, '/');
        
        if (path_start) {
            strncpy(url->host, host_start, path_start - host_start);
            url->host[path_start - host_start] = '\0';
            strcpy(url->path, path_start); // Copy the rest as the path
        } else {
            strcpy(url->host, host_start);
            url->path[0] = '\0'; // No path
        }
    } else {
        // Assume the entire string is host without scheme
        url->scheme[0] = '\0';
        strcpy(url->host, url_copy);
        url->path[0] = '\0';
    }
    free(url_copy);
}

// Function to display the sanitized URL
void display_sanitized_url(const URL *url) {
    char sanitized_path[MAX_URL_LENGTH * 3]; // In a worst case scenario, the path could triple in length
    sanitize_url(url->path, sanitized_path);

    printf("Sanitized URL:\n");
    if (url->scheme[0] != '\0') {
        printf("Scheme: %s\n", url->scheme);
    }
    printf("Host: %s\n", url->host);
    printf("Path: %s\n", sanitized_path);
}

int main() {
    printf("Welcome to the URL Sanitizer, brought to you in the style of Sherlock Holmes!\n");
    printf("Please provide the URL you wish to sanitize:\n");

    char input_url[MAX_URL_LENGTH];
    fgets(input_url, MAX_URL_LENGTH, stdin);
    
    // Remove trailing newline if present
    input_url[strcspn(input_url, "\n")] = '\0';

    URL url;
    parse_url(input_url, &url);
    
    printf("\nHolmes would approve of a fine sanitization!\n");
    display_sanitized_url(&url);

    return 0;
}