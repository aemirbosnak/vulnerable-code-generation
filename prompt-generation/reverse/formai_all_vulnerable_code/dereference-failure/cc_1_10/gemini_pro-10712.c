//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

// Define the structure of the phone book
typedef struct phone_book {
    contact contacts[MAX_CONTACTS];
    int num_contacts;
} phone_book;

// Create a new phone book
phone_book *create_phone_book() {
    phone_book *pb = (phone_book *)malloc(sizeof(phone_book));
    pb->num_contacts = 0;
    return pb;
}

// Add a contact to the phone book
void add_contact(phone_book *pb, char *name, char *phone_number, char *email) {
    strcpy(pb->contacts[pb->num_contacts].name, name);
    strcpy(pb->contacts[pb->num_contacts].phone_number, phone_number);
    strcpy(pb->contacts[pb->num_contacts].email, email);
    pb->num_contacts++;
}

// Search for a contact in the phone book by name
contact *search_contact_by_name(phone_book *pb, char *name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Search for a contact in the phone book by phone number
contact *search_contact_by_phone_number(phone_book *pb, char *phone_number) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].phone_number, phone_number) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Search for a contact in the phone book by email
contact *search_contact_by_email(phone_book *pb, char *email) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].email, email) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Print the contacts in the phone book
void print_phone_book(phone_book *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s\n", pb->contacts[i].name);
        printf("%s\n", pb->contacts[i].phone_number);
        printf("%s\n", pb->contacts[i].email);
        printf("\n");
    }
}

// Free the memory allocated for the phone book
void free_phone_book(phone_book *pb) {
    free(pb);
}

// Main function
int main() {
    // Create a new phone book
    phone_book *pb = create_phone_book();

    // Add some contacts to the phone book
    add_contact(pb, "John Doe", "555-1212", "john.doe@example.com");
    add_contact(pb, "Jane Doe", "555-1213", "jane.doe@example.com");
    add_contact(pb, "John Smith", "555-1214", "john.smith@example.com");

    // Print the contacts in the phone book
    print_phone_book(pb);

    // Search for a contact by name
    contact *john_doe = search_contact_by_name(pb, "John Doe");
    if (john_doe != NULL) {
        printf("Found John Doe: %s, %s, %s\n", john_doe->name, john_doe->phone_number, john_doe->email);
    } else {
        printf("John Doe not found\n");
    }

    // Search for a contact by phone number
    contact *jane_doe = search_contact_by_phone_number(pb, "555-1213");
    if (jane_doe != NULL) {
        printf("Found Jane Doe: %s, %s, %s\n", jane_doe->name, jane_doe->phone_number, jane_doe->email);
    } else {
        printf("Jane Doe not found\n");
    }

    // Search for a contact by email
    contact *john_smith = search_contact_by_email(pb, "john.smith@example.com");
    if (john_smith != NULL) {
        printf("Found John Smith: %s, %s, %s\n", john_smith->name, john_smith->phone_number, john_smith->email);
    } else {
        printf("John Smith not found\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(pb);

    return 0;
}