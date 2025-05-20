//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char word[MAX_WORDS];
    int frequency;
    struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
    WordNode* newNode = malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        WordNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void countWords(WordNode* head) {
    WordNode* current = head;
    while (current) {
        current->frequency++;
        current = current->next;
    }
}

int main() {
    WordNode* head = NULL;
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, text);
    countWords(head);

    WordNode* wordNode = head;
    while (wordNode) {
        printf("%s: %d\n", wordNode->word, wordNode->frequency);
        wordNode = wordNode->next;
    }

    return 0;
}