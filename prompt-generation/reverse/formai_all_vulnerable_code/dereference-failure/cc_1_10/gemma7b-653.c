//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

char **spell_checker(char **words, int num_words)
{
    char **suggestions = malloc(num_words * MAX_WORD_LENGTH);
    for (int i = 0; i < num_words; i++)
    {
        suggestions[i] = malloc(MAX_WORD_LENGTH);
    }

    for (int i = 0; i < num_words; i++)
    {
        char *word = words[i];
        int word_length = strlen(word);
        for (int j = 0; j < word_length; j++)
        {
            char letter = word[j];
            if (!isupper(letter))
            {
                letter = toupper(letter);
            }
            int suggestion_index = 0;
            for (int k = 0; k < num_words; k++)
            {
                char *suggestion = suggestions[k];
                int suggestion_length = strlen(suggestion);
                for (int l = 0; l < suggestion_length; l++)
                {
                    if (suggestion[l] == letter && !strcmp(word, suggestion))
                    {
                        suggestions[i][suggestion_index] = suggestion[l];
                        suggestion_index++;
                    }
                }
            }
        }
    }

    return suggestions;
}

int main()
{
    char **words = malloc(10 * MAX_WORD_LENGTH);
    words[0] = "apple";
    words[1] = "banana";
    words[2] = "orange";
    words[3] = "grape";
    words[4] = "apricot";
    words[5] = "mango";
    words[6] = "peach";
    words[7] = "pear";
    words[8] = "grapes";
    words[9] = "watermelon";

    char **suggestions = spell_checker(words, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", suggestions[i]);
    }

    return 0;
}