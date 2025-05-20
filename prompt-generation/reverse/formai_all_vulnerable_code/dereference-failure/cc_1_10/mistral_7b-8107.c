//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int key) {
    Node *newNode = createNode(key);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->key < key) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int cSearch(Node *head, int target) {
    Node *current = head;
    int position = 0;
    while (current != NULL) {
        if (current->key == target) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

int main() {
    Node *linkedList = NULL;
    int i, num, key;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter %d keys: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &key);
        insertNode(&linkedList, key);
    }

    int searchKey;
    printf("Enter the key to search: ");
    scanf("%d", &searchKey);

    int result = cSearch(linkedList, searchKey);

    if (result != -1) {
        printf("Key %d found at position %d.\n", searchKey, result + 1);
    } else {
        printf("Key %d not found.\n", searchKey);
    }

    return 0;
}