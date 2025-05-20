//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char *name;
    char *phone_number;
    struct contact *next;
};

struct phone_book {
    struct contact *head;
    struct contact *tail;
};

struct phone_book *create_phone_book() {
    struct phone_book *phone_book = malloc(sizeof(struct phone_book));
    if (phone_book == NULL) {
        return NULL;
    }
    phone_book->head = NULL;
    phone_book->tail = NULL;
    return phone_book;
}

void free_phone_book(struct phone_book *phone_book) {
    struct contact *current = phone_book->head;
    struct contact *next;
    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current->phone_number);
        free(current);
        current = next;
    }
    free(phone_book);
}

int add_contact(struct phone_book *phone_book, char *name, char *phone_number) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    if (new_contact == NULL) {
        return -1;
    }
    new_contact->name = strdup(name);
    if (new_contact->name == NULL) {
        free(new_contact);
        return -1;
    }
    new_contact->phone_number = strdup(phone_number);
    if (new_contact->phone_number == NULL) {
        free(new_contact->name);
        free(new_contact);
        return -1;
    }
    new_contact->next = NULL;
    if (phone_book->head == NULL) {
        phone_book->head = new_contact;
        phone_book->tail = new_contact;
    } else {
        phone_book->tail->next = new_contact;
        phone_book->tail = new_contact;
    }
    return 0;
}

int remove_contact(struct phone_book *phone_book, char *name) {
    struct contact *current = phone_book->head;
    struct contact *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                phone_book->head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == phone_book->tail) {
                phone_book->tail = previous;
            }
            free(current->name);
            free(current->phone_number);
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

struct contact *find_contact(struct phone_book *phone_book, char *name) {
    struct contact *current = phone_book->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_phone_book(struct phone_book *phone_book) {
    struct contact *current = phone_book->head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}

int main() {
    struct phone_book *phone_book = create_phone_book();
    if (phone_book == NULL) {
        fprintf(stderr, "Error creating phone book.\n");
        return EXIT_FAILURE;
    }
    add_contact(phone_book, "John Doe", "555-1212");
    add_contact(phone_book, "Jane Doe", "555-1213");
    add_contact(phone_book, "John Smith", "555-1214");
    print_phone_book(phone_book);
    struct contact *contact = find_contact(phone_book, "John Doe");
    if (contact == NULL) {
        fprintf(stderr, "Error finding contact.\n");
        return EXIT_FAILURE;
    }
    printf("Name: %s\n", contact->name);
    printf("Phone number: %s\n", contact->phone_number);
    remove_contact(phone_book, "John Smith");
    print_phone_book(phone_book);
    free_phone_book(phone_book);
    return EXIT_SUCCESS;
}