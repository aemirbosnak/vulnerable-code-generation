//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creating a structure to represent a node in a linked list
struct Node
{
    int data;
    struct Node* next;
};

// Function to insert a new node
void insert(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main()
{
    srand(time(NULL));

    // Creating an empty linked list
    struct Node* head = NULL;

    // Generating a random number between 5 and 15 to determine the size of the linked list
    int size = rand() % 11 + 5;

    // Adding random numbers to the linked list
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 100;
        insert(&head, num);
    }

    // Printing the linked list
    printf("The linked list is: \n");
    printList(head);

    return 0;
}