//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    printf("Enter text: ");
    fgets(str, 1000, stdin);

    // Remove common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "offer"};
    int i = 0;
    for (i = 0; spam_words[i] != NULL; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            printf("Text contains spam words.\n");
            break;
        }
    }

    // Check for grammatical errors
    char *grammar_errors[] = {"grammar", "syntax", "errors"};
    i = 0;
    for (i = 0; grammar_errors[i] != NULL; i++)
    {
        if (strstr(str, grammar_errors[i]) != NULL)
        {
            printf("Text contains grammatical errors.\n");
            break;
        }
    }

    // Check for suspicious formatting
    char *suspicious_formatting[] = {"$$$", "****", "!!!"};
    i = 0;
    for (i = 0; suspicious_formatting[i] != NULL; i++)
    {
        if (strstr(str, suspicious_formatting[i]) != NULL)
        {
            printf("Text contains suspicious formatting.\n");
            break;
        }
    }

    // If no spam or errors found, print message
    if (i == 3)
    {
        printf("Text is clean.\n");
    }

    return 0;
}