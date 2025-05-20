//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each contact
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Define a node for the linked list
typedef struct node {
    Contact contact;
    struct node* next;
} Node;

// Function to add a contact to the phone book
void addContact(Node** head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->contact.name, name);
    strcpy(newNode->contact.phone, phone);
    newNode->next = *head;
    *head = newNode;
}

// Function to search for a contact in the phone book
Node* searchContact(Node* head, char* name) {
    while (head!= NULL) {
        if (strcmp(head->contact.name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print the phone book
void printPhoneBook(Node* head) {
    printf("Phone Book:\n");
    while (head!= NULL) {
        printf("Name: %s\tPhone: %s\n", head->contact.name, head->contact.phone);
        head = head->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Add contacts to the phone book
    addContact(&head, "John Doe", "123-456-7890");
    addContact(&head, "Jane Doe", "987-654-3210");

    // Print the phone book
    printPhoneBook(head);

    // Search for a contact in the phone book
    Node* foundNode = searchContact(head, "John Doe");
    if (foundNode!= NULL) {
        printf("Found contact: %s\n", foundNode->contact.name);
    } else {
        printf("Contact not found.\n");
    }

    return 0;
}