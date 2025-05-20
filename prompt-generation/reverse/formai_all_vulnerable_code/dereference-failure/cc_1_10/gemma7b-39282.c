//Gemma-7B DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void text_process(char **text)
{
    int i = 0;
    char word[20];
    char ch;

    while (*text[i] != '\0')
    {
        ch = *text[i];
        if (ch >= 'a' && ch <= 'z')
        {
            word[i] = ch;
            i++;
        }
        else if (word[0] != '\0')
        {
            printf("%s ", word);
            word[0] = '\0';
            i--;
        }
        i++;
    }

    if (word[0] != '\0')
    {
        printf("%s ", word);
    }

    return;
}

int main()
{
    char **text = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        text[i] = (char *)malloc(20 * sizeof(char));
    }

    text[0] = "The quick brown fox jumps over the lazy dog.";
    text[1] = "The swift parrot eats bananas.";
    text[2] = "The curious cat sits on the mat.";

    text_process(text);

    for (int i = 0; i < 10; i++)
    {
        free(text[i]);
    }
    free(text);

    return 0;
}