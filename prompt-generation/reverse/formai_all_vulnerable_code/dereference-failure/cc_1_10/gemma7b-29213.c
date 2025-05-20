//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

char **words(char **arr, int *n)
{
    char *str = arr[0];
    char *p = str;
    int i = 0;
    *n = 0;

    while (p)
    {
        char word[MAX_WORDS];
        int j = 0;

        while (isalnum(*p) && j < MAX_WORDS)
        {
            word[j++] = *p;
            p++;
        }

        word[j] = '\0';

        if (strcmp(word, "") != 0)
        {
            arr[*n] = strdup(word);
            (*n)++;
        }
    }

    return arr;
}

int main()
{
    char **arr = NULL;
    int n = 0;

    arr = words(arr, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}