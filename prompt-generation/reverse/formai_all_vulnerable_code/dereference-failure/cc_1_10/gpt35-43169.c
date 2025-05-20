//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *root = NULL;

void push(int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = root;
    root = new_node;
}

int pop()
{
    if (root == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }

    int data = root->data;
    Node *temp = root;
    root = root->next;
    free(temp);
    return data;
}

void display()
{
    if (root == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    Node *current = root;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}