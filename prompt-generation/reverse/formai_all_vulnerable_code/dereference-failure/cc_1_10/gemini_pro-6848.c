//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
// Welcome to the Cyberpunk Phonebook, a digital sanctuary amidst the neon-drenched streets.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
struct Contact {
    char *name;
    int number;
    struct Contact *next;
};

struct Phonebook {
    struct Contact *head;
    int size;
};

// Function prototypes
struct Phonebook *create_phonebook();
void add_contact(struct Phonebook *p, char *name, int number);
void remove_contact(struct Phonebook *p, char *name);
void print_phonebook(struct Phonebook *p);
void destroy_phonebook(struct Phonebook *p);

// Cyberpunk-themed ASCII art
char *divider = "======================================================================================================";
char *title = "\n  _ _               _      ____    ____                _            \n |(_) |__   __ _ _ __| |__  / ___|  / ___|  _ __   __ _| |__  _   _  \n | | '_ \ / _` | '__| '_ \ \___ \  \___ \ | '__| / _` | '_ \| | | | \n | | | | | (_| | |  | | | | ___) |  ___) || |   | (_| | | | | |_| | \n |_|_| |_|\__,_|_|  |_| |_|(____/  |____/ |_|    \__,_|_| |_|\__,_| \n\n";

int main() {
    printf("%s", title);
    printf("%s\n", divider);
    
    // Create a new phonebook
    struct Phonebook *p = create_phonebook();

    // Add some contacts
    add_contact(p, "Neo", 1234567890);
    add_contact(p, "Trinity", 9876543210);
    add_contact(p, "Morpheus", 1122334455);

    // Print the phonebook
    printf("Your Contacts:\n");
    print_phonebook(p);

    // Remove a contact
    remove_contact(p, "Trinity");

    // Print the updated phonebook
    printf("Updated Contacts:\n");
    print_phonebook(p);

    // Destroy the phonebook
    destroy_phonebook(p);

    return 0;
}

// Function definitions

struct Phonebook *create_phonebook() {
    struct Phonebook *p = malloc(sizeof(struct Phonebook));
    if (p == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for phonebook.\n");
        exit(1);
    }
    p->head = NULL;
    p->size = 0;
    return p;
}

void add_contact(struct Phonebook *p, char *name, int number) {
    // Create a new contact
    struct Contact *c = malloc(sizeof(struct Contact));
    if (c == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for contact.\n");
        exit(1);
    }
    c->name = strdup(name);
    c->number = number;
    c->next = NULL;

    // Add the contact to the phonebook
    if (p->head == NULL) {
        p->head = c;
    } else {
        struct Contact *current = p->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = c;
    }
    p->size++;
}

void remove_contact(struct Phonebook *p, char *name) {
    if (p->head == NULL) {
        fprintf(stderr, "Error: Phonebook is empty.\n");
        return;
    }

    struct Contact *previous = NULL;
    struct Contact *current = p->head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                p->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            p->size--;
            return;
        }
        previous = current;
        current = current->next;
    }

    fprintf(stderr, "Error: Contact not found.\n");
}

void print_phonebook(struct Phonebook *p) {
    if (p->head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }

    struct Contact *current = p->head;
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->number);
        current = current->next;
    }
}

void destroy_phonebook(struct Phonebook *p) {
    if (p->head == NULL) {
        return;
    }

    struct Contact *current = p->head;
    while (current != NULL) {
        struct Contact *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    free(p);
}