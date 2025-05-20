//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insert(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void search(Node* head, char target) {
    while (head) {
        if (head->data == target) {
            printf("Target found!\n");
            return;
        } else if (head->next) {
            head = head->next;
        } else {
            printf("Target not found.\n");
            return;
        }
    }
}

int main() {
    Node* head = NULL;
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');

    search(head, 'c');

    return 0;
}