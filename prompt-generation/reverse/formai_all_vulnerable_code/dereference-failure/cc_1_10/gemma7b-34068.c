//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char *word)
{
    char **dictionary = (char **)malloc(MAX_WORD_LENGTH * sizeof(char *));
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        dictionary[i] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    }

    // Load the dictionary
    dictionary[0] = "apple";
    dictionary[1] = "banana";
    dictionary[2] = "orange";
    dictionary[3] = "grape";
    dictionary[4] = "apricot";

    // Check if the word is in the dictionary
    int found = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    // Print the results
    if (found)
    {
        printf("The word %s is in the dictionary.\n", word);
    }
    else
    {
        printf("The word %s is not in the dictionary.\n", word);
    }

    // Free the memory
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        free(dictionary[i]);
    }
    free(dictionary);
}

int main()
{
    char word[20];

    printf("Enter a word: ");
    scanf("%s", word);

    spell_checker(word);

    return 0;
}