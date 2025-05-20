//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c)
{
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
        return 1;
    return 0;
}

void sanitize_url(char* url)
{
    int i, j;
    char* new_url = malloc(MAX_URL_LENGTH);
    int new_url_length = 0;

    for (i = 0; i < strlen(url); i++)
    {
        if (is_valid_url_char(url[i]))
        {
            if (new_url_length == MAX_URL_LENGTH - 1)
            {
                printf("Error: URL is too long.\n");
                exit(1);
            }
            new_url[new_url_length++] = url[i];
        }
    }

    new_url[new_url_length] = '\0';

    printf("Sanitized URL: %s\n", new_url);
    free(new_url);
}

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}