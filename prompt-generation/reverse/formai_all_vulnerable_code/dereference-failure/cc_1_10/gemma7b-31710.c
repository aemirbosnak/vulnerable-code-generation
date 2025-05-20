//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char word[MAX_WORDS];
    struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
    WordNode* newNode = malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    WordNode* head = NULL;

    // Multiplayer game loop
    while (1) {
        // Get the word from the client
        char word[MAX_WORDS];
        printf("Enter a word: ");
        scanf("%s", word);

        // Insert the word into the list
        head = insertWord(head, word);

        // Print the list of words
        printf("List of words: ");
        WordNode* current = head;
        while (current) {
            printf("%s ", current->word);
            current = current->next;
        }

        // Check if the client wants to continue
        char continue_yn;
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &continue_yn);

        // Break out of the loop if the client does not want to continue
        if (continue_yn != 'y') {
            break;
        }
    }

    return 0;
}