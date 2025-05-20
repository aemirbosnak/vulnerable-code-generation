//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URL
char* sanitize_url(char *url)
{
    // Check if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0)
    {
        // URL is already sanitized
        return url;
    }
    
    // URL does not start with "http://" or "https://", so sanitize it
    char *sanitized_url = (char*) malloc(strlen(url) + 8);
    
    // Add "http://" or "https://" to the beginning of the URL
    strcpy(sanitized_url, "http://");
    if (strncmp(url, "https://", 8) == 0)
    {
        strcat(sanitized_url, "s");
    }
    else
    {
        strcat(sanitized_url, "//");
    }
    
    // Add the remaining part of the URL to the sanitized URL
    strcat(sanitized_url, url);
    
    return sanitized_url;
}

int main()
{
    char url[100];
    
    // Get URL from user
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    
    // Sanitize URL
    char *sanitized_url = sanitize_url(url);
    
    // Print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    // Free memory allocated for sanitized URL
    free(sanitized_url);
    
    return 0;
}