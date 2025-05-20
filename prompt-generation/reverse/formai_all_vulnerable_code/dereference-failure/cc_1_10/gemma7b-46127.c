//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
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
    Word *words;
    struct Sentence *next;
} Sentence;

Sentence *createSentence(char *sentence)
{
    Sentence *newSentence = malloc(sizeof(Sentence));
    newSentence->sentence = strdup(sentence);
    newSentence->words = NULL;
    newSentence->next = NULL;

    return newSentence;
}

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;
    newWord->next = NULL;

    return newWord;
}

void addWordToSentence(Sentence *sentence, Word *word)
{
    Word *existingWord = sentence->words;

    if (existingWord == NULL)
    {
        sentence->words = word;
    }
    else
    {
        while (existingWord->next)
        {
            existingWord = existingWord->next;
        }

        existingWord->next = word;
    }
}

void analyzeSentiment(Sentence *sentence)
{
    Word *words = sentence->words;

    for (words = sentence->words; words; words = words->next)
    {
        printf("%s ", words->word);
    }

    printf("\n");

    int sentiment = 0;

    for (words = sentence->words; words; words = words->next)
    {
        if (words->word[0] == 'N' || words->word[0] == 'S' || words->word[0] == 'P')
        {
            sentiment++;
        }
    }

    printf("Sentiment score: %d\n", sentiment);
}

int main()
{
    Sentence *sentence = createSentence("The quick brown fox jumps over the lazy dog.");

    addWordToSentence(sentence, createWord("The"));
    addWordToSentence(sentence, createWord("quick"));
    addWordToSentence(sentence, createWord("brown"));
    addWordToSentence(sentence, createWord("fox"));
    addWordToSentence(sentence, createWord("jumps"));
    addWordToSentence(sentence, createWord("over"));
    addWordToSentence(sentence, createWord("lazy"));
    addWordToSentence(sentence, createWord("dog"));

    analyzeSentiment(sentence);

    return 0;
}