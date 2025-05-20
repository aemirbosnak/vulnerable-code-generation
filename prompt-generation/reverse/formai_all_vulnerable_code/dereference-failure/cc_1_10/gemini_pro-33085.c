//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char *name;
    char *number;
};

struct PhoneBook {
    int size;
    struct Contact *contacts;
};

struct PhoneBook *create_phone_book(int size) {
    struct PhoneBook *phone_book = malloc(sizeof(struct PhoneBook));
    phone_book->size = size;
    phone_book->contacts = malloc(sizeof(struct Contact) * size);
    return phone_book;
}

void destroy_phone_book(struct PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->size; i++) {
        free(phone_book->contacts[i].name);
        free(phone_book->contacts[i].number);
    }
    free(phone_book->contacts);
    free(phone_book);
}

void add_contact(struct PhoneBook *phone_book, char *name, char *number) {
    struct Contact contact;
    contact.name = strdup(name);
    contact.number = strdup(number);
    phone_book->contacts[phone_book->size++] = contact;
}

char *get_number(struct PhoneBook *phone_book, char *name) {
    for (int i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            return phone_book->contacts[i].number;
        }
    }
    return NULL;
}

int main() {
    struct PhoneBook *phone_book = create_phone_book(100);
    add_contact(phone_book, "Alice", "123-456-7890");
    add_contact(phone_book, "Bob", "234-567-8901");
    add_contact(phone_book, "Carol", "345-678-9012");

    char *number = get_number(phone_book, "Alice");
    printf("Alice's number is %s\n", number);

    destroy_phone_book(phone_book);

    return 0;
}