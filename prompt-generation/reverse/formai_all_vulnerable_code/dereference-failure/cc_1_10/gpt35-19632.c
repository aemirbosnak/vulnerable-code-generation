//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a phonebook struct
struct Phonebook {
    char name[50];
    char number[20];
    struct Phonebook* next;
};

// Function to add a new contact to the phonebook
void addContact(struct Phonebook** head_ref, char* name, char* number) {
    // Allocate memory for a new contact node
    struct Phonebook* new_contact = (struct Phonebook*)malloc(sizeof(struct Phonebook));
    
    // Copy the contact information into the new node
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    
    // Set the new node's next pointer to the current head node
    new_contact->next = *head_ref;
    
    // Set the head pointer to the new node
    *head_ref = new_contact;
}

// Function to print all contacts in the phonebook
void printPhonebook(struct Phonebook* head) {
    printf("\nPhonebook:\n");
    
    // Traverse the list and print each contact's information
    while(head != NULL) {
        printf("%s: %s\n", head->name, head->number);
        head = head->next;
    }
}

// Function to delete a contact from the phonebook
void deleteContact(struct Phonebook** head_ref, char* name) {
    struct Phonebook* current = *head_ref;
    struct Phonebook* prev = NULL;
    
    // Traverse the list to find the node with the given name
    while(current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    // If the contact was not found in the phonebook, print an error message and return
    if(current == NULL) {
        printf("Error: '%s' is not in the phonebook\n", name);
        return;
    }
    
    // If the contact was found in the phonebook, remove the node from the list
    if(prev == NULL) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }
    
    // Free the memory used by the deleted node
    free(current);
}

// Main function
int main() {
    struct Phonebook* phonebook = NULL;
    
    // Add some test contacts to the phonebook
    addContact(&phonebook, "Alice", "555-1234");
    addContact(&phonebook, "Bob", "555-5678");
    addContact(&phonebook, "Charlie", "555-9101");
    
    // Print the phonebook
    printPhonebook(phonebook);
    
    // Delete a contact from the phonebook
    deleteContact(&phonebook, "Bob");
    
    // Print the phonebook again to confirm that the contact was deleted
    printPhonebook(phonebook);
    
    return 0;
}