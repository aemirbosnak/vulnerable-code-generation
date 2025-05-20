//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS] = "I am happy today. The sun is shining and the flowers are blooming.";
    char words[MAX_WORDS][20];
    int num_words = 0;

    // Tokenize the text
    char *ptr = text;
    while (ptr)
    {
        char *word = strtok(ptr, " ");
        if (word)
        {
            strcpy(words[num_words], word);
            num_words++;
        }
        ptr = NULL;
    }

    // Analyze the sentiment of each word
    int sentiment[num_words];
    for (int i = 0; i < num_words; i++)
    {
        sentiment[i] = analyze_sentiment(words[i]);
    }

    // Print the sentiment of the text
    for (int i = 0; i < num_words; i++)
    {
        printf("%s: %d\n", words[i], sentiment[i]);
    }

    return 0;
}

int analyze_sentiment(char *word)
{
    // Sentiment dictionary
    int sentiment_dict[] = {
        0, // Neutral
        1, // Positive
        -1 // Negative
    };

    // Check if the word is in the sentiment dictionary
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(word, sentiment_dict[i]) == 0)
        {
            return sentiment_dict[i];
        }
    }

    // If the word is not in the dictionary, return neutral
    return 0;
}