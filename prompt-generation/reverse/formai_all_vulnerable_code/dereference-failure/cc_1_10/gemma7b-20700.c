//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

void insertNode(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

int searchIndex(Node* head, char data) {
    while (head) {
        if (head->data[0] == data) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;

    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'c');
    insertNode(head, 'd');
    insertNode(head, 'e');

    if (searchIndex(head, 'b') == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}