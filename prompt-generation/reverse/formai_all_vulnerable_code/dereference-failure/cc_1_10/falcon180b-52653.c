//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//Define node structure
struct Node
{
    int data;
    struct Node* next;
};

void addNode(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    while (node!= NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void reverseList(struct Node** head_ref)
{
    struct Node* prev_node = NULL;
    struct Node* current_node = (*head_ref);

    while (current_node!= NULL)
    {
        struct Node* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    (*head_ref) = prev_node;
}

void deleteNode(struct Node** head_ref, int key)
{
    struct Node* temp = (*head_ref);
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == key)
    {
        (*head_ref) = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int searchElement(struct Node* head, int key)
{
    struct Node* current = head;

    while (current!= NULL)
    {
        if (current->data == key)
            return 1;
        current = current->next;
    }

    return 0;
}

int main()
{
    struct Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    printf("Original list: ");
    printList(head);

    reverseList(&head);

    printf("\nReversed list: ");
    printList(head);

    deleteNode(&head, 30);

    printf("\nList after deleting 30: ");
    printList(head);

    int search_result = searchElement(head, 50);

    if (search_result == 1)
        printf("\nElement 50 found in the list.\n");
    else
        printf("\nElement 50 not found in the list.\n");

    return 0;
}