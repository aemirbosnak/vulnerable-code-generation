//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro to count the frequency of a word
#define countWord(word, text) (text) ? strstr(text, word) : 0

// Define a function to print the word frequency
void printWordFrequency(char *text)
{
    // Create a dictionary to store the word frequency
    int **wordFreq = malloc(sizeof(int *) * 100);
    for (int i = 0; i < 100; i++)
    {
        wordFreq[i] = NULL;
    }

    // Tokenize the text
    char *token = strtok(text, " ");

    // Iterate over the tokens
    while (token)
    {
        // Count the frequency of each word
        int wordFreqIndex = countWord(token, text);
        if (wordFreqIndex)
        {
            if (wordFreq[wordFreqIndex] == NULL)
            {
                wordFreq[wordFreqIndex] = 1;
            }
            else
            {
                wordFreq[wordFreqIndex]++;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the word frequency
    printf("Word frequency:\n");
    for (int i = 0; wordFreq[i] != NULL; i++)
    {
        printf("%s: %d\n", wordFreq[i], wordFreq[i]);
    }

    // Free the memory allocated for the dictionary
    free(wordFreq);
}

int main()
{
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    printWordFrequency(text);

    return 0;
}