//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main()
{
    char ***words = NULL;
    int word_count = 0;

    // Allocate memory for words
    words = malloc(MAX_WORDS * sizeof(char **));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    }

    // Get the word from the user
    printf("Enter a word: ");
    scanf("%s", words[word_count]);

    // Increment the word count
    word_count++;

    // Check if the word is already in the dictionary
    for (int i = 0; i < word_count - 1; i++)
    {
        if (strcmp(words[i], words[word_count - 1]) == 0)
        {
            printf("The word %s is already in the dictionary.\n", words[word_count - 1]);
            word_count--;
            break;
        }
    }

    // Add the word to the dictionary
    words[word_count - 1] = malloc(MAX_WORD_LENGTH * sizeof(char));
    scanf("Enter the word: ", words[word_count - 1]);

    // Print the word list
    printf("The word list is:\n");
    for (int i = 0; i < word_count; i++)
    {
        printf("%s\n", words[i]);
    }

    // Free the memory
    for (int i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }
    free(words);

    return 0;
}