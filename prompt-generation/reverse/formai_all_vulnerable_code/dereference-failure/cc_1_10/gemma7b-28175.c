//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 255

typedef struct Word
{
    char *word;
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
    newWord->next = NULL;
    return newWord;
}

void addWordToSentence(Sentence *sentence, Word *word)
{
    Word *newWord = createWord(word->word);
    if (sentence->words == NULL)
    {
        sentence->words = newWord;
    }
    else
    {
        sentence->words->next = newWord;
    }
}

void freeSentence(Sentence *sentence)
{
    free(sentence->sentence);
    free(sentence->words);
    free(sentence);
}

int main()
{
    time_t start, end;
    char **sentences = malloc(MAX_WORDS * MAX_SENTENCE_LENGTH);
    for (int i = 0; i < MAX_WORDS; i++)
    {
        sentences[i] = malloc(MAX_SENTENCE_LENGTH);
    }

    for (int i = 0; i < MAX_WORDS; i++)
    {
        sentences[i] = "The quick brown fox jumps over the lazy dog.";
    }

    start = time(NULL);
    for (int i = 0; i < MAX_WORDS; i++)
    {
        Sentence *sentence = createSentence(sentences[i]);
        freeSentence(sentence);
    }
    end = time(NULL);

    printf("Time taken: %f seconds\n", end - start);

    return 0;
}