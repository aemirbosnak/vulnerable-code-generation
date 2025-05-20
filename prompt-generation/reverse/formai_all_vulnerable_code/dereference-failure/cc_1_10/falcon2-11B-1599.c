//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert_at_beginning(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_after_element(int data, int prev_data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *temp = head;
    while (temp->next!= NULL && temp->next->data!= prev_data)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_from_list(int data)
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (temp->data == data)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && temp->next->data!= data)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Data not found in the list!\n");
        return;
    }

    temp->next = temp->next->next;
    free(temp->next);
}

void display_list()
{
    Node *temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_beginning(5);
    insert_after_element(10, 5);
    delete_from_list(10);
    display_list();

    return 0;
}