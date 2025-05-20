//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word *createWord(char *word, int frequency)
{
    Word *w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = frequency;

    return w;
}

void analyzeSentiment(char *sentence)
{
    Word **words = NULL;
    int numWords = 0;

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token)
    {
        Word *w = createWord(token, 1);
        words = realloc(words, (numWords + 1) * sizeof(Word *));
        words[numWords++] = w;
        token = strtok(NULL, " ");
    }

    // Calculate sentiment
    int sentiment = 0;
    for (int i = 0; i < numWords; i++)
    {
        if (words[i]->word[0] == 'n' || words[i]->word[0] == 'a' || words[i]->word[0] == 'o')
        {
            sentiment++;
        }
    }

    // Print sentiment
    printf("Sentiment: %d\n", sentiment);
}

int main()
{
    analyzeSentiment("I am happy. I am sad.");
    analyzeSentiment("I am angry. I am excited.");

    return 0;
}