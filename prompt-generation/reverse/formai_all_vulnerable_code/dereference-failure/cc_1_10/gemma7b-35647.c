//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct Word
{
    char *word;
    int frequency;
    struct Word *next;
} Word;

typedef struct Sentence
{
    char *sentence;
    Word **words;
    struct Sentence *next;
} Sentence;

void AnalyzeSentiment(Sentence *sentence)
{
    Word *word = sentence->words;
    int positive_words = 0;
    int negative_words = 0;
    int neutral_words = 0;

    while (word)
    {
        if (strcmp(word->word, "positive") == 0)
        {
            positive_words++;
        }
        else if (strcmp(word->word, "negative") == 0)
        {
            negative_words++;
        }
        else if (strcmp(word->word, "neutral") == 0)
        {
            neutral_words++;
        }
        word = word->next;
    }

    printf("Sentiment analysis of the sentence:\n");
    printf("Positive words: %d\n", positive_words);
    printf("Negative words: %d\n", negative_words);
    printf("Neutral words: %d\n", neutral_words);
}

int main()
{
    Sentence *sentence = malloc(sizeof(Sentence));
    sentence->sentence = malloc(MAX_SENTENCE_LENGTH);
    sentence->words = NULL;

    printf("Enter a sentence: ");
    getline(sentence->sentence, MAX_SENTENCE_LENGTH, stdin);

    AnalyzeSentiment(sentence);

    free(sentence->sentence);
    free(sentence);

    return 0;
}