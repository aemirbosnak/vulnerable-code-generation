//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
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

void printWordFrequency(WordNode *head) {
    WordNode *currNode = head;
    int wordCount = 0;
    char **wordList = NULL;

    while (currNode) {
        wordCount++;
        if (wordList == NULL) {
            wordList = malloc(sizeof(char *) * wordCount);
        }
        wordList[wordCount - 1] = currNode->word;
        currNode = currNode->next;
    }

    printf("Word frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        int frequency = 0;
        WordNode *iterNode = head;
        while (iterNode) {
            if (strcmp(iterNode->word, wordList[i]) == 0) {
                frequency++;
            }
            iterNode = iterNode->next;
        }
        printf("%s: %d\n", wordList[i], frequency);
    }

    free(wordList);
}

int main() {
    WordNode *head = NULL;
    char *text = "This is a sample text for word frequency counting. It contains many words, some of them are repeated. The repeated words should be counted accurately.";

    insertWord(head, text);
    printWordFrequency(head);

    return 0;
}