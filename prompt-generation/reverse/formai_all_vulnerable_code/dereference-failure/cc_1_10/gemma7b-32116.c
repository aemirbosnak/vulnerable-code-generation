//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word *createWord(char *word)
{
    Word *wordStruct = malloc(sizeof(Word));
    wordStruct->word = strdup(word);
    wordStruct->frequency = 1;
    return wordStruct;
}

void addWord(Word *wordList, char *word)
{
    Word *newWord = createWord(word);
    wordList->frequency++;
    wordList->word = realloc(wordList->word, (wordList->frequency) * MAX_WORDS);
    wordList->word = realloc(newWord->word, MAX_WORDS);
    wordList->word[wordList->frequency - 1] = newWord->word;
}

int main()
{
    Word *wordList = malloc(sizeof(Word) * MAX_WORDS);
    wordList->word = NULL;

    char *text = "This is a sample text with many words. The words are repeated many times. Some words are unique, but most are not.";

    char *words[] = {"the", "is", "a", "sample", "text", "with", "many", "words", "are", "repeated", "many", "times", "some", "words", "are", "unique", "but", "most", "are", "not"};

    for (int i = 0; i < 13; i++)
    {
        addWord(wordList, words[i]);
    }

    printf("Word list:\n");
    for (int i = 0; i < wordList->frequency; i++)
    {
        printf("%s - %d\n", wordList->word[i], wordList->frequency);
    }

    free(wordList);
    return 0;
}