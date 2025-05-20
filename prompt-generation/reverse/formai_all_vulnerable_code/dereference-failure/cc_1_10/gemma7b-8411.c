//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Paranoiac linked list operations
struct node {
    int data;
    struct node* next;
    struct node* prev;
    struct node* paranoid_next;
    struct node* paranoid_prev;
};

struct node* insert_at_tail(struct node* head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->paranoid_next = NULL;
    new_node->paranoid_prev = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node* tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new_node;
    }

    return head;
}

struct node* delete_from_tail(struct node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    free(tail);
    tail = NULL;

    return head;
}

int main()
{
    struct node* head = NULL;
    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_tail(head, 40);

    delete_from_tail(head);

    struct node* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}