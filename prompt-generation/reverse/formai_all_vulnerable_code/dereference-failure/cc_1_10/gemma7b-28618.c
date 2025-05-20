//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char word[MAX_WORDS];
    struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int countWords(WordNode* head) {
    int count = 0;
    WordNode* current = head;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    WordNode* head = NULL;
    char word[MAX_WORDS];

    printf("Enter a word: ");
    scanf("%s", word);
    insertWord(head, word);

    printf("Enter another word: ");
    scanf("%s", word);
    insertWord(head, word);

    printf("Number of words: %d", countWords(head));

    return 0;
}