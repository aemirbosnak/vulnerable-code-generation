//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the phone book structure
typedef struct {
    char *name;
    char *phone;
    struct phone_book *next;
} phone_book_t;

// Define the phone book functions
phone_book_t *phone_book_create(void);
void phone_book_insert(phone_book_t **head, const char *name, const char *phone);
void phone_book_search(phone_book_t **head, const char *name);
void phone_book_delete(phone_book_t **head, const char *name);

// Implement the phone book functions
phone_book_t *phone_book_create(void) {
    phone_book_t *new_book = malloc(sizeof(phone_book_t));
    new_book->name = NULL;
    new_book->phone = NULL;
    new_book->next = NULL;
    return new_book;
}

void phone_book_insert(phone_book_t **head, const char *name, const char *phone) {
    phone_book_t *new_book = phone_book_create();
    new_book->name = strdup(name);
    new_book->phone = strdup(phone);
    new_book->next = *head;
    *head = new_book;
}

void phone_book_search(phone_book_t **head, const char *name) {
    phone_book_t *current = *head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found: %s\n", current->name);
            break;
        }
        current = current->next;
    }
}

void phone_book_delete(phone_book_t **head, const char *name) {
    phone_book_t *current = *head;
    phone_book_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->phone);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main(void) {
    phone_book_t *head = phone_book_create();

    phone_book_insert(&head, "John Doe", "123-4567");
    phone_book_insert(&head, "Jane Doe", "987-6543");
    phone_book_insert(&head, "Bob Smith", "234-5678");

    phone_book_search(&head, "John Doe");
    phone_book_search(&head, "Jane Doe");
    phone_book_search(&head, "Bob Smith");

    phone_book_delete(&head, "John Doe");

    return 0;
}