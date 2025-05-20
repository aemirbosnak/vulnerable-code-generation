//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct node to store email and next node pointer 
struct node{
    char email[50];
    struct node *next;
};

// Declaration of function prototypes
void addEmail(struct node **head, char *email);
void deleteEmail(struct node **head, char *email);
void printMailingList(struct node *head);
void freeList(struct node **head);

int main()
{
    // Initialize head pointer to NULL
    struct node *head = NULL;

    // Add emails to mailing list
    addEmail(&head, "example1@gmail.com");
    addEmail(&head, "example2@yahoo.com");
    addEmail(&head, "example3@gmail.com");
    addEmail(&head, "example4@hotmail.com");
    addEmail(&head, "example5@gmail.com");

    // Print mailing list
    printf("Mailing List:\n");
    printMailingList(head);

    // Delete an email from mailing list
    deleteEmail(&head, "example2@yahoo.com");

    // Print updated mailing list
    printf("\nMailing List after deleting an email:\n");
    printMailingList(head);

    // Free memory allocated by mailing list
    freeList(&head);

    return 0;
}

// Function to add new email to mailing list
void addEmail(struct node **head, char *email)
{
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));

    // Copy email to newNode
    strcpy(newNode->email, email);

    // Link newNode to mailing list
    newNode->next = *head;
    *head = newNode;
}

// Function to delete an email from mailing list
void deleteEmail(struct node **head, char *email)
{
    // Create temporary node pointers
    struct node *current = *head;
    struct node *previous = NULL;

    // Traverse mailing list to find node with matching email
    while(current != NULL){
        if(strcmp(current->email, email) == 0){
            break;
        }
        previous = current;
        current = current->next;
    }

    // If email is found, delete node
    if(current != NULL){
        // If node to be deleted is the head node
        if(current == *head){
            *head = current->next;
        }
        // If node to be deleted is not the head node
        else{
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to print mailing list
void printMailingList(struct node *head)
{
    // Traverse mailing list and print emails
    while(head != NULL){
        printf("%s\n", head->email);
        head = head->next;
    }
}

// Function to free memory allocated by mailing list
void freeList(struct node **head)
{
    struct node *temp;

    // Traverse mailing list and free each node
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}