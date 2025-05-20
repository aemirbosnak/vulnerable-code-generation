//Gemma-7B DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a macro for readability
#define MAX 1024

// Function to calculate the frequency of a word in a text
int word_frequency(char *text, char *word)
{
    int i = 0, count = 0;
    char *ptr = text;

    // Iterate over the text
    while (ptr[i] != '\0')
    {
        // Check if the word is the same as the current word
        if (strcmp(word, ptr + i) == 0)
        {
            // Increment the word frequency
            count++;
        }

        // Move to the next character
        i++;
    }

    // Return the word frequency
    return count;
}

// Function to find the most frequent words in a text
void find_most_frequent_words(char *text, int n)
{
    char *words[n];
    int frequency[n];
    int i, j, max_frequency = 0;

    // Calculate the frequency of each word
    for (i = 0; i < n; i++)
    {
        words[i] = malloc(20);
        strcpy(words[i], text);
        frequency[i] = word_frequency(text, words[i]);
    }

    // Find the most frequent words
    for (i = 0; i < n; i++)
    {
        if (frequency[i] > max_frequency)
        {
            max_frequency = frequency[i];
        }
    }

    // Print the most frequent words
    printf("The most frequent words in the text are:\n");
    for (i = 0; i < n; i++)
    {
        if (frequency[i] == max_frequency)
        {
            printf("%s - %d\n", words[i], frequency[i]);
        }
    }
}

int main()
{
    char text[] = "This is a sample text. It contains many words. The most frequent words are the, is, a, and of.";
    int n = 10;

    find_most_frequent_words(text, n);

    return 0;
}