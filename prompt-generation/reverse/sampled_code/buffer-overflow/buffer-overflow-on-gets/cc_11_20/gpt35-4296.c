//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000], search[50], replace[50], new_text[1000];
    int i, j, text_length, search_length, replace_length, found;

    printf("Enter some text: ");
    gets(text);

    printf("Enter the word to search: ");
    gets(search);

    printf("Enter the word to replace: ");
    gets(replace);

    text_length = strlen(text);
    search_length = strlen(search);
    replace_length = strlen(replace);

    if (search_length == replace_length)
    {
        for (i = 0; i < text_length; i++)
        {
            if (text[i] == search[0])
            {
                found = 1;
                for (j = 1; j < search_length; j++)
                {
                    if (text[i+j] != search[j])
                    {
                        found = 0;
                        break;
                    }
                }
                if (found == 1)
                {
                    for (j = 0; j < replace_length; j++)
                    {
                        new_text[i+j] = replace[j];
                    }
                    i += search_length - 1;
                }
                else
                {
                    new_text[i] = text[i];
                }
            }
            else
            {
                new_text[i] = text[i];
            }
        }
    }
    else if (search_length > replace_length)
    {
        printf("Replace word should be longer than search word.");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i = 0; i < text_length; i++)
        {
            if (text[i] == search[0])
            {
                found = 1;
                for (j = 1; j < search_length; j++)
                {
                    if (text[i+j] != search[j])
                    {
                        found = 0;
                        break;
                    }
                }
                if (found == 1)
                {
                    for (j = 0; j < replace_length; j++)
                    {
                        new_text[i+j] = replace[j];
                    }
                    i += search_length - 1;
                }
                else
                {
                    new_text[i] = text[i];
                }
            }
            else
            {
                new_text[i] = text[i];
            }
        }
        new_text[i] = '\0';
        printf("New Text: %s", new_text);
        exit(EXIT_SUCCESS);
    }
}