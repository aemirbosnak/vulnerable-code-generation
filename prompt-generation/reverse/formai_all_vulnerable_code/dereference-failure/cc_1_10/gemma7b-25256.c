//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

int sanitize_url(char **url)
{
    char *new_url = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0, valid = 1;

    for (i = 0; (*url)[i] != '\0'; i++)
    {
        if (!isalnum((*url)[i]) && (*url)[i] != '-' && (*url)[i] != '_')
        {
            valid = 0;
            break;
        }

        if (valid)
        {
            if (islower((*url)[i]))
            {
                new_url[j++] = toupper((*url)[i]);
            }
            else
            {
                new_url[j++] = (*url)[i];
            }
        }
    }

    if (valid)
    {
        *url = new_url;
        return 1;
    }

    return 0;
}

int main()
{
    char *url = "abc&xyz-123$%^&*()";

    if (sanitize_url(&url))
    {
        printf("Sanitized URL: %s\n", url);
    }
    else
    {
        printf("Error sanitizing URL.\n");
    }

    return 0;
}