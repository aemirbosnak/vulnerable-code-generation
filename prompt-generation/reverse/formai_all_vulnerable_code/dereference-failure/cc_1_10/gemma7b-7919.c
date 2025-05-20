//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    char text[MAX];
    printf("Enter text: ");
    fgets(text, MAX, stdin);

    // Create an array of words
    char **words = NULL;
    int num_words = 0;
    words = split_text(text, &num_words);

    // Count the frequency of each word
    int word_freq[num_words];
    for (int i = 0; i < num_words; i++)
    {
        word_freq[i] = count_words(words[i]);
    }

    // Print the word frequency
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++)
    {
        printf("%s: %d\n", words[i], word_freq[i]);
    }

    // Free the memory allocated for words
    free(words);

    return 0;
}

int split_text(char *text, int *num_words)
{
    char **words = NULL;
    *num_words = 0;

    // Split the text into words
    char *word = strtok(text, " ");
    while (word)
    {
        words = realloc(words, (*num_words + 1) * sizeof(char *));
        words[*num_words] = strdup(word);
        (*num_words)++;
        word = strtok(NULL, " ");
    }

    return words;
}

int count_words(char *word)
{
    int count = 0;

    // Iterate over the text and count the occurrences of the word
    char *text = "The quick brown fox jumps over the lazy dog.";
    char *ptr = text;
    while (ptr)
    {
        if (strcmp(word, ptr) == 0)
        {
            count++;
        }
        ptr++;
    }

    return count;
}