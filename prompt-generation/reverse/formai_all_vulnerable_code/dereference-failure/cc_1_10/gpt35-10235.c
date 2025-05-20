//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the node of the linked list
struct node {
    int data;
    struct node *next;
};

// Function to insert elements to the list
void insert(struct node **head, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    
    if(*head == NULL) {
        // If the list is empty
        *head = new_node;
    }
    else {
        // Traverse to the end of the list
        struct node *temp = *head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        // Add the new node to the end of the list
        temp->next = new_node;
    }
    printf("Element %d added to the list!\n", value);
}

// Function to traverse through the list and display all the elements
void display(struct node *head) {
    if(head == NULL) {
        // If the list is empty
        printf("Linked list is empty!\n");
    }
    else {
        struct node *temp = head;
        printf("Linked list elements are:\n");
        while(temp!=NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to delete an element from the list
void delete(struct node **head, int value) {
    if(*head == NULL) {
        // If the list is empty
        printf("List is empty, deletion is not possible!\n");
    }
    else {
        struct node *temp1 = *head, *temp2 = NULL;
        while(temp1!=NULL && temp1->data!=value) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(temp1!=NULL) {
            // If the element is found
            if(temp1 == *head) {
                // If the element is the first element
                *head = (*head)->next;
            }
            else {
                temp2->next = temp1->next;
            }
            printf("Element %d deleted from the list!\n", value);
            free(temp1);
        }
        else {
            // If the element is not found
            printf("Element not found in the list, deletion is not possible!\n");
        }
    }
}

// Main function to demonstrate all the operations
int main() {
    struct node *head = NULL;
    int choice, value;
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the elements\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be added:\n");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter the element to be deleted:\n");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0); // Exit the program with clean exit
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}