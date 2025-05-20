//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct PhoneBook {
    Contact *contacts;
    int num_contacts;
    int max_contacts;
} PhoneBook;

PhoneBook *createPhoneBook(int max_contacts) {
    PhoneBook *phone_book = (PhoneBook *) malloc(sizeof(PhoneBook));
    phone_book->contacts = (Contact *) malloc(max_contacts * sizeof(Contact));
    phone_book->num_contacts = 0;
    phone_book->max_contacts = max_contacts;
    return phone_book;
}

void addContact(PhoneBook *phone_book, char *name, char *phone) {
    if (phone_book->num_contacts >= phone_book->max_contacts) {
        printf("Phone book is full\n");
        return;
    }
    strcpy(phone_book->contacts[phone_book->num_contacts].name, name);
    strcpy(phone_book->contacts[phone_book->num_contacts].phone, phone);
    phone_book->num_contacts++;
}

void displayContacts(PhoneBook *phone_book) {
    if (phone_book->num_contacts == 0) {
        printf("Phone book is empty\n");
        return;
    }
    printf("Phone Book:\n");
    printf("Name\t\tPhone\n");
    for (int i = 0; i < phone_book->num_contacts; i++) {
        printf("%s\t\t%s\n", phone_book->contacts[i].name, phone_book->contacts[i].phone);
    }
}

int main() {
    PhoneBook *phone_book = createPhoneBook(10);
    addContact(phone_book, "John Doe", "555-555-5555");
    addContact(phone_book, "Jane Smith", "555-123-4567");
    displayContacts(phone_book);
    free(phone_book->contacts);
    free(phone_book);
    return 0;
}