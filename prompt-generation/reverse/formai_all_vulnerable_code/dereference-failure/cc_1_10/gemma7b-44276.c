//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void countWords(char **arr, int n)
{
    int i = 0, count = 0;
    for (i = 0; i < n; i++)
    {
        char *word = arr[i];
        int len = strlen(word);
        int isWord = 0;
        for (int j = 0; j < len; j++)
        {
            if (word[j] >= 'a' && word[j] <= 'z')
            {
                isWord = 1;
            }
        }
        if (isWord)
        {
            count++;
        }
    }
    printf("Total number of words: %d\n", count);
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of sentences: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    printf("Enter the sentences: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    countWords(arr, n);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}