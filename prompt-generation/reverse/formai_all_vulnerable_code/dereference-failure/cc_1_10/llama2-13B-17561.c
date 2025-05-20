//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Phone book structure
typedef struct {
    char *name;
    char *phone;
    struct PhoneBook *next;
} PhoneBook;

// Phone book functions
PhoneBook *createPhoneBook() {
    PhoneBook *pb = malloc(sizeof(PhoneBook));
    pb->name = NULL;
    pb->phone = NULL;
    pb->next = NULL;
    return pb;
}

void addPhone(PhoneBook **head, char *name, char *phone) {
    PhoneBook *new = malloc(sizeof(PhoneBook));
    new->name = name;
    new->phone = phone;
    new->next = *head;
    *head = new;
}

void removePhone(PhoneBook **head, char *name) {
    PhoneBook *current = *head;
    PhoneBook *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
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

void printPhoneBook(PhoneBook *head) {
    while (head != NULL) {
        printf("%s: %s\n", head->name, head->phone);
        head = head->next;
    }
}

int main() {
    PhoneBook *head = createPhoneBook();

    // Add some phones
    addPhone(&head, "John Doe", "555-1234");
    addPhone(&head, "Jane Doe", "555-5678");
    addPhone(&head, "Bob Smith", "555-9012");

    // Remove a phone
    removePhone(&head, "Jane Doe");

    // Print the phone book
    printPhoneBook(head);

    return 0;
}