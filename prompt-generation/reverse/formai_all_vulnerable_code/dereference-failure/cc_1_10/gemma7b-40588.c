//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_words(char *str)
{
    int i = 0, word_count = 0;
    char *word = NULL;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            if (word)
            {
                word_count++;
                free(word);
                word = NULL;
            }
        }
        else if (word == NULL)
        {
            word = malloc(20);
            word[0] = '\0';
            word[1] = str[i];
        }
        else
        {
            word = realloc(word, 20 * (word_count + 1));
            word[word_count] = str[i];
            word[word_count + 1] = '\0';
        }

        i++;
    }

    if (word)
    {
        word_count++;
        free(word);
    }

    printf("Word count: %d\n", word_count);
}

int main()
{
    char str[] = "This is a sample text with many words. Some words are short, while others are long. The text also contains punctuation marks, such as commas, periods, and exclamation marks.";

    count_words(str);

    return 0;
}