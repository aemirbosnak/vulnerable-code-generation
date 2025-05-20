//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct contact {
    char *name;
    char *phone_number;
    struct contact *next;
};

typedef struct contact contact;

struct phone_book {
    contact *head;
    int size;
};

typedef struct phone_book phone_book;

contact *create_contact(char *name, char *phone_number) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    new_contact->name = name;
    new_contact->phone_number = phone_number;
    new_contact->next = NULL;
    return new_contact;
}

phone_book *create_phone_book() {
    phone_book *new_phone_book = (phone_book *)malloc(sizeof(phone_book));
    new_phone_book->head = NULL;
    new_phone_book->size = 0;
    return new_phone_book;
}

void add_contact(phone_book *phone_book, contact *new_contact) {
    if (phone_book->head == NULL) {
        phone_book->head = new_contact;
    } else {
        contact *current_contact = phone_book->head;
        while (current_contact->next != NULL) {
            current_contact = current_contact->next;
        }
        current_contact->next = new_contact;
    }
    phone_book->size++;
}

void print_phone_book(phone_book *phone_book) {
    contact *current_contact = phone_book->head;
    while (current_contact != NULL) {
        printf("%s: %s\n", current_contact->name, current_contact->phone_number);
        current_contact = current_contact->next;
    }
}

void free_phone_book(phone_book *phone_book) {
    contact *current_contact = phone_book->head;
    while (current_contact != NULL) {
        contact *next_contact = current_contact->next;
        free(current_contact->name);
        free(current_contact->phone_number);
        free(current_contact);
        current_contact = next_contact;
    }
    free(phone_book);
}

int main() {
    phone_book *phone_book = create_phone_book();
    add_contact(phone_book, create_contact("John", "555-123-4567"));
    add_contact(phone_book, create_contact("Mary", "555-234-5678"));
    add_contact(phone_book, create_contact("Bob", "555-345-6789"));
    print_phone_book(phone_book);
    free_phone_book(phone_book);
    return 0;
}