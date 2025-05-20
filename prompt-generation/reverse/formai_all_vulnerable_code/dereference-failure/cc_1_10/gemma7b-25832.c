//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}node;

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    // Create two linked lists for Romeo and Juliet
    for(int i = 0; i < MAX; i++)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = i + 1;
        newNode->next = NULL;

        if(head1 == NULL)
        {
            head1 = newNode;
        }
        else
        {
            head1->next = newNode;
            head1 = newNode;
        }
    }

    for(int i = 0; i < MAX; i++)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = i + MAX + 1;
        newNode->next = NULL;

        if(head2 == NULL)
        {
            head2 = newNode;
        }
        else
        {
            head2->next = newNode;
            head2 = newNode;
        }
    }

    // Print the two linked lists
    node* current1 = head1;
    while(current1)
    {
        printf("%d ", current1->data);
        current1 = current1->next;
    }

    printf("\n");

    node* current2 = head2;
    while(current2)
    {
        printf("%d ", current2->data);
        current2 = current2->next;
    }

    return 0;
}