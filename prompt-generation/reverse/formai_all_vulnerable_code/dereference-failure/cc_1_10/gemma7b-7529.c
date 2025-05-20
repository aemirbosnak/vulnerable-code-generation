//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    char item[MAX];
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item[0] = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void traverse(Node* head)
{
    Node* current = head;

    while (current) {
        printf("%s ", current->item);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');

    traverse(head);

    return 0;
}