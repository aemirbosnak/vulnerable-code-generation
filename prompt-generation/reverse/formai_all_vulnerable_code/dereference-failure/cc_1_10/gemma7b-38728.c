//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 100

int main()
{
    setlocale(LC_ALL, "");

    char text[1000] = "The quick brown fox jumps over the lazy dog. The early bird gets the worm, but the worm is not a very smart worm.";
    char **words = NULL;
    int num_words = 0;

    // Tokenize the text
    words = tokenize(text, &num_words);

    // Analyze the sentiment of each word
    for (int i = 0; i < num_words; i++)
    {
        int sentiment = analyze_sentiment(words[i]);

        // Print the word and its sentiment
        printf("%s - %d\n", words[i], sentiment);
    }

    // Free the memory allocated for words
    free(words);

    return 0;
}

int tokenize(char *text, int *num_words)
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

int analyze_sentiment(char *word)
{
    // Sentiment dictionary
    int sentiment_dict[] = {
        -1,  // Negative
        0,   // Neutral
        1,   // Positive
    };

    // Check if the word is in the sentiment dictionary
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(word, sentiment_dict[i]) == 0)
        {
            return sentiment_dict[i];
        }
    }

    // Return neutral if the word is not in the dictionary
    return 0;
}