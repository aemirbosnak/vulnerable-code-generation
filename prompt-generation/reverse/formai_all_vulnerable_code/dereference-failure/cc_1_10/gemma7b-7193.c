//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char **spell_check(char **word_list, int word_list_size)
{
    int i, j, k, spell_check_error = 0;
    char **new_word_list = NULL;

    for (i = 0; i < word_list_size; i++)
    {
        for (j = 0; j < word_list_size; j++)
        {
            if (i != j)
            {
                for (k = 0; k < strlen(word_list[i]); k++)
                {
                    if (strcmp(word_list[i], word_list[j]) == 0)
                    {
                        spell_check_error = 1;
                        break;
                    }
                }
            }
        }

        if (spell_check_error)
        {
            new_word_list = realloc(new_word_list, (i + 1) * sizeof(char *));
            new_word_list[i] = strdup(word_list[i]);
        }
        else
        {
            new_word_list = realloc(new_word_list, (i) * sizeof(char *));
            new_word_list[i] = NULL;
        }

        spell_check_error = 0;
    }

    return new_word_list;
}

int main()
{
    char **word_list = NULL;
    int word_list_size = 0;

    word_list = spell_check(word_list, word_list_size);

    for (int i = 0; word_list[i] != NULL; i++)
    {
        printf("%s ", word_list[i]);
    }

    printf("\n");

    return 0;
}