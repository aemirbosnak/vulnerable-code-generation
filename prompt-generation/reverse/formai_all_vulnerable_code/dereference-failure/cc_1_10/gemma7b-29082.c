//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main()
{
    char **words = (char**)malloc(MAX_WORDS * sizeof(char*));
    int word_count = 0;

    // Read words from the input
    printf("Enter a word: ");
    char word[20];
    scanf("%s", word);
    words[word_count++] = strdup(word);

    // Loop over the words and check for spelling errors
    for (int i = 0; i < word_count; i++)
    {
        int error_count = 0;
        for (int j = 0; j < strlen(words[i]); j++)
        {
            // Check if the letter is not alphabetical
            if (!isalnum(words[i][j]))
            {
                error_count++;
            }

            // Check if the letter is repeated
            for (int k = 0; k < i; k++)
            {
                if (strcmp(words[i], words[k]) == 0)
                {
                    error_count++;
                }
            }
        }

        // If there are no errors, print the word
        if (error_count == 0)
        {
            printf("%s is a valid word.\n", words[i]);
        }
        else
        {
            printf("%s has %d errors.\n", words[i], error_count);
        }
    }

    free(words);
    return 0;
}