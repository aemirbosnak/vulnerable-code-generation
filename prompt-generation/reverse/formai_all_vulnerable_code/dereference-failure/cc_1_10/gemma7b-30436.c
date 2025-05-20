//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word *createWord(char *word)
{
    Word *w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = 0;
    return w;
}

void addWord(Word *w, char *word)
{
    if (strcmp(w->word, word) == 0)
    {
        w->frequency++;
    }
    else
    {
        w = createWord(word);
        w->frequency = 1;
        // Add w to the list of words
    }
}

int main()
{
    char text[] = "This is a sample text. It contains a lot of words. Some words are repeated. The most frequent word is the word 'a'.";

    Word *words = NULL;

    addWord(words, "a");
    addWord(words, "is");
    addWord(words, "sample");
    addWord(words, "text");
    addWord(words, "a");

    printf("The most frequent word is: %s", words->word);
    printf("\nThe frequency of the word 'a' is: %d", words->frequency);

    return 0;
}