//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char **str)
{
    char *ptr = *str;
    char *temp = NULL;

    // Remove all special characters
    while (*ptr)
    {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9') || (*ptr == '_') || (*ptr == '-') || (*ptr == '+'))
        {
            ptr++;
            continue;
        }

        temp = realloc(ptr, sizeof(char) * (strlen(*str) + 1));
        if (temp)
        {
            *str = temp;
            ptr = *str + strlen(*str);
        }
        else
        {
            free(*str);
            return;
        }
    }

    *str = realloc(*str, sizeof(char) * (strlen(*str) + 1));
    **str = temp;

    return;
}

int main()
{
    char *str = NULL;
    char input[1024];

    printf("Enter a string: ");
    fgets(input, 1024, stdin);

    str = strdup(input);

    sanitize(&str);

    printf("Sanitized string: %s\n", str);

    free(str);

    return 0;
}