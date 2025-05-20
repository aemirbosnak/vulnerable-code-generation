//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *number;
} Contact;

typedef struct {
    Contact **arr;
    int size;
} PhoneBook;

PhoneBook *createPhoneBook(int initialSize) {
    PhoneBook *book = (PhoneBook *)malloc(sizeof(PhoneBook));
    book->arr = (Contact **)malloc(sizeof(Contact *) * initialSize);
    book->size = 0;
    return book;
}

void addContact(PhoneBook *book, Contact *contact) {
    book->arr[book->size++] = contact;
}

Contact *findContactByName(PhoneBook *book, char *name) {
    for (int i = 0; i < book->size; i++) {
        if (strcmp(book->arr[i]->name, name) == 0) {
            return book->arr[i];
        }
    }
    return NULL;
}

Contact *findContactByNumber(PhoneBook *book, char *number) {
    for (int i = 0; i < book->size; i++) {
        if (strcmp(book->arr[i]->number, number) == 0) {
            return book->arr[i];
        }
    }
    return NULL;
}

void printPhoneBook(PhoneBook *book) {
    for (int i = 0; i < book->size; i++) {
        printf("%s %s\n", book->arr[i]->name, book->arr[i]->number);
    }
}

int main() {
    PhoneBook *book = createPhoneBook(10);
    addContact(book, (Contact *)malloc(sizeof(Contact)));
    book->arr[0]->name = "John Doe";
    book->arr[0]->number = "1234567890";
    addContact(book, (Contact *)malloc(sizeof(Contact)));
    book->arr[1]->name = "Jane Doe";
    book->arr[1]->number = "0987654321";
    printPhoneBook(book);
    Contact *contact = findContactByName(book, "Jane Doe");
    if (contact != NULL) {
        printf("Found contact: %s %s\n", contact->name, contact->number);
    } else {
        printf("Contact not found\n");
    }
    contact = findContactByNumber(book, "0987654321");
    if (contact != NULL) {
        printf("Found contact: %s %s\n", contact->name, contact->number);
    } else {
        printf("Contact not found\n");
    }
    return 0;
}