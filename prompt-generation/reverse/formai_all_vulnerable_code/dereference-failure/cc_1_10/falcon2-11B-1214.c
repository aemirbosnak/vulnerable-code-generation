//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

void insert_at_beginning(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print_list()
{
    Node* temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(Node* del)
{
    if(del == head)
    {
        head = del->next;
        free(del);
    }
    else
    {
        Node* temp = head;
        while(temp->next!= del)
            temp = temp->next;
        Node* prev = temp;
        prev->next = temp->next;
        free(del);
    }
}

int main()
{
    insert_at_beginning(5);
    insert_at_beginning(10);
    insert_at_beginning(15);
    insert_at_beginning(20);

    print_list();

    delete_node(head->next);
    print_list();

    delete_node(head);
    print_list();

    return 0;
}