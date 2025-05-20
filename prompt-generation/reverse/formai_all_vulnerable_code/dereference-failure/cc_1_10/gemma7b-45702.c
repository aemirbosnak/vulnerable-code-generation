//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

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
        WordNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

int main() {
    WordNode* head = NULL;

    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char* words[] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    for (int i = 0; i < 9; i++) {
        insertWord(head, words[i]);
    }

    WordNode* current = head;

    while (current) {
        printf("%s: %d\n", current->word, current->frequency);
        current = current->next;
    }

    return 0;
}