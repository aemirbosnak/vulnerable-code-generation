//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int countWords(WordNode *head) {
    int count = 0;
    WordNode *current = head;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    WordNode *head = NULL;
    char *word;

    printf("Enter a word: ");
    scanf("%s", word);

    insertWord(head, word);

    printf("Enter another word: ");
    scanf("%s", word);

    insertWord(head, word);

    printf("Total number of words: %d", countWords(head));

    return 0;
}