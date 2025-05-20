//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

// Function prototype
char *sanitize_url(char *url);

int main()
{
    char url[MAX_URL_LENGTH];
    char *sanitized_url;

    // Prompt user to enter URL
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove newline character from URL
    url[strcspn(url, "\n")] = '\0';

    // Sanitize URL
    sanitized_url = sanitize_url(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}

char *sanitize_url(char *url)
{
    int i, j = 0;
    char *sanitized_url = (char *) malloc(MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);

    // Remove whitespace from URL
    for (i = 0; url[i] != '\0'; i++)
    {
        if (!isspace(url[i]))
        {
            sanitized_url[j++] = url[i];
        }
    }

    // Check if URL starts with "http://" or "https://"
    if (strncmp(sanitized_url, "http://", 7) != 0 && strncmp(sanitized_url, "https://", 8) != 0)
    {
        // Add "http://" to URL if it doesn't start with "http://" or "https://
        char *temp_url = (char *) malloc(MAX_URL_LENGTH);
        memset(temp_url, 0, MAX_URL_LENGTH);
        strcpy(temp_url, sanitized_url);
        memset(sanitized_url, 0, MAX_URL_LENGTH);
        strcat(sanitized_url, "http://");
        strcat(sanitized_url, temp_url);
        free(temp_url);
    }

    // Remove any trailing slashes from URL
    if (sanitized_url[strlen(sanitized_url) - 1] == '/')
    {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }

    // Convert all uppercase letters in URL to lowercase
    for (i = 0; sanitized_url[i] != '\0'; i++)
    {
        sanitized_url[i] = tolower(sanitized_url[i]);
    }

    return sanitized_url;
}