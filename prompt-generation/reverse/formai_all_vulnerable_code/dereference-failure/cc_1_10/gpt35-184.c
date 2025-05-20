//FormAI DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact { // defining struct for contact
    char name[50];
    char phone_num[20];
    char email[50];
} Contact;

void add_contact(Contact *arr, int *size); // function prototype for adding a contact
void search_contact(Contact *arr, int size); // function prototype for searching a contact
void display_contacts(Contact *arr, int size); // function prototype for displaying all contacts
void delete_contact(Contact *arr, int *size); // function prototype for deleting a contact

int main() {
    int size = 0; // initializing size of contact list
    char choice;
    Contact *contacts = calloc(10, sizeof(Contact)); // allocating memory for 10 contacts
    
    printf("Welcome to your Phone Book!\n\n");
    
    do {
        printf("Please choose an option:\n");
        printf("1) Add a contact\n");
        printf("2) Search for a contact\n");
        printf("3) Display all contacts\n");
        printf("4) Delete a contact\n");
        printf("5) Exit\n\n");
        
        printf("Choice: ");
        scanf(" %c", &choice); // getting user choice
        
        switch(choice) {
            case '1':
                add_contact(contacts, &size); // call add_contact function and pass array and size
                break;
            case '2':
                search_contact(contacts, size); // call search_contact function and pass array and size
                break;
            case '3':
                display_contacts(contacts, size); // call display_contacts function and pass array and size
                break;
            case '4':
                delete_contact(contacts, &size); // call delete_contact function and pass array and size
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    } while (choice != '5'); // continue loop until user chooses to exit
    
    free(contacts); // free allocated memory for contacts
    
    return 0; // end program
}

void add_contact(Contact *arr, int *size) {
    Contact new_contact; // declaring new contact
    
    printf("Enter name: ");
    scanf(" %[^\n]", new_contact.name); // get name with spaces
    printf("Enter phone number: ");
    scanf(" %s", new_contact.phone_num); // get phone number
    printf("Enter email address: ");
    scanf(" %s", new_contact.email); // get email address
    
    arr[*size] = new_contact; // add new_contact to end of array
    (*size)++; // increment size of array
}

void search_contact(Contact *arr, int size) {
    char name[50];
    int i, found = 0; // initialize found flag
    
    printf("Enter name to search for: ");
    scanf(" %[^\n]", name); // get name with spaces
    
    for (i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) { // if contact name matches
            printf("\nName: %s\n", arr[i].name);
            printf("Phone Number: %s\n", arr[i].phone_num);
            printf("Email Address: %s\n", arr[i].email);
            
            found = 1; // set found flag to 1
            break; // exit loop
        }
    }
    
    if (!found) // if contact not found
        printf("\nContact not found.\n");
}

void display_contacts(Contact *arr, int size) {
    int i;
    
    if (size == 0) { // if no contacts in array
        printf("There are no contacts to display.\n");
        return;
    }
    
    printf("\n%-20s%-20s%-20s\n", "Name", "Phone Number", "Email");
    
    for (i = 0; i < size; i++) {
        printf("%-20s%-20s%-20s\n", arr[i].name, arr[i].phone_num, arr[i].email); // display contact information
    }
}

void delete_contact(Contact *arr, int *size) {
    char name[50];
    int i, found = 0; // initialize found flag
    
    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]", name); // get name with spaces
    
    for (i = 0; i < *size; i++) {
        if (strcmp(arr[i].name, name) == 0) { // if contact name matches
            arr[i] = arr[*size - 1]; // move last contact to current position
            (*size)--; // decrement size of array
            found = 1; // set found flag to 1
            break; // exit loop
        }
    }
    
    if (!found) // if contact not found
        printf("\nContact not found.\n");
    else
        printf("\nContact deleted.\n");
}