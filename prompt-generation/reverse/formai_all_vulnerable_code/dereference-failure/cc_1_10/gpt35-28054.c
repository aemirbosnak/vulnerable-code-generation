//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store contact information
struct Contact {
    char name[50];
    char phone_number[20];
    char email[100];
};

// Function to add contact to the phone book
void add_contact(struct Contact *contacts, int num_contacts) {
    char input[100];
    printf("Enter name: ");
    fgets(input, 100, stdin);
    strcpy(contacts[num_contacts].name, input);
    contacts[num_contacts].name[strcspn(contacts[num_contacts].name, "\n")] = 0; // remove newline
    
    printf("Enter phone number: ");
    fgets(input, 100, stdin);
    strcpy(contacts[num_contacts].phone_number, input);
    contacts[num_contacts].phone_number[strcspn(contacts[num_contacts].phone_number, "\n")] = 0; // remove newline
    
    printf("Enter email: ");
    fgets(input, 100, stdin);
    strcpy(contacts[num_contacts].email, input);
    contacts[num_contacts].email[strcspn(contacts[num_contacts].email, "\n")] = 0; // remove newline
    
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name
void search_contact(struct Contact *contacts, int num_contacts) {
    char search_name[50];
    printf("Enter name to search for: ");
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // remove newline
    
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_number);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int num_contacts = 0;
    struct Contact *contacts = malloc(sizeof(struct Contact));
    
    printf("Welcome to the Phone Book!\n\n");
    
    while (1) {
        printf("Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Quit\n\n");
        
        char input[100];
        printf("Enter choice: ");
        fgets(input, 100, stdin);
        
        if (strcmp(input, "1\n") == 0) {
            add_contact(contacts, num_contacts);
            num_contacts++;
            contacts = realloc(contacts, (num_contacts + 1) * sizeof(struct Contact)); // resize array
        }
        else if (strcmp(input, "2\n") == 0) {
            search_contact(contacts, num_contacts);
        }
        else if (strcmp(input, "3\n") == 0) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    free(contacts);
    
    return 0;
}