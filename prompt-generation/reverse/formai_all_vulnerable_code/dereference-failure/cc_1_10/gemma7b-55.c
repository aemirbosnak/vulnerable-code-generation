//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>

int spellcheck(char **word, int i, char **dictionary)
{
    int j, k, flag = 0;

    if (i >= (*word)[0] - 'a' + 1)
    {
        return 1;
    }

    for (j = 0; dictionary[j] != NULL; j++)
    {
        for (k = 0; dictionary[j][k] != '\0'; k++)
        {
            if (word[i] == dictionary[j][k] && spellcheck(word, i + 1, dictionary) == 1)
            {
                flag = 1;
            }
        }
    }

    return flag;
}

int main()
{
    char **word = malloc(10 * sizeof(char *));
    char **dictionary = malloc(100 * sizeof(char *));

    word[0] = "hello";
    word[1] = "world";
    word[2] = "apple";
    word[3] = "banana";

    dictionary[0] = "hello";
    dictionary[1] = "world";
    dictionary[2] = "apple";
    dictionary[3] = "banana";
    dictionary[4] = "orange";

    if (spellcheck(word, 0, dictionary) == 1)
    {
        printf("Word is spelled correctly\n");
    }
    else
    {
        printf("Word is not spelled correctly\n");
    }

    free(word);
    free(dictionary);

    return 0;
}