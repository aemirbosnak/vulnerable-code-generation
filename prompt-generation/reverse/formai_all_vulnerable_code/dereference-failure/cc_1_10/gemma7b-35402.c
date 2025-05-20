//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

void spell_checker(char **words, int word_count)
{
    int i, j, k, found = 0;
    char word[20];

    printf("Enter a word: ");
    scanf("%s", word);

    for (i = 0; i < word_count; i++)
    {
        for (j = 0; words[i][j] != '\0'; j++)
        {
            for (k = 0; word[k] != '\0'; k++)
            {
                if (words[i][j] == word[k] && words[i][j + 1] == '\0' && word[k + 1] == '\0')
                {
                    found = 1;
                    break;
                }
            }
        }
    }

    if (found)
    {
        printf("Word found!\n");
    }
    else
    {
        printf("Word not found.\n");
    }
}

int main()
{
    char **words = NULL;
    int word_count = 0;

    words = malloc(MAX_WORDS * sizeof(char *));

    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i] = malloc(20 * sizeof(char));
    }

    spell_checker(words, word_count);

    for (int i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }

    free(words);

    return 0;
}