//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 50000

/* This function checks whether a word is present in the dictionary,
 * it returns 1 if the word is found, otherwise it returns 0.
 */
int is_spelled_correctly(char *word, char *dictionary[])
{
    int i;
    for (i = 0; i < MAX_DICTIONARY_WORDS; i++)
    {
        if (dictionary[i] == NULL)
        {
            break;
        }
        else if (strcmp(word, dictionary[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/* This function takes a word and removes all punctuation characters from it.
 * It returns a new string with the resulting word.
 */
char *remove_punctuation(char *word)
{
    char *new_word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int i, j = 0;
    for (i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            new_word[j++] = tolower(word[i]);
        }
    }
    new_word[j] = '\0';
    return new_word;
}

int main()
{
    char *dictionary[MAX_DICTIONARY_WORDS];
    char word[MAX_WORD_LENGTH];
    int i = 0;

    /* Load the dictionary into memory */
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL)
    {
        printf("Error: dictionary file not found.\n");
        return 1;
    }
    while (fgets(word, MAX_WORD_LENGTH, fp) != NULL)
    {
        /* Remove the newline character from the end of the word */
        word[strcspn(word, "\n")] = 0;

        dictionary[i] = malloc(sizeof(char) * MAX_WORD_LENGTH);
        strcpy(dictionary[i++], word);
    }
    dictionary[i] = NULL;

    /* Spell checking loop */
    printf("Enter text to check (press Ctrl+D to exit):\n");
    while (fgets(word, MAX_WORD_LENGTH, stdin) != NULL)
    {
        /* Split each line into words */
        char *token;
        token = strtok(word, " ");
        while (token != NULL)
        {
            char *clean_word = remove_punctuation(token);
            if (!is_spelled_correctly(clean_word, dictionary))
            {
                printf("'%s' is spelled incorrectly.\n", token);
            }
            free(clean_word);
            token = strtok(NULL, " ");
        }
    }

    /* Free memory */
    for (i = 0; i < MAX_DICTIONARY_WORDS; i++)
    {
        free(dictionary[i]);
    }

    return 0;
}