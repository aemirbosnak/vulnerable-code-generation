//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        WordNode *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void printWordFrequency(WordNode *head) {
    printf("Word frequency:\n");
    WordNode *current = head;
    while (current) {
        printf("%s: %d\n", current->word, current->frequency);
        current = current->next;
    }
}

int main() {
    WordNode *head = NULL;

    // Get the words from the two players
    char player1Word[20];
    printf("Player 1, enter your word: ");
    scanf("%s", player1Word);
    insertWord(head, player1Word);

    char player2Word[20];
    printf("Player 2, enter your word: ");
    scanf("%s", player2Word);
    insertWord(head, player2Word);

    // Print the word frequency
    printWordFrequency(head);

    return 0;
}