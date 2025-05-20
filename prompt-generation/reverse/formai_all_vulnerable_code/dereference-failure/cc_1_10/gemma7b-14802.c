//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

void searchIndex(Node* head, int target) {
    Node* traverse = head;
    while (traverse) {
        if (traverse->index == target) {
            printf("Index found: %d\n", traverse->index);
            return;
        }
        traverse = traverse->next;
    }

    printf("Index not found.\n");
}

int main() {
    Node* head = NULL;

    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    insertNode(head, 50);

    searchIndex(head, 20);
    searchIndex(head, 60);

    return 0;
}