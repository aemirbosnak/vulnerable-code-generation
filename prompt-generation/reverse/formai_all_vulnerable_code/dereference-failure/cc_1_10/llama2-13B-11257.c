//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#define PHONE_BOOK_SIZE 1009
#define PHONE_NUMBER_SIZE 10

typedef struct phone_book {
    char name[PHONE_BOOK_SIZE];
    char phone_number[PHONE_NUMBER_SIZE];
    struct phone_book *next;
} phone_book_t;

phone_book_t *phone_book_create(void) {
    phone_book_t *book = malloc(sizeof(phone_book_t));
    book->name[0] = '\0';
    book->phone_number[0] = '\0';
    book->next = NULL;
    return book;
}

void phone_book_add(phone_book_t **head, const char *name, const char *phone_number) {
    phone_book_t *new_book = phone_book_create();
    strcpy(new_book->name, name);
    strcpy(new_book->phone_number, phone_number);
    new_book->next = *head;
    *head = new_book;
}

void phone_book_remove(phone_book_t **head, const char *name) {
    phone_book_t *current = *head;
    phone_book_t *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void phone_book_print(phone_book_t *head) {
    while (head != NULL) {
        printf("%s: %s\n", head->name, head->phone_number);
        head = head->next;
    }
}

int main(void) {
    phone_book_t *head = NULL;

    phone_book_add(&head, "John Doe", "555-1234");
    phone_book_add(&head, "Jane Doe", "555-5678");
    phone_book_add(&head, "Bob Smith", "555-9012");

    phone_book_remove(&head, "Jane Doe");

    phone_book_print(head);

    return 0;
}