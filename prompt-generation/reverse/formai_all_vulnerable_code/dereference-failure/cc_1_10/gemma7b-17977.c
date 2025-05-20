//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    char key[MAX_SIZE];
    int hash;
    struct Index* next;
};

void insert(struct Index** head, char* key, int hash) {
    struct Index* newNode = malloc(sizeof(struct Index));
    strcpy(newNode->key, key);
    newNode->hash = hash;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int search(struct Index* head, char* key) {
    while (head) {
        if (strcmp(key, head->key) == 0) {
            return head->hash;
        }
        head = head->next;
    }

    return -1;
}

int main() {
    struct Index* head = NULL;
    insert(&head, "John Doe", 12);
    insert(&head, "Jane Doe", 24);
    insert(&head, "Peter Pan", 36);

    int hash = search(head, "Jane Doe");
    if (hash != -1) {
        printf("Hash of Jane Doe: %d\n", hash);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}