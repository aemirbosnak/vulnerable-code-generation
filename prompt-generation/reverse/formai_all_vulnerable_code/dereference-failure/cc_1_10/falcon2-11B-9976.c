//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define the struct for the phone book
struct PhoneBook {
    char name[100];
    char phone[20];
    char address[100];
};

// Function to add a new contact to the phone book
void addContact(struct PhoneBook* pb, char* name, char* phone, char* address) {
    pb->name[0] = '\0';
    strcpy(pb->name, name);
    pb->phone[0] = '\0';
    strcpy(pb->phone, phone);
    pb->address[0] = '\0';
    strcpy(pb->address, address);
}

// Function to search for a contact in the phone book
int searchContact(struct PhoneBook* pb, char* name) {
    int i = 0;
    while (pb[i].name[0]!= '\0') {
        if (strcmp(pb[i].name, name) == 0) {
            printf("Name: %s\n", pb[i].name);
            printf("Phone: %s\n", pb[i].phone);
            printf("Address: %s\n", pb[i].address);
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to display all contacts in the phone book
void displayContacts(struct PhoneBook* pb) {
    int i = 0;
    while (pb[i].name[0]!= '\0') {
        printf("Name: %s\n", pb[i].name);
        printf("Phone: %s\n", pb[i].phone);
        printf("Address: %s\n", pb[i].address);
        i++;
    }
}

int main() {
    // Create an array of phone book entries
    struct PhoneBook contacts[10];

    // Add contacts to the phone book
    addContact(contacts, "John Doe", "1234567890", "123 Main St");
    addContact(contacts, "Jane Smith", "9876543210", "456 Elm St");
    addContact(contacts, "Bob Johnson", "5555555555", "789 Oak St");

    // Search for a contact in the phone book
    int found = searchContact(contacts, "Jane Smith");
    if (found == 1) {
        printf("Contact found!\n");
    } else {
        printf("Contact not found\n");
    }

    // Display all contacts in the phone book
    displayContacts(contacts);

    return 0;
}