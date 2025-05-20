//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

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
        WordNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

int countWords(WordNode *head) {
    int count = 0;
    WordNode *temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    WordNode *head = NULL;
    char text[] = "This is a sample text. It has many words. Some words are repeated. The quick brown fox jumps over the lazy dog.";

    insertWord(head, text);

    int wordCount = countWords(head);
    printf("Number of words in the text: %d\n", wordCount);

    return 0;
}