//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insert(int data)
{
    Node* node = createNode(data);
    if (head == NULL)
    {
        head = node;
        return head;
    }
    Node* current = head;
    while (current->next!= NULL)
    {
        current = current->next;
    }
    current->next = node;
    return head;
}

void printList()
{
    Node* current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    printList();
    return 0;
}