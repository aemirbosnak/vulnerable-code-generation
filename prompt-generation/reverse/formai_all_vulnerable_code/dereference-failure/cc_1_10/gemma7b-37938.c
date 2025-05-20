//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

char *read_string(char **str)
{
    *str = malloc(MAX_STRING_LENGTH);
    printf("Enter a string: ");
    fgets(*str, MAX_STRING_LENGTH, stdin);
    return *str;
}

int spam_detector(char *str)
{
    int flags = 0;

    // Check for common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "miracle"};
    for (int i = 0; i < 5; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            flags++;
        }
    }

    // Check for exclamation marks
    if (strstr(str, "!!!"))
    {
        flags++;
    }

    // Check for capitalization inconsistencies
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        flags++;
    }

    // Check for excessive punctuation
    if (str[0] == '.' || str[0] == ',')
    {
        flags++;
    }

    return flags;
}

int main()
{
    char *str;
    int flags;

    read_string(&str);
    flags = spam_detector(str);

    if (flags > 0)
    {
        printf("Spam detected!\n");
    } else
    {
        printf("No spam detected.\n");
    }

    free(str);
    return 0;
}