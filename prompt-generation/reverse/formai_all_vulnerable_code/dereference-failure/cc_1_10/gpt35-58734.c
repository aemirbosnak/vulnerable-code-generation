//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeUrl(char* url){
    // Check if the URL starts with "http://" or "https://"
    char* httpStr = "http://";
    char* httpsStr = "https://";
    int httpLen = strlen(httpStr);
    int httpsLen = strlen(httpsStr);
    if (strncmp(url, httpsStr, httpsLen) != 0 && strncmp(url, httpStr, httpLen) != 0) {
        printf("Invalid URL. Must start with either \"http://\" or \"https://\"\n");
        exit(EXIT_FAILURE);
    }
    
    // Remove any trailing slash
    int urlLen = strlen(url);
    if (url[urlLen - 1] == '/') {
        url[urlLen - 1] = '\0';
    }
    
    // Remove any query parameters (i.e. anything after a '?')
    char* queryStart = strchr(url, '?');
    if (queryStart != NULL) {
        *queryStart = '\0';
    }
    
    // Remove any fragments (i.e. anything after a '#')
    char* fragmentStart = strchr(url, '#');
    if (fragmentStart != NULL) {
        *fragmentStart = '\0';
    }
    
    // Convert any double slashes into single slashes
    char* p = url;
    while (*p != '\0') {
        if (*p == '/' && *(p+1) == '/') {
            strcpy(p, p+1);
        }
        p++;
    }
}

int main() {
    char* url1 = "https://www.example.com:8080/path/to/file.html#fragment?query=param";
    char* url2 = "ftp://www.example.com/path/to/file.html";
    char* url3 = "www.example.com";
    
    printf("Original URL1: %s\n", url1);
    sanitizeUrl(url1);
    printf("Sanitized URL1: %s\n\n", url1);
    
    printf("Original URL2: %s\n", url2);
    sanitizeUrl(url2);
    printf("Sanitized URL2: %s\n\n", url2);
    
    printf("Original URL3: %s\n", url3);
    sanitizeUrl(url3);
    printf("Sanitized URL3: %s\n\n", url3);
    
    return 0;
}