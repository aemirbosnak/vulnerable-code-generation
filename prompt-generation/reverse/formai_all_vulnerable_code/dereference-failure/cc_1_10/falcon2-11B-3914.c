//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a contact
typedef struct contact {
    char name[50];
    char phone[15];
} Contact;

// Structure to hold the phone book
typedef struct phone_book {
    Contact contacts[10];
    int count;
} PhoneBook;

// Function to add a new contact to the phone book
void add_contact(PhoneBook *phone_book, char *name, char *phone) {
    // Check if the phone book is full
    if (phone_book->count == 10) {
        printf("Phone book is full.\n");
        return;
    }
    
    // Allocate memory for the new contact
    Contact *contact = (Contact *)malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->phone, phone);
    
    // Add the contact to the phone book
    phone_book->contacts[phone_book->count++] = *contact;
}

// Function to print all contacts in the phone book
void print_contacts(PhoneBook *phone_book) {
    int i;
    for (i = 0; i < phone_book->count; i++) {
        printf("%s: %s\n", phone_book->contacts[i].name, phone_book->contacts[i].phone);
    }
}

// Function to search for a contact in the phone book
int search_contact(PhoneBook *phone_book, char *name) {
    int i;
    for (i = 0; i < phone_book->count; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a contact from the phone book
void delete_contact(PhoneBook *phone_book, int index) {
    // Copy the contact to be deleted
    Contact *contact = &phone_book->contacts[index];
    
    // Free the memory used by the contact
    free(contact);
    
    // Shift the remaining contacts down to fill the gap
    for (int i = index; i < phone_book->count - 1; i++) {
        phone_book->contacts[i] = phone_book->contacts[i + 1];
    }
    
    // Decrement the count
    phone_book->count--;
}

// Function to initialize a new phone book
PhoneBook *init_phone_book() {
    PhoneBook *phone_book = (PhoneBook *)malloc(sizeof(PhoneBook));
    phone_book->count = 0;
    return phone_book;
}

// Function to exit the program
void exit_program() {
    printf("Exiting program...\n");
    exit(0);
}

int main() {
    PhoneBook *phone_book = init_phone_book();
    
    // Add some contacts to the phone book
    add_contact(phone_book, "Alice", "1234567890");
    add_contact(phone_book, "Bob", "0987654321");
    add_contact(phone_book, "Charlie", "0123456789");
    
    // Print all contacts in the phone book
    printf("Contacts in the phone book:\n");
    print_contacts(phone_book);
    
    // Search for a contact
    int contact_index = search_contact(phone_book, "Alice");
    if (contact_index!= -1) {
        printf("Contact found at index %d\n", contact_index);
    } else {
        printf("Contact not found\n");
    }
    
    // Delete a contact
    delete_contact(phone_book, 0);
    
    // Print all contacts again
    printf("Contacts in the phone book:\n");
    print_contacts(phone_book);
    
    // Exit the program
    exit_program();
    
    return 0;
}