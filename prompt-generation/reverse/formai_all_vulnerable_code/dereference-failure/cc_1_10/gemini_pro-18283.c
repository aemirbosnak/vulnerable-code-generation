//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *createNode(char *word) {
    Node *node = malloc(sizeof(Node));
    node->word = strdup(word);
    node->next = NULL;
    return node;
}

void insertNode(Node **head, Node *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

int findNode(Node *head, char *word) {
    while (head != NULL) {
        if (strcmp(head->word, word) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s dictionary words...\n", argv[0]);
        return 1;
    }

    // Build a hash table of the dictionary words
    Node *head = NULL;
    for (int i = 1; i < argc; i++) {
        Node *node = createNode(argv[i]);
        insertNode(&head, node);
    }

    // Check the spelling of the input words
    char word[MAX_WORD_LEN];
    while (scanf("%s", word) != EOF) {
        if (!findNode(head, word)) {
            printf("%s: not found\n", word);
        }
    }

    // Free the hash table
    freeList(head);

    return 0;
}