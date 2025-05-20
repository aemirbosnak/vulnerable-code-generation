//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

// Define the allowed characters in the URL
char allowedChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_~:/?#[]@!$&'()*+,;=";

// Define the regular expression pattern to match the URL
char pattern[] = "^(https?://)?(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)";

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Function to check if the given URL is valid
int isValidUrl(char *url)
{
    // Compile the regular expression
    regex_t regex;
    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret != 0)
    {
        fprintf(stderr, "Error compiling regular expression: %s\n", strerror(ret));
        return 0;
    }

    // Check if the URL matches the regular expression
    size_t nmatch = 1;
    regmatch_t pmatch[nmatch];
    ret = regexec(&regex, url, nmatch, pmatch, 0);
    regfree(&regex);

    // If the URL matches the regular expression, return 1, otherwise return 0
    return ret == 0;
}

// Function to sanitize the given URL
char *sanitizeUrl(char *url)
{
    // Allocate a buffer to store the sanitized URL
    char *sanitizedUrl = malloc(MAX_BUFFER_SIZE);

    // Initialize the index of the sanitized URL
    int i = 0;

    // Iterate over the characters in the input URL
    for (int j = 0; j < strlen(url); j++)
    {
        // If the character is allowed, append it to the sanitized URL
        if (strchr(allowedChars, url[j]) != NULL)
        {
            sanitizedUrl[i++] = url[j];
        }
    }

    // Terminate the sanitized URL with a null character
    sanitizedUrl[i] = '\0';

    // Return the sanitized URL
    return sanitizedUrl;
}

// Main function
int main()
{
    // Get the input URL from the user
    char url[MAX_BUFFER_SIZE];
    printf("Enter the URL: ");
    scanf("%s", url);

    // Sanitize the input URL
    char *sanitizedUrl = sanitizeUrl(url);

    // Check if the sanitized URL is valid
    if (isValidUrl(sanitizedUrl))
    {
        // Print the sanitized URL
        printf("Sanitized URL: %s\n", sanitizedUrl);
    }
    else
    {
        // Print an error message
        printf("Invalid URL: %s\n", url);
    }

    // Free the allocated memory
    free(sanitizedUrl);

    return 0;
}