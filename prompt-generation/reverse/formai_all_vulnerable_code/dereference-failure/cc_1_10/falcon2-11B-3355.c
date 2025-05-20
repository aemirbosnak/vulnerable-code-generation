//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create_node(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *add_node_to_tail(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        while (current->next!= NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    add_node_to_tail(head, 1);
    add_node_to_tail(head, 2);
    add_node_to_tail(head, 3);
    print_list(head);
    return 0;
}