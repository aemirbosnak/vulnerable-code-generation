//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_node(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* insert_at_beginning(node* head, int data)
{
    node* new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

void print_list(node* head)
{
    while (head!= NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node* head = NULL;
    int num;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter the data for element %d: ", i+1);
        scanf("%d", &num);
        head = insert_at_beginning(head, num);
    }

    print_list(head);

    return 0;
}