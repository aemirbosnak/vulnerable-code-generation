//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word **createWordList(int size)
{
    Word **words = malloc(size * sizeof(Word));
    for (int i = 0; i < size; i++)
    {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(MAX_WORDS * sizeof(char));
        words[i]->frequency = 0;
    }
    return words;
}

void addWord(Word **words, char *word)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(words[i]->word, word) == 0)
        {
            words[i]->frequency++;
            return;
        }
    }
    Word *newWord = malloc(sizeof(Word));
    newWord->word = malloc(MAX_WORDS * sizeof(char));
    newWord->frequency = 1;
    strcpy(newWord->word, word);
    words[MAX_WORDS - 1] = newWord;
}

int spamDetector(Word **words)
{
    int threshold = 5;
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (words[i]->frequency > threshold)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    Word **words = createWordList(1000);
    addWord(words, "buy");
    addWord(words, "now");
    addWord(words, "free");
    addWord(words, "spam");
    addWord(words, "offers");
    addWord(words, "miracle");
    addWord(words, "get");
    addWord(words, "quick");
    addWord(words, "easy");
    addWord(words, "cheap");

    if (spamDetector(words) == 1)
    {
        printf("Spam detected!");
    }
    else
    {
        printf("No spam detected.");
    }

    return 0;
}