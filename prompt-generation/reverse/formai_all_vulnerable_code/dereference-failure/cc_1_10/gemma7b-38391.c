//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int search(struct Node* head, char target) {
    while (head) {
        if (head->data == target) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    struct Node* head = NULL;

    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    if (search(head, 'c') == 1) {
        printf("Target found!\n");
    } else {
        printf("Target not found.\n");
    }

    return 0;
}