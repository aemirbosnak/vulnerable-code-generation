//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

/* define the linked list node */
typedef struct node
{
    int data;
    struct node* next;
} node;

/* function to print the linked list */
void print(node* head)
{
    node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* function to insert a new node at the beginning of the linked list */
void insert_beginning(node** head_ref, int value)
{
    /* create a new node */
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = *head_ref;
    
    /* update the head reference */
    *head_ref = new_node;
}

/* function to insert a new node at the end of the linked list */
void insert_end(node** head_ref, int value)
{
    /* create a new node */
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    
    /* if the linked list is empty, set the head reference to the new node */
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    
    /* otherwise, find the tail and append the new node */
    node* current = *head_ref;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

/* function to insert a new node at a specific position in the linked list */
void insert_pos(node** head_ref, int value, int position)
{
    /* create a new node */
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    
    /* handle the case where the position is 0 (i.e. insert at the beginning) */
    if(position == 0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    
    /* find the node before the position */
    node* current = *head_ref;
    int i;
    for(i = 0; i < position-1 && current != NULL; i++)
    {
        current = current->next;
    }
    
    /* if we went past the end of the list, return an error */
    if(current == NULL)
    {
        printf("Error: Position %d does not exist in list.\n", position);
        return;
    }
    
    /* otherwise, insert the new node after the node before the position */
    new_node->next = current->next;
    current->next = new_node;
}

/* function to delete the first node in the linked list */
void delete_beginning(node** head_ref)
{
    if(*head_ref == NULL)
    {
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    
    node* current = *head_ref;
    *head_ref = current->next;
    free(current);
}

/* function to delete the last node in the linked list */
void delete_end(node** head_ref)
{
    if(*head_ref == NULL)
    {
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    
    node* current = *head_ref;
    if(current->next == NULL)
	{
		*head_ref = NULL;
		free(current);
		return;
	}
    
    node* prev = NULL;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    free(current);
}

/* function to delete a node at a specific position in the linked list */
void delete_pos(node** head_ref, int position)
{
    if(*head_ref == NULL)
    {
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    
    if(position == 0)
    {
        node* current = *head_ref;
        *head_ref = current->next;
        free(current);
        return;
    }
    
    node* current = *head_ref;
    int i;
    for(i = 0; i < position-1 && current != NULL; i++)
    {
        current = current->next;
    }
    
    if(current == NULL || current->next == NULL)
    {
        printf("Error: Position %d does not exist in list.\n", position);
        return;
    }
    
    node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

/* main function */
int main()
{
    node* head = NULL;
    
    /* insert nodes at the beginning */
    printf("Inserting nodes at the beginning: ");
    insert_beginning(&head, 1);
    insert_beginning(&head, 2);
    insert_beginning(&head, 3);
    print(head);
    
    /* insert nodes at the end */
    printf("Inserting nodes at the end: ");
    insert_end(&head, 4);
    insert_end(&head, 5);
    insert_end(&head, 6);
    print(head);
    
    /* insert nodes at specific positions */
    printf("Inserting nodes at specific positions: ");
    insert_pos(&head, 0, 0);
    insert_pos(&head, 7, 7);
    insert_pos(&head, 8, 3);
    print(head);
    
    /* delete nodes from the beginning */
    printf("Deleting nodes from the beginning: ");
    delete_beginning(&head);
    delete_beginning(&head);
    delete_beginning(&head);
    print(head);
    
    /* delete nodes from the end */
    printf("Deleting nodes from the end: ");
    delete_end(&head);
    delete_end(&head);
    delete_end(&head);
    print(head);
    
    /* delete nodes at specific positions */
    printf("Deleting nodes at specific positions: ");
    delete_pos(&head, 0);
    delete_pos(&head, 5);
    delete_pos(&head, 2);
    print(head);
    
    return 0;
}