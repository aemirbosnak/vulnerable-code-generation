//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void count_words(char *str)
{
    int i = 0, word_count = 0;
    char *word = NULL;

    while (str[i] != '\0')
    {
        if (word == NULL)
        {
            word = malloc(20);
            word[0] = '\0';
        }

        if (str[i] >= 'a' && str[i] <= 'z')
        {
            word[i] = str[i];
            i++;
        }
        else
        {
            if (word[0] != '\0')
            {
                word_count++;
                free(word);
                word = NULL;
            }
            i++;
        }
    }

    if (word != NULL)
    {
        free(word);
    }

    printf("Word count: %d\n", word_count);
}

int main()
{
    char str[] = "This is a sentence with many words. The quick brown fox jumps over the lazy dog.";

    count_words(str);

    return 0;
}