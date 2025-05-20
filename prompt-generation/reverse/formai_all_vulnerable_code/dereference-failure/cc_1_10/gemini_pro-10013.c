//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char *name;
    char *number;
};

struct phonebook {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts;
};

struct phonebook *create_phonebook() {
    struct phonebook *phonebook = malloc(sizeof(struct phonebook));
    phonebook->num_contacts = 0;
    return phonebook;
}

void add_contact(struct phonebook *phonebook, char *name, char *number) {
    if (phonebook->num_contacts >= MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return;
    }

    struct contact *contact = &phonebook->contacts[phonebook->num_contacts];
    contact->name = strdup(name);
    contact->number = strdup(number);
    phonebook->num_contacts++;
}

void print_phonebook(struct phonebook *phonebook) {
    for (int i = 0; i < phonebook->num_contacts; i++) {
        struct contact *contact = &phonebook->contacts[i];
        printf("%s: %s\n", contact->name, contact->number);
    }
}

void free_phonebook(struct phonebook *phonebook) {
    for (int i = 0; i < phonebook->num_contacts; i++) {
        struct contact *contact = &phonebook->contacts[i];
        free(contact->name);
        free(contact->number);
    }
    free(phonebook);
}

int main() {
    struct phonebook *phonebook = create_phonebook();

    add_contact(phonebook, "Alice", "123-456-7890");
    add_contact(phonebook, "Bob", "098-765-4321");
    add_contact(phonebook, "Carol", "111-222-3333");

    print_phonebook(phonebook);

    free_phonebook(phonebook);

    return 0;
}