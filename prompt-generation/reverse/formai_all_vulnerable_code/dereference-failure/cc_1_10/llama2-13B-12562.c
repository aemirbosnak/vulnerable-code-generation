//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the phone book structure
typedef struct {
    char *name;
    char *number;
    struct phone_book *next;
} phone_book_t;

// Define the phone book function prototypes
phone_book_t *phone_book_create(void);
void phone_book_add(phone_book_t *book, const char *name, const char *number);
phone_book_t *phone_book_find(phone_book_t *book, const char *name);
void phone_book_remove(phone_book_t *book, const char *name);

// Implement the phone book functions
phone_book_t *phone_book_create(void) {
    phone_book_t *book = malloc(sizeof(phone_book_t));
    book->next = NULL;
    return book;
}

void phone_book_add(phone_book_t *book, const char *name, const char *number) {
    phone_book_t *new_book = malloc(sizeof(phone_book_t));
    new_book->name = strdup(name);
    new_book->number = strdup(number);
    new_book->next = book->next;
    book->next = new_book;
}

phone_book_t *phone_book_find(phone_book_t *book, const char *name) {
    phone_book_t *current = book;
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }
    return current;
}

void phone_book_remove(phone_book_t *book, const char *name) {
    phone_book_t *current = book;
    phone_book_t *prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            book->next = current->next;
        } else {
            prev->next = current->next;
        }
        free(current->name);
        free(current->number);
        free(current);
    }
}

int main(void) {
    phone_book_t *book = phone_book_create();
    phone_book_add(book, "John Doe", "555-1234");
    phone_book_add(book, "Jane Doe", "555-5678");
    phone_book_add(book, "Bob Smith", "555-9012");

    // Search the phone book
    printf("John Doe's number is: %s\n", phone_book_find(book, "John Doe")->number);

    // Remove a name from the phone book
    phone_book_remove(book, "Jane Doe");

    // Print the updated phone book
    printf("The updated phone book is:\n");
    phone_book_t *current = book;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->number);
        current = current->next;
    }

    return 0;
}