//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

/* Function to check if the character is a valid URL character*/
bool isValidChar(char c)
{
    if (c >= 48 && c <= 57) // digits 
        return true;
    if (c >= 65 && c <= 90) // uppercase letters 
        return true;
    if (c >= 97 && c <= 122) // lowercase letters
        return true;
    if (c == 45 || c == 46 || c == 95 || c == 126) // hyphen, dot, underscore or tilde 
        return true;
    return false;
}

/* Function to sanitize the URL */
char* sanitizeUrl(char* url)
{
    char* sanitizedUrl = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int j = 0; // index of sanitizedUrl
    for (int i = 0; i < strlen(url); i++)
    {
        if (isValidChar(url[i]))
        {
            sanitizedUrl[j++] = url[i];
        }
        else
        {
            // replace invalid character with hyphen
            sanitizedUrl[j++] = '-';
        }
    }
    sanitizedUrl[j] = '\0'; //add null terminator at the end of sanitizedUrl
    return sanitizedUrl;
}

int main()
{
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove newline character from url

    char* sanitizedUrl = sanitizeUrl(url);

    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl); // free memory allocated for sanitizedUrl
    return 0;
}