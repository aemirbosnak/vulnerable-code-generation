//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char *word;
    int frequency;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        WordNode *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

void printWordFrequency(WordNode *head) {
    printf("Word Frequency:\n");
    WordNode *traverse = head;
    while (traverse) {
        printf("%s: %d\n", traverse->word, traverse->frequency);
        traverse = traverse->next;
    }
}

int main() {
    WordNode *head = NULL;
    char *text = "This is a sample text for word frequency counting. The text contains many words, some of them are repeated. The most frequent word is the. The text also contains some uncommon words, such as hippopotamus and rhinoceros. I hope this text is interesting.";

    // Insert words into the linked list
    insertWord(head, "the");
    insertWord(head, "is");
    insertWord(head, "a");
    insertWord(head, "sample");
    insertWord(head, "text");
    insertWord(head, "for");
    insertWord(head, "word");
    insertWord(head, "frequency");
    insertWord(head, "counting");
    insertWord(head, "most");
    insertWord(head, "frequent");
    insertWord(head, "uncommon");
    insertWord(head, "hippopotamus");
    insertWord(head, "rhinoceros");

    // Print word frequency
    printWordFrequency(head);

    return 0;
}