//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for each node in the mailing list
typedef struct node {
    char name[50];
    char email[50];
    struct node* next;
} node;

// Function to create a new node (member) in the mailing list
node* createNode(char name[], char email[]) {
    node* newNode = (node*) malloc(sizeof(node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new member to the mailing list
void addMember(node** head, char name[], char email[]) {
    if (*head == NULL) {
        // If there is no member in the list yet, create a new node and point the head to it
        node* newNode = createNode(name, email);
        *head = newNode;
        return;
    }
    // If there are already members in the list, traverse through the list until the end
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Add the new member to the end of the list
    node* newNode = createNode(name, email);
    temp->next = newNode;
}

// Function to remove a member from the mailing list
void removeMember(node** head, char name[]) {
    node* temp = *head;
    node* prev = NULL;
    // Traverse through the list to look for the member to be removed
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        // Member not found in the list
        printf("Member not found in the mailing list.\n");
        return;
    }
    if (prev == NULL) {
        // If the member to be removed is the first member in the list, point the head to the next member
        *head = temp->next;
    } else {
        // Remove the member by bypassing it in the list
        prev->next = temp->next;
    }
    free(temp); // Free up the memory used by the removed member
}

// Function to print all members in the mailing list
void printList(node* head) {
    node* temp = head;
    printf("Mailing list:\n");
    while (temp != NULL) {
        printf("%s, %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    node* head = NULL; // Initialize the mailing list to be empty
    char choice, name[50], email[50];
    do {
        printf("\nEnter A to add a member, R to remove a member, P to print the mailing list, or Q to quit: ");
        scanf(" %c", &choice);
        switch(choice) {
            case 'A': // Adding a new member
            case 'a':
                printf("Enter the member's name: ");
                scanf(" %[^\n]s", name);
                printf("Enter the member's email: ");
                scanf(" %[^\n]s", email);
                addMember(&head, name, email);
                printf("New member %s added to the mailing list.\n", name);
                break;
            case 'R': // Removing a member
            case 'r':
                printf("Enter the name of the member to be removed: ");
                scanf(" %[^\n]s", name);
                removeMember(&head, name);
                break;
            case 'P': // Printing the mailing list
            case 'p':
                printList(head);
                break;
            case 'Q': // Quitting the program
            case 'q':
                printf("Exiting the mailing list manager.\n");
                break;
            default: // Wrong input
                printf("Invalid input, please try again.\n");
        }
    } while (choice != 'Q' && choice != 'q');
    return 0;
}