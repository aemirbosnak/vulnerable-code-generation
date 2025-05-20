//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    int score;
    struct Word *next;
} Word;

Word *head = NULL;

void addWord(char *word, int score)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->score = score;
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        Word *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newWord;
    }
}

int checkWord(char *word)
{
    Word *temp = head;
    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
        {
            return temp->score;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    addWord("apple", 5);
    addWord("banana", 6);
    addWord("orange", 4);

    char wordToCheck[20];

    printf("Enter a word: ");
    scanf("%s", wordToCheck);

    int score = checkWord(wordToCheck);

    if (score > 0)
    {
        printf("Score: %d\n", score);
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}