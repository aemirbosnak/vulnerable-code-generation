//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct node
{
    char data[MAX];
    struct node* next;
}node;

node* create_node(char data[])
{
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void insert_node(node** head_ref, char data[])
{
    node* new_node = create_node(data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    node* temp = *head_ref;
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = new_node;
}

void print_list(node* head)
{
    while (head!= NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
}

int main()
{
    node* head = NULL;
    insert_node(&head, "hello");
    insert_node(&head, "world");
    insert_node(&head, "index");
    insert_node(&head, "system");
    print_list(head);
    return 0;
}