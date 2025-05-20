//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_SIZE 10

typedef struct phone_entry {
    char name[50];
    char phone_number[PHONE_NUMBER_SIZE];
    struct phone_entry *next;
} phone_entry_t;

phone_entry_t *phone_book = NULL;

void insert(phone_entry_t **head_ref, char *name, char *phone_number) {
    phone_entry_t *new_entry = (phone_entry_t *)malloc(sizeof(phone_entry_t));
    strcpy(new_entry->name, name);
    strcpy(new_entry->phone_number, phone_number);
    new_entry->next = NULL;

    if (*head_ref == NULL) {
        phone_book = new_entry;
    } else {
        phone_book->next = new_entry;
    }

    phone_book = new_entry;
}

phone_entry_t *search(char *name) {
    phone_entry_t *current = phone_book;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void delete(char *name) {
    phone_entry_t *current = phone_book;
    phone_entry_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                phone_book = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        char name[50];
        char phone_number[PHONE_NUMBER_SIZE];

        // Generate a random name and phone number
        sprintf(name, "Person %d", i);
        sprintf(phone_number, "%d-%d-%d", rand() % 1000, rand() % 1000, rand() % 1000);

        insert(&phone_book, name, phone_number);
    }

    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        char name[50];

        // Randomly delete a name and phone number
        sprintf(name, "Person %d", i);
        delete(name);
    }

    return 0;
}