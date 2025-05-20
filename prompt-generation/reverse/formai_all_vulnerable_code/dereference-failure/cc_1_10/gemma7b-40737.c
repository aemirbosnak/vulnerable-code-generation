//Gemma-7B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 10

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

Node* head = NULL;

void* alloc(int size)
{
    if (head == NULL)
    {
        head = malloc(sizeof(Node));
        head->next = NULL;
        head->data = malloc(size);
    }
    else
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = head;
        head = newNode;
        newNode->data = malloc(size);
    }

    return head->data;
}

void free(void* ptr)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data == ptr)
        {
            free(temp->data);
            free(temp);
            head = temp->next;
            break;
        }
        temp = temp->next;
    }
}

int main()
{
    alloc(20);
    alloc(30);
    alloc(40);

    free(alloc(10));
    free(alloc(20));

    return 0;
}