//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check whether a given character is alphanumeric or not
int isAlNum(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

// Function to sanitize the given URL
void sanitizeURL(char *url)
{
    // Allocate memory for the sanitized URL
    char *sanitizedURL = (char*)malloc(strlen(url) + 1);

    // Iterate through each character of the URL
    int i, j;
    for (i = 0, j = 0; url[i] != '\0'; i++)
    {
        // If the current character is alphanumeric, copy it to the sanitized URL
        if (isAlNum(url[i]))
            sanitizedURL[j++] = url[i];
        
        // If the current character is a special character, skip it
    }

    // Add the null terminator to the sanitized URL
    sanitizedURL[j] = '\0';

    // Copy the sanitized URL back to the original URL
    strcpy(url, sanitizedURL);

    // Free the memory allocated for the sanitized URL
    free(sanitizedURL);
}

int main()
{
    char url[1000];

    // Read the URL from the user
    printf("Enter the URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';   // Remove the trailing newline character

    // Sanitize the URL
    sanitizeURL(url);

    // Display the sanitized URL
    printf("The sanitized URL is: %s\n", url);

    return 0;
}