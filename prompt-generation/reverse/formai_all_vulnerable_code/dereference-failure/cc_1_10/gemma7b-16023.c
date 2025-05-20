//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This is a sample text for word frequency counting.";
    char word[20];
    int i, word_count = 0, frequency[20] = {0};

    // Tokenize the text into words
    word_count = tokenize(str, word);

    // Count the frequency of each word
    for (i = 0; i < word_count; i++)
    {
        frequency[word[i]]++;
    }

    // Print the word frequency
    for (i = 0; i < 20; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%s: %d\n", word[i], frequency[i]);
        }
    }

    return 0;
}

int tokenize(char *str, char *word)
{
    int i = 0, word_count = 0;

    // Split the text into words
    while (str[i] != '\0')
    {
        char word_start = str[i];
        i++;

        // Check if the word is complete
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '.')
        {
            word[word_count] = str[i];
            i++;
            word_count++;
        }

        // Increment the word count
        word_count++;

        // Null-terminate the word
        word[word_count] = '\0';
    }

    return word_count;
}