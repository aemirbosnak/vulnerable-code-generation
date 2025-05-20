//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* InsertAtTail(struct Node* head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void Traverse(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = InsertAtTail(head, 'a');
    head = InsertAtTail(head, 'b');
    head = InsertAtTail(head, 'c');
    head = InsertAtTail(head, 'd');
    Traverse(head);

    // Compression
    struct Node* compressedHead = NULL;
    struct Node* current = head;
    char previous = '\0';
    int count = 0;
    while (current) {
        if (current->data == previous) {
            count++;
        } else {
            if (previous != '\0') {
                InsertAtTail(compressedHead, count);
            }
            previous = current->data;
            count = 1;
        }
        current = current->next;
    }

    Traverse(compressedHead);

    return 0;
}