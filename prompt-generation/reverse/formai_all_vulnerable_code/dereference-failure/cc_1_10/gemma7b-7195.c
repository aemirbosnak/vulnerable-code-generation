//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word)
{
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

int main()
{
    Word* wordList = NULL;
    char* sentence = "This is a spam email with lots of garbage words and some important information.";

    // Tokenize the sentence and insert each word into the list
    char* word = strtok(sentence, " ");
    while (word)
    {
        insertWord(wordList, word);
        word = strtok(NULL, " ");
    }

    // Create a blacklist of suspicious words
    char* blacklist[] = {"spam", "junk", "garbage", "lottery", "free", "miracle"};

    // Check if each word in the sentence is on the blacklist
    for (int i = 0; i < 6; i++)
    {
        Word* currentWord = wordList;
        while (currentWord)
        {
            if (strcmp(currentWord->word, blacklist[i]) == 0)
            {
                printf("Word %s is on the blacklist.\n", currentWord->word);
            }
            currentWord = currentWord->next;
        }
    }

    return 0;
}