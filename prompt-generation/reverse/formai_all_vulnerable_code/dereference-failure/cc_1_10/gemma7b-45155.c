//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 20

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode **createWordList() {
    WordNode **head = malloc(sizeof(WordNode *));
    *head = NULL;
    return head;
}

void addWordToWordList(WordNode **head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next)->next = newNode;
        *head = (*head)->next;
    }
}

int findWord(WordNode **head, char *word) {
    for (WordNode *node = *head; node; node = node->next) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    WordNode **wordList = createWordList();

    addWordToWordList(wordList, "apple");
    addWordToWordList(wordList, "banana");
    addWordToWordList(wordList, "cherry");
    addWordToWordList(wordList, "orange");
    addWordToWordList(wordList, "peach");
    addWordToWordList(wordList, "apricot");

    if (findWord(wordList, "apple") == 1) {
        printf("Apple found!\n");
    }

    if (findWord(wordList, "banana") == 1) {
        printf("Banana found!\n");
    }

    return 0;
}