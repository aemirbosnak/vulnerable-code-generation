//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

void insertData(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void searchData(Node* head, char data) {
    while (head) {
        if (head->data[0] == data) {
            printf("Data found: %c\n", data);
            return;
        }

        head = head->next;
    }

    printf("Data not found: %c\n", data);
}

int main() {
    Node* head = NULL;

    insertData(head, 'a');
    insertData(head, 'b');
    insertData(head, 'c');
    insertData(head, 'd');

    searchData(head, 'b');
    searchData(head, 'e');

    return 0;
}