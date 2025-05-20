//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORDS 1024
#define MAX_SENTENCE_LENGTH 2048

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int main()
{
    Word *wordHead = insertWord(NULL, "spam");
    wordHead = insertWord(wordHead, "eggs");
    wordHead = insertWord(wordHead, "ham");
    wordHead = insertWord(wordHead, "bacon");

    char sentence[MAX_SENTENCE_LENGTH] = "The quick brown fox jumps over the lazy dog. The spam, eggs, and ham are delicious.";

    int sentenceLength = strlen(sentence);

    for (int i = 0; i < sentenceLength; i++)
    {
        char word[MAX_WORDS];

        word[0] = sentence[i];

        Word *wordSearch = wordHead;

        while (wordSearch)
        {
            if (strcmp(word, wordSearch->word) == 0)
            {
                printf("Spam detected at position %d.\n", i);
                break;
            }

            wordSearch = wordSearch->next;
        }
    }

    return 0;
}