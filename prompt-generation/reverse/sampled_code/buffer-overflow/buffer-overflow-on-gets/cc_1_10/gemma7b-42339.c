//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
    char str[MAX_WORDS][256];
    int i, j, k, word_count = 0, word_length = 0;
    char word[MAX_WORDS][256];

    printf("Welcome to the Word Frequency Counter!\n");

    // Get the user input
    printf("Please enter a sentence: ");
    gets(str[word_count]);

    // Calculate the number of words in the sentence
    for (i = 0; str[word_count][i] != '\0'; i++)
    {
        if (str[word_count][i] == ' ')
        {
            word_count++;
        }
    }

    // Store the words in an array
    for (i = 0; i < word_count; i++)
    {
        word_length = 0;
        for (j = 0; str[word_count][j] != ' '; j++)
        {
            word[i][word_length] = str[word_count][j];
            word_length++;
        }
        word[i][word_length] = '\0';
    }

    // Calculate the frequency of each word
    for (i = 0; i < word_count; i++)
    {
        int frequency = 0;
        for (j = 0; j < word_count; j++)
        {
            if (strcmp(word[i], word[j]) == 0)
            {
                frequency++;
            }
        }
        printf("%s occurs %d times.\n", word[i], frequency);
    }

    return 0;
}