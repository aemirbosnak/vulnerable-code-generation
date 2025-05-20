//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

struct Word
{
    char *word;
    struct Word *next;
};

struct Word **createWordList()
{
    struct Word **head = malloc(sizeof(struct Word *));
    *head = NULL;
    return head;
}

void addWord(struct Word **head, char *word)
{
    struct Word *newNode = malloc(sizeof(struct Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

int spellCheck(struct Word **head, char *word)
{
    struct Word *currWord = *head;

    while (currWord)
    {
        if (strcmp(currWord->word, word) == 0)
        {
            return 1;
        }
        currWord = currWord->next;
    }

    return 0;
}

int main()
{
    struct Word **wordList = createWordList();

    addWord(wordList, "apple");
    addWord(wordList, "banana");
    addWord(wordList, "orange");
    addWord(wordList, "grape");

    char *wordToSearch = "apple";

    if (spellCheck(wordList, wordToSearch))
    {
        printf("Word found: %s\n", wordToSearch);
    }
    else
    {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}