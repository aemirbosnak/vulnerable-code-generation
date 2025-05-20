//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sanitizeURL(char *url);

int main()
{
    char *url = "hTtPs://example.com//path/./to/../resource.html";
    printf("Original URL: %s\n", url);

    char *sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);

    return 0;
}

char *sanitizeURL(char *url)
{
    char *scheme = strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *path = strtok(NULL, "");

    // Convert scheme and host to lowercase
    for (int i = 0; scheme[i]; i++)
    {
        scheme[i] = tolower(scheme[i]);
    }
    for (int i = 0; host[i]; i++)
    {
        host[i] = tolower(host[i]);
    }

    // Remove path segments containing "."
    char *token;
    while ((token = strtok(NULL, "/")))
    {
        if (strcmp(token, ".") == 0)
        {
            // Skip this segment
            continue;
        }
        if (strcmp(token, "..") == 0)
        {
            // Remove the last segment if it's not empty
            if (strlen(path) > 0)
            {
                // Find the last "/"
                char *lastSlash = strrchr(path, '/');
                if (lastSlash)
                {
                    *lastSlash = '\0';
                }
            }
        }
        else
        {
            // Add this segment to the path
            strcat(path, "/");
            strcat(path, token);
        }
    }

    // Remove extra slashes in path
    char *in = path, *out = path;
    while (*in)
    {
        if (*in == '/' && *(in + 1) == '/')
        {
            // Skip this slash
            in++;
        }
        else
        {
            // Copy the character
            *out++ = *in++;
        }
    }
    *out = '\0';

    // Combine the scheme, host, and sanitized path
    char *sanitizedURL = malloc(strlen(scheme) + strlen(host) + strlen(path) + 4);
    sprintf(sanitizedURL, "%s://%s%s", scheme, host, path);

    return sanitizedURL;
}