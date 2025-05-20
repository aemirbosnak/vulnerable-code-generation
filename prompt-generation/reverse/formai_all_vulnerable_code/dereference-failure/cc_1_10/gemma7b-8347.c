//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 255

char* sanitize_url(char* url)
{
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int len = strlen(url);

    for (i = 0; i < len; i++)
    {
        char ch = url[i];

        // Normalize spaces
        if (ch == ' ')
        {
            sanitized_url[i] = '+';
        }
        // Convert uppercase letters to lowercase
        else if (isupper(ch))
        {
            sanitized_url[i] = tolower(ch);
        }
        // Remove invalid characters
        else if (!isalnum(ch) && ch != '-')
        {
            sanitized_url[i] = '\0';
        }
        else
        {
            sanitized_url[i] = ch;
        }
    }

    sanitized_url[len] = '\0';

    return sanitized_url;
}

int main()
{
    char* url = "This is an example URL with spaces, uppercase letters, and special characters!";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}