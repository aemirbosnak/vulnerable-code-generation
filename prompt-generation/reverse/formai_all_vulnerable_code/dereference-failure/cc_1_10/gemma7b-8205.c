//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 255

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    WordNode *traversingNode = head;
    while (traversingNode->next) {
        traversingNode = traversingNode->next;
    }

    traversingNode->next = newNode;
    return head;
}

void printWordFrequency(WordNode *head) {
    WordNode *traversingNode = head;
    int frequency = 0;

    while (traversingNode) {
        char *word = traversingNode->word;
        frequency = 0;

        for (WordNode *comparisonNode = head; comparisonNode; comparisonNode = comparisonNode->next) {
            if (strcmp(word, comparisonNode->word) == 0) {
                frequency++;
            }
        }

        printf("%s: %d\n", word, frequency);
        traversingNode = traversingNode->next;
    }
}

int main() {
    WordNode *head = NULL;
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, "quick");
    insertWord(head, "brown");
    insertWord(head, "fox");
    insertWord(head, "jumps");
    insertWord(head, "lazy");
    insertWord(head, "over");

    printWordFrequency(head);

    return 0;
}