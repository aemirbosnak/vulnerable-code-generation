//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create_node(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(struct node* head)
{
    struct node* current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = NULL;
    head = create_node(1);
    head = create_node(2);
    head = create_node(3);
    head = create_node(4);
    head = create_node(5);

    head = create_node(6);
    head = create_node(7);
    head = create_node(8);
    head = create_node(9);
    head = create_node(10);

    head = create_node(11);
    head = create_node(12);
    head = create_node(13);
    head = create_node(14);
    head = create_node(15);

    head = create_node(16);
    head = create_node(17);
    head = create_node(18);
    head = create_node(19);
    head = create_node(20);

    print_list(head);

    return 0;
}