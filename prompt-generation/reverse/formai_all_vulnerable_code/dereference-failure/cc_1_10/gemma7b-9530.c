//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char **words = NULL;
    char sentence[200];
    int word_count = 0;
    int sentiment = 0;

    // Allocate memory for words
    words = (char**)malloc(MAX_WORDS * sizeof(char*));

    // Get the sentence
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token)
    {
        // Add the word to the words array
        words[word_count] = strdup(token);
        word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment
    for (int i = 0; i < word_count; i++)
    {
        // Check if the word is positive or negative
        if (words[i][0] == 'p' || words[i][0] == 'a' || words[i][0] == 'e')
        {
            sentiment++;
        }
        else if (words[i][0] == 'n' || words[i][0] == 'o' || words[i][0] == 's')
        {
            sentiment--;
        }
    }

    // Print the sentiment
    printf("The sentiment of the sentence is: %d\n", sentiment);

    // Free the memory
    free(words);

    return 0;
}