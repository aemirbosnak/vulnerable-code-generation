//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char **url)
{
    char *new_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;

    for (i = 0; (*url)[i] != '\0'; i++)
    {
        if ((*url)[i] >= 'a' && (*url)[i] <= 'z')
        {
            new_url[j++] = (*url)[i] - 32;
        }
        else if ((*url)[i] >= 'A' && (*url)[i] <= 'Z')
        {
            new_url[j++] = (*url)[i] + 32;
        }
        else if ((*url)[i] >= '0' && (*url)[i] <= '9')
        {
            new_url[j++] = (*url)[i];
        }
        else if ((*url)[i] == '/' || (*url)[i] == '\\' || (*url)[i] == '?')
        {
            new_url[j++] = '_';
        }
    }

    new_url[j] = '\0';
    *url = new_url;
}

int main()
{
    char *url = malloc(MAX_URL_LENGTH);
    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(&url);

    printf("Sanitized URL: %s\n", url);

    free(url);

    return 0;
}