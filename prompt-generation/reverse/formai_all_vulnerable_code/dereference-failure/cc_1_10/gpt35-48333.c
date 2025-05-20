//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

// Function to check if a character is a valid URL character
int is_valid_url_char(char ch)
{
    if(isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~')
    {
        return 1;
    }
    return 0;
}

// Function to sanitize a given URL
char* sanitize_url(char* url)
{
    int url_length = strlen(url);
    char* sanitized_url = (char*)malloc(sizeof(char) * (MAX_URL_LENGTH + 1));
    int j = 0;

    for(int i = 0; i < url_length; i++)
    {
        if(is_valid_url_char(url[i]))
        {
            sanitized_url[j++] = url[i];
        }
        else if(url[i] == ' ')
        {
            sanitized_url[j++] = '+';
        }
    }

    // Add null character at the end of sanitized URL
    sanitized_url[j] = '\0';

    return sanitized_url;
}

// Main function
int main()
{
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove trailing newline character from URL
    url[strcspn(url, "\n")] = '\0';

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s", sanitized_url);

    // Free memory allocated for sanitized URL
    free(sanitized_url);

    return 0;
}