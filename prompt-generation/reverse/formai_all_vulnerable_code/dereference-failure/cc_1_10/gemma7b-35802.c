//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    char message[MAX_SIZE];
    char sentiment[MAX_SIZE];
    int i, j, k, score = 0, opponent_score = 0;
    char **words = NULL;

    // Allocate memory for the words array
    words = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        words[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the message from the user
    printf("Enter a message: ");
    fgets(message, MAX_SIZE, stdin);

    // Tokenize the message into words
    j = 0;
    words[j++] = strtok(message, " ");
    while ((words[j] = strtok(NULL, " ")) != NULL)
    {
        j++;
    }

    // Calculate the sentiment of each word
    for (k = 0; k < j; k++)
    {
        score += sentiment_analysis(words[k]);
    }

    // Calculate the overall sentiment of the message
    sentiment[0] = 'A';
    if (score < 0)
    {
        sentiment[0] = 'D';
    }
    else if (score < 5)
    {
        sentiment[0] = 'C';
    }
    else
    {
        sentiment[0] = 'B';
    }

    // Print the sentiment of the message
    printf("The sentiment of your message is: %c\n", sentiment[0]);

    // Free the memory allocated for the words array
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(words[i]);
    }
    free(words);

    return 0;
}

int sentiment_analysis(char *word)
{
    int score = 0;

    // Check if the word is positive or negative
    if (word_is_positive(word))
    {
        score++;
    }
    else if (word_is_negative(word))
    {
        score--;
    }

    // Return the sentiment score
    return score;
}

int word_is_positive(char *word)
{
    char *positive_words[] = {"happy", "joy", "good", "great", "excellent"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, positive_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int word_is_negative(char *word)
{
    char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, negative_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}