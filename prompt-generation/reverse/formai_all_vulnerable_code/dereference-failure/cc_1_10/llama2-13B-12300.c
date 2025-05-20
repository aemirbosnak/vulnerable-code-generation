//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LEN 25
#define MAX_PHONE_LEN 20
#define MAX_ADDRESS_LEN 50

struct phone_book {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
};

typedef struct phone_book phone_book_t;

phone_book_t* create_phone_book();
void add_contact(phone_book_t*, char*, char*, char*);
void search_contact(phone_book_t*, char*);
void delete_contact(phone_book_t*, char*);
void print_contacts(phone_book_t*);

phone_book_t* create_phone_book() {
    phone_book_t* pb = (phone_book_t*) malloc(sizeof(struct phone_book));
    pb->name[0] = '\0';
    pb->phone[0] = '\0';
    pb->address[0] = '\0';
    return pb;
}

void add_contact(phone_book_t* pb, char* name, char* phone, char* address) {
    strcpy(pb->name, name);
    strcpy(pb->phone, phone);
    strcpy(pb->address, address);
}

void search_contact(phone_book_t* pb, char* name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (tolower(name[i]) != tolower(pb->name[i])) {
            break;
        }
    }
    if (i == strlen(name)) {
        printf("Contact found: %s\n", pb->name);
    } else {
        printf("Contact not found\n");
    }
}

void delete_contact(phone_book_t* pb, char* name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (tolower(name[i]) != tolower(pb->name[i])) {
            break;
        }
    }
    if (i == strlen(name)) {
        printf("Contact not found\n");
    } else {
        strcpy(pb->name, "");
        strcpy(pb->phone, "");
        strcpy(pb->address, "");
    }
}

void print_contacts(phone_book_t* pb) {
    printf("Contacts:\n");
    printf("Name: %s\n", pb->name);
    printf("Phone: %s\n", pb->phone);
    printf("Address: %s\n", pb->address);
}

int main() {
    phone_book_t* pb = create_phone_book();

    // Add some contacts
    add_contact(pb, "John Doe", "555-1234", "123 Main St");
    add_contact(pb, "Jane Doe", "555-5678", "456 Elm St");
    add_contact(pb, "Bob Smith", "555-9012", "789 Oak St");

    // Search for a contact
    search_contact(pb, "Jane Doe");

    // Delete a contact
    delete_contact(pb, "Bob Smith");

    // Print all contacts
    print_contacts(pb);

    return 0;
}