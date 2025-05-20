//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[100];
    struct node *next;
} node;

node *create_node(char *data)
{
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(node **head, char *data)
{
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, char *data)
{
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_position(node **head, char *data, int position)
{
    if (position == 1)
    {
        insert_at_beginning(head, data);
        return;
    }
    node *new_node = create_node(data);
    node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_at_position(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 1)
    {
        delete_at_beginning(head);
        return;
    }
    node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    node *to_be_deleted = temp->next;
    temp->next = temp->next->next;
    free(to_be_deleted);
}

void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    insert_at_beginning(&head, "Hello");
    insert_at_end(&head, "World");
    insert_at_position(&head, "!", 2);
    print_list(head);
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 1);
    print_list(head);
    return 0;
}