//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int sentiment_analysis(char *sentence)
{
    int i, sentiment = 0, word_count = 0;
    char word[MAX];

    // Tokenize the sentence
    sentence = strtok(sentence, " ");

    // Iterate over the tokens
    while (sentence)
    {
        // Remove punctuation and convert to lowercase
        word[0] = toupper(sentence[0]);
        word[1] = '\0';

        // Check if the word is a sentiment word
        if (strcmp(word, "happy") == 0 || strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0)
        {
            // Increment the sentiment score
            sentiment++;
        }

        // Increment the word count
        word_count++;

        // Get the next token
        sentence = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    sentiment = sentiment / word_count;

    return sentiment;
}

int main()
{
    char sentence[MAX];

    // Get the sentence from the user
    printf("Enter a sentence: ");
    getline(stdin, sentence, MAX);

    // Analyze the sentiment of the sentence
    int sentiment = sentiment_analysis(sentence);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment);

    return 0;
}