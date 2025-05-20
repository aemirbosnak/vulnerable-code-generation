//FormAI DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int data) 
{
    struct node *new_node =(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=(*head);
    (*head)=new_node;
}

void deleteNode(struct node **head, int key)
{
    struct node* ptr1 = *head, *ptr2 = NULL;
    while (ptr1 && ptr1->data != key)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    if (!ptr1) return;
    if (!ptr2) *head = ptr1->next;
    else ptr2->next = ptr1->next;
    free(ptr1);
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct node *head = NULL;
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 10);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 2);
    printf("Original Linked List: ");
    printList(head);
    deleteNode(&head, 10);
    printf("\nLinked List after Deletion of 10: ");
    printList(head);
    return 0;
}