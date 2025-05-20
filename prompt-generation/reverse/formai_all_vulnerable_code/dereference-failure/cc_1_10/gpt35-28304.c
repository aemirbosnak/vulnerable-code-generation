//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored
#define MAX_NAME_LEN 50 // Maximum length of contact's name
#define MAX_PHONE_LEN 15 // Maximum length of contact's phone number

// Structure to hold contact information
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

// Function prototypes
void add_contact(Contact* contacts, int* num_contacts);
void search_contact(Contact* contacts, const int* num_contacts);
void display_contact(Contact* contacts, const int* num_contacts);
void save_contacts(Contact* contacts, const int* num_contacts);
void load_contacts(Contact* contacts, int* num_contacts);

int main() {
    Contact contactList[MAX_CONTACTS]; // Array to store contacts
    int numContacts = 0; // Number of contacts stored
    char choice;

    printf("Welcome to the Phone Book!\n");

    load_contacts(contactList, &numContacts); // Load contacts from file

    do {
        printf("\nMain Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Save Contacts\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': // Add Contact
                add_contact(contactList, &numContacts);
                break;
            case '2': // Search Contact
                search_contact(contactList, &numContacts);
                break;
            case '3': // Display All Contacts
                display_contact(contactList, &numContacts);
                break;
            case '4': // Save Contacts
                save_contacts(contactList, &numContacts);
                break;
            case '5': // Quit
                printf("Thanks for using the Phone Book!\n");
                break;
            default: // Invalid Choice
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != '5');

    return 0;
}

// Function to add a new contact
void add_contact(Contact* contacts, int* num_contacts) {
    if(*num_contacts >= MAX_CONTACTS) {
        printf("Sorry, the Phone Book is full.\n");
        return;
    }

    printf("Enter the Name: ");
    scanf(" %[^\n]", contacts[*num_contacts].name);
    printf("Enter the Phone Number (in XXX-XXX-XXXX format): ");
    scanf(" %s", contacts[*num_contacts].phone);

    printf("Contact Added.\n");

    (*num_contacts)++;
}

// Function to search for a contact
void search_contact(Contact* contacts, const int* num_contacts) {
    char name[MAX_NAME_LEN];
    int i, found = 0;

    printf("Enter the Name to Search: ");
    scanf(" %[^\n]", name);

    for(i = 0; i < *num_contacts; i++) {
        if(strcasecmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if(!found) {
        printf("Contact not found!\n");
    }
}

// Function to display all contacts
void display_contact(Contact* contacts, const int* num_contacts) {
    int i;

    if(*num_contacts == 0) {
        printf("No Contacts Found!\n");
        return;
    }

    printf("All Contacts:\n");

    for(i = 0; i < *num_contacts; i++) {
        printf("%d. Name: %s\n   Phone: %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

// Function to save all contacts to a file
void save_contacts(Contact* contacts, const int* num_contacts) {
    FILE* fp;
    int i;

    fp = fopen("contacts.txt", "w");

    if(fp == NULL) {
        printf("Error: Unable to Open File!\n");
        return;
    }

    for(i = 0; i < *num_contacts; i++) {
        fprintf(fp, "%s,%s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(fp);

    printf("Contacts Saved!\n");
}

// Function to load all contacts from a file
void load_contacts(Contact* contacts, int* num_contacts) {
    FILE* fp;
    char line[100], *name, *phone;

    fp = fopen("contacts.txt", "r");

    if(fp == NULL) {
        printf("No saved contacts found.\n");
        return;
    }

    while(fgets(line, 100, fp) != NULL) {
        name = strtok(line, ",");
        phone = strtok(NULL, ",");

        strncpy(contacts[*num_contacts].name, name, MAX_NAME_LEN);
        strncpy(contacts[*num_contacts].phone, phone, MAX_PHONE_LEN);

        (*num_contacts)++;
    }

    fclose(fp);

    printf("%d Contacts Loaded.\n", *num_contacts);
}