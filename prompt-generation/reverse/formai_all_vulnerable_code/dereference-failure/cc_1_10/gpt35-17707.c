//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

//Structure for the Node containing data and pointer to next node
struct Node {
    int data;
    struct Node* next;
};

//Function to add a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    //Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Assign data and pointer to next node
    new_node->data = new_data;
    new_node->next = (*head_ref);

    //Re-assign the reference of head to the new node
    (*head_ref) = new_node;
}

//Function to search an element in the linked list
void search(struct Node* head, int key)
{
    //Assign pointer to head of the linked list
    struct Node* current = head;

    //Loop through the linked list until key is found or end of list is reached
    while (current != NULL) 
    {
        //If key is found, print message and return control to calling function
        if (current->data == key) 
        {
            printf("\nData item found in Cyberworld Matrix: %d", key);
            return;
        }
        //Move pointer to the next node
        current = current->next;
    }
    //If key is not found, print message
    printf("\nData item not found in Cyberworld Matrix: %d", key);
}

//Main function
int main()
{
    //Assign pointer to head of the linked list
    struct Node* head = NULL;

    //Add nodes at the beginning of the linked list
    push(&head, 17);
    push(&head, 29);
    push(&head, 38);
    push(&head, 41);
    push(&head, 55);
    push(&head, 67);

    //Search for elements in the linked list
    search(head, 38);
    search(head, 25);
    search(head, 55);

    return 0;
}