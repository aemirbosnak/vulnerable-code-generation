//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUM_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_NUM_LENGTH];
} Contact;

typedef struct {
    int size;
    Contact* elements;
} PhoneBook;

PhoneBook* createPhoneBook(int size) {
    PhoneBook* phoneBook = (PhoneBook*) malloc(sizeof(PhoneBook));
    phoneBook->size = size;
    phoneBook->elements = (Contact*) malloc(size * sizeof(Contact));
    return phoneBook;
}

void addContact(PhoneBook* phoneBook, const char* name, const char* phone) {
    if (phoneBook->size == phoneBook->size) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook->elements[phoneBook->size].name, name);
    strcpy(phoneBook->elements[phoneBook->size].phone, phone);
    phoneBook->size++;
}

void removeContact(PhoneBook* phoneBook, int index) {
    if (index < 0 || index >= phoneBook->size) {
        printf("Invalid index.\n");
        return;
    }
    memmove(&phoneBook->elements[index], &phoneBook->elements[index + 1],
             (phoneBook->size - index - 1) * sizeof(Contact));
    phoneBook->size--;
}

Contact* findContactByName(PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->elements[i].name, name) == 0) {
            return &phoneBook->elements[i];
        }
    }
    return NULL;
}

void printPhoneBook(PhoneBook* phoneBook) {
    for (int i = 0; i < phoneBook->size; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook->elements[i].name,
               phoneBook->elements[i].phone);
    }
}

void freePhoneBook(PhoneBook* phoneBook) {
    free(phoneBook->elements);
    free(phoneBook);
}

int main() {
    PhoneBook* phoneBook = createPhoneBook(5);
    addContact(phoneBook, "Alice", "123-456-7890");
    addContact(phoneBook, "Bob", "234-567-8901");
    printPhoneBook(phoneBook);
    Contact* contact = findContactByName(phoneBook, "Alice");
    if (contact != NULL) {
        printf("Found contact with name \"%s\" and phone number \"%s\".\n",
               contact->name, contact->phone);
    }
    removeContact(phoneBook, 1);
    printPhoneBook(phoneBook);
    freePhoneBook(phoneBook);
    return 0;
}