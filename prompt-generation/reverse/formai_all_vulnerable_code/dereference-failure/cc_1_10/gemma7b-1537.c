//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>

int spellcheck(char **word, int i, char **dictionary)
{
    int j, k, found = 0;
    char temp[20];

    strcpy(temp, word[i]);
    word[i] = '\0';

    for (j = 0; dictionary[j] != NULL; j++)
    {
        for (k = 0; dictionary[j][k] != '\0'; k++)
        {
            if (strcmp(temp, dictionary[j][k]) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        word[i] = temp[0];
        spellcheck(word, i + 1, dictionary);
    }

    return 0;
}

int main()
{
    char **word = malloc(20 * sizeof(char *));
    char **dictionary = malloc(20 * sizeof(char *));

    word[0] = "hello";
    word[1] = "world";
    word[2] = "apple";
    word[3] = "banana";

    dictionary[0] = "hello";
    dictionary[1] = "world";
    dictionary[2] = "apple";
    dictionary[3] = "banana";
    dictionary[4] = "apricot";

    spellcheck(word, 0, dictionary);

    printf("%s", word[0]);

    return 0;
}