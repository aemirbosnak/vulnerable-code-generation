//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word)
{
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

void printWordFrequency(WordNode *head)
{
    WordNode *current = head;
    int frequency = 0;
    char *word;

    while (current) {
        word = current->word;
        frequency = 0;

        while (current) {
            if (strcmp(word, current->word) == 0) {
                frequency++;
            }
            current = current->next;
        }

        printf("%s: %d\n", word, frequency);
        current = head;
    }
}

int main()
{
    WordNode *head = NULL;
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, "the");
    insertWord(head, "quick");
    insertWord(head, "brown");
    insertWord(head, "fox");
    insertWord(head, "jumps");
    insertWord(head, "lazy");
    insertWord(head, "over");
    insertWord(head, "dog");

    printWordFrequency(head);

    return 0;
}