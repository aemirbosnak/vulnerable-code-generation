//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Function to validate the URL
int validateURL(char *url)
{
    // Regex pattern to match valid URLs
    char *pattern = "^(https?://)?(www\\.)?([a-zA-Z0-9]+)\\.([a-zA-Z]{2,6})(/[a-zA-Z0-9-_\\./?%&=]+$)?";
    regex_t regex;

    // Compile the regex pattern
    if (regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB) != 0)
    {
        fprintf(stderr, "Error compiling regex pattern\n");
        return -1;
    }

    // Match the URL against the regex pattern
    int match = regexec(&regex, url, 0, NULL, 0);

    // Free the compiled regex pattern
    regfree(&regex);

    // Return the result (0 for match, non-zero for no match)
    return match;
}

// Function to sanitize the URL
char *sanitizeURL(char *url)
{
    // Allocate memory for the sanitized URL
    char *sanitizedURL = malloc(strlen(url) + 1);
    if (sanitizedURL == NULL)
    {
        fprintf(stderr, "Error allocating memory for sanitized URL\n");
        return NULL;
    }

    // Copy the original URL into the sanitized URL
    strcpy(sanitizedURL, url);

    // Remove any whitespace from the sanitized URL
    char *p = sanitizedURL;
    while (*p != '\0')
    {
        if (isspace(*p))
        {
            *p = '_';
        }
        p++;
    }

    // Remove any non-alphanumeric characters from the sanitized URL
    p = sanitizedURL;
    while (*p != '\0')
    {
        if (!isalnum(*p))
        {
            *p = '_';
        }
        p++;
    }

    // Remove any multiple underscores from the sanitized URL
    p = sanitizedURL;
    while (*p != '\0')
    {
        if (*p == '_' && *(p + 1) == '_')
        {
            memmove(p, p + 1, strlen(p + 1) + 1);
        }
        else
        {
            p++;
        }
    }

    // Return the sanitized URL
    return sanitizedURL;
}

int main(int argc, char **argv)
{
    // Check if the user entered a URL
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s url\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Validate the URL
    int valid = validateURL(argv[1]);
    if (valid != 0)
    {
        fprintf(stderr, "Invalid URL: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Sanitize the URL
    char *sanitizedURL = sanitizeURL(argv[1]);
    if (sanitizedURL == NULL)
    {
        return EXIT_FAILURE;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitizedURL);

    // Free the memory allocated for the sanitized URL
    free(sanitizedURL);

    return EXIT_SUCCESS;
}