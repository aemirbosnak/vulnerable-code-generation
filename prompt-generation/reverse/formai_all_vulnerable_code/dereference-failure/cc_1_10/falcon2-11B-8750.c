//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a word is spelled correctly
int isSpelledCorrectly(char *word, char *dictionary[])
{
    int i;
    for (i = 0; dictionary[i]!= NULL; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to suggest corrections for a misspelled word
char *suggestCorrections(char *word, char *dictionary[])
{
    char *suggestion = NULL;
    int i;
    for (i = 0; dictionary[i]!= NULL; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            suggestion = dictionary[i];
            break;
        }
    }
    return suggestion;
}

// Function to spell check a string
int spellCheck(char *string, char *dictionary[])
{
    int i;
    for (i = 0; string[i]!= '\0'; i++)
    {
        if (isalpha(string[i]) &&!isSpelledCorrectly(string + i - 1, dictionary))
        {
            // Replace the misspelled word with its correction
            char *misspelledWord = string + i - 1;
            char *correctedWord = suggestCorrections(misspelledWord, dictionary);
            string[i - 1] = '\0';
            string[i] = correctedWord[0];
            string[i + strlen(correctedWord)] = '\0';
            i += strlen(correctedWord);
        }
    }
    return 1;
}

int main()
{
    char string[100];
    printf("Enter a string to spell check: ");
    fgets(string, sizeof(string), stdin);
    char *dictionary[] = {"apple", "banana", "pear", "orange"};
    spellCheck(string, dictionary);
    printf("Spell checked string: %s\n", string);
    return 0;
}