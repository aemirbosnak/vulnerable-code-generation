//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str)
{
    int i = 0, wordCount = 0;
    char *word = NULL;

    // Iterate over the string
    for (i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is a word boundary
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            // If the word is not NULL, increment the word count
            if (word)
            {
                wordCount++;
            }

            // Allocate memory for the next word
            word = malloc(20);

            // Copy the character into the word
            word[0] = str[i];

            // Initialize the rest of the word to NULL
            word[1] = '\0';
        }
        else
        {
            // Append the character to the word
            word[i - 1] = str[i];
        }
    }

    // Check if the last word is complete
    if (word)
    {
        wordCount++;
    }

    return wordCount;
}

int main()
{
    char str[] = "This is a sample string with many words.";

    int wordCount = countWords(str);

    printf("The number of words in the string is: %d", wordCount);

    return 0;
}