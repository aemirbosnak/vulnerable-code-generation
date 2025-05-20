//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

int main()
{
    char **words = NULL;
    char text[4096];
    int num_words = 0;
    int i = 0;
    int spam_score = 0;
    char *pattern = "money|lottery|prize|free|miracle|miracle|miracle";

    printf("Enter text: ");
    fgets(text, 4096, stdin);

    // Tokenize the text and store the words in an array
    words = tokenize(text);

    // Count the number of words in the text
    num_words = count_words(words);

    // Calculate the spam score based on the number of words and the presence of certain patterns
    spam_score = calculate_spam_score(num_words, words, pattern);

    // Display the spam score
    printf("Spam score: %d\n", spam_score);

    // Free the memory allocated for the words array
    free(words);

    return 0;
}

int tokenize(char *text)
{
    char **words = NULL;
    int i = 0;
    int num_words = 0;

    words = malloc(MAX_WORDS * sizeof(char *));

    // Tokenize the text into words
    char *token = strtok(text, " ");

    // Store the words in the array
    while (token)
    {
        words[num_words++] = strdup(token);
        token = strtok(NULL, " ");
    }

    return words;
}

int count_words(char **words)
{
    int num_words = 0;

    // Count the number of words in the array
    for (int i = 0; words[i] != NULL; i++)
    {
        num_words++;
    }

    return num_words;
}

int calculate_spam_score(int num_words, char **words, char *pattern)
{
    int spam_score = 0;
    char *word_pattern = strchr(pattern, '|');

    // Calculate the spam score based on the number of words and the presence of certain patterns
    if (num_words > 20)
    {
        spam_score++;
    }

    // Iterate over the words and check if they match the pattern
    for (int i = 0; words[i] != NULL; i++)
    {
        if (strstr(words[i], word_pattern))
        {
            spam_score++;
        }
    }

    return spam_score;
}