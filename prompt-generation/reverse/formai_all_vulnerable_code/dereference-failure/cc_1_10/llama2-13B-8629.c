//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct phone_book {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    struct phone_book *next;
} phone_book_t;

phone_book_t *create_phone_book() {
    phone_book_t *pb = (phone_book_t *)malloc(sizeof(phone_book_t));
    pb->name[0] = '\0';
    pb->phone_number[0] = '\0';
    pb->next = NULL;
    return pb;
}

void add_contact(phone_book_t *pb, const char *name, const char *phone_number) {
    phone_book_t *new_pb = create_phone_book();
    strcpy(new_pb->name, name);
    strcpy(new_pb->phone_number, phone_number);
    new_pb->next = pb->next;
    pb->next = new_pb;
}

void remove_contact(phone_book_t *pb, const char *name) {
    phone_book_t *current = pb;
    phone_book_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                pb->next = current->next;
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

void print_contacts(phone_book_t *pb) {
    while (pb != NULL) {
        printf("%s: %s\n", pb->name, pb->phone_number);
        pb = pb->next;
    }
}

int main() {
    phone_book_t *pb = create_phone_book();

    // Add some contacts
    add_contact(pb, "John Doe", "555-1234");
    add_contact(pb, "Jane Doe", "555-5678");
    add_contact(pb, "Bob Smith", "555-9012");

    // Remove a contact
    remove_contact(pb, "Jane Doe");

    // Print the remaining contacts
    print_contacts(pb);

    // Free the memory
    free(pb);

    return 0;
}