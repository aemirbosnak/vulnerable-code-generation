//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word **createWordList(char *text)
{
    Word **words = (Word **)malloc(sizeof(Word *) * MAX_WORDS);
    int i = 0;
    char *word = NULL;
    for (int j = 0; text[j] != '\0'; j++)
    {
        if (word == NULL)
        {
            word = (char *)malloc(sizeof(char) * 20);
            words[i] = (Word *)malloc(sizeof(Word));
            words[i]->word = word;
            words[i]->frequency = 0;
            i++;
        }
        else if (text[j] == ' ')
        {
            words[i]->frequency++;
            word = NULL;
        }
        else
        {
            word[strlen(word)] = text[j];
            word[strlen(word) + 1] = '\0';
        }
    }
    return words;
}

int main()
{
    char *text = "This is a sample text that I am using to demonstrate a sentiment analysis tool.";
    Word **words = createWordList(text);

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    return 0;
}