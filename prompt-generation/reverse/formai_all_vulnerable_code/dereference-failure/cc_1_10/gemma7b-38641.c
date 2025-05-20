//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog, the quick brown fox jumps over the lazy dog, the quick brown fox jumps over the lazy dog";
    char *word;
    int i = 0, word_count = 0, frequency[100] = {0};

    // Allocate memory for the word pointer
    word = (char *)malloc(100);

    // Loop through the string to find words
    while (str[i] != '\0')
    {
        // Check if the current character is the start of a word
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Start collecting words
            word[word_count] = str[i];
            word_count++;

            // Continue collecting words until a space is found or the end of the string is reached
            while (str[i] != ' ' && str[i] != '\0')
            {
                i++;
                word[word_count] = str[i];
                word_count++;
            }

            // Increment the frequency of the word
            frequency[word_count - 1]++;
        }

        // Increment the index
        i++;
    }

    // Print the word frequencies
    for (i = 0; i < word_count; i++)
    {
        printf("%s: %d\n", word[i], frequency[i]);
    }

    // Free the allocated memory
    free(word);

    return 0;
}