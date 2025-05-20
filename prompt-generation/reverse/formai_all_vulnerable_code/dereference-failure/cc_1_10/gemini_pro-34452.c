//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Contact {
    char *name;
    char *number;
} Contact;

typedef struct PhoneBook {
    Contact *contacts;
    int capacity;
    int size;
} PhoneBook;

PhoneBook *create_phone_book(int capacity) {
    PhoneBook *phone_book = malloc(sizeof(PhoneBook));
    phone_book->contacts = malloc(sizeof(Contact) * capacity);
    phone_book->capacity = capacity;
    phone_book->size = 0;
    return phone_book;
}

void destroy_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->size; i++) {
        free(phone_book->contacts[i].name);
        free(phone_book->contacts[i].number);
    }
    free(phone_book->contacts);
    free(phone_book);
}

bool add_contact(PhoneBook *phone_book, const char *name, const char *number) {
    if (phone_book->size == phone_book->capacity) {
        return false;
    }

    int index = phone_book->size++;
    phone_book->contacts[index].name = strdup(name);
    phone_book->contacts[index].number = strdup(number);

    return true;
}

bool remove_contact(PhoneBook *phone_book, const char *name) {
    for (int i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            free(phone_book->contacts[i].name);
            free(phone_book->contacts[i].number);

            for (int j = i + 1; j < phone_book->size; j++) {
                phone_book->contacts[j - 1] = phone_book->contacts[j];
            }

            phone_book->size--;

            return true;
        }
    }

    return false;
}

Contact *get_contact(PhoneBook *phone_book, const char *name) {
    for (int i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            return &phone_book->contacts[i];
        }
    }

    return NULL;
}

void print_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->size; i++) {
        printf("%s: %s\n", phone_book->contacts[i].name, phone_book->contacts[i].number);
    }
}

int main() {
    PhoneBook *phone_book = create_phone_book(10);

    add_contact(phone_book, "John Doe", "555-1212");
    add_contact(phone_book, "Jane Smith", "555-1213");
    add_contact(phone_book, "Bill Jones", "555-1214");

    print_phone_book(phone_book);

    Contact *contact = get_contact(phone_book, "John Doe");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->number);
    } else {
        printf("Contact not found.\n");
    }

    remove_contact(phone_book, "Jane Smith");

    print_phone_book(phone_book);

    destroy_phone_book(phone_book);

    return 0;
}