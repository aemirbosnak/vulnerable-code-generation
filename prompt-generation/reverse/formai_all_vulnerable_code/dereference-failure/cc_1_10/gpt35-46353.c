//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a character is an alphabet or not
bool isAlpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a digit or not
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a valid URL character or not
bool isValidURLChar(char c)
{
    return (isAlpha(c) || isDigit(c) || c == ':' || c == '.' || c == '/' || c == '-' || c == '_');
}

// Function to sanitize a given URL string
void sanitizeURL(char* url)
{
    char* sanitizedURL = (char*)malloc(strlen(url) + 1);
    int j = 0;

    for (int i = 0; url[i] != '\0'; i++) {
        if (isValidURLChar(url[i])) {
            sanitizedURL[j++] = url[i];
        }
    }

    sanitizedURL[j] = '\0';

    printf("Sanitized URL: %s\n", sanitizedURL);
}

// Driver function
int main()
{
    char url[100];

    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    sanitizeURL(url);

    return 0;
}