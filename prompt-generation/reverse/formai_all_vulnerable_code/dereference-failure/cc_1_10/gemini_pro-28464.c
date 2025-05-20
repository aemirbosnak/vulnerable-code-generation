//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char *name;
    char *number;
};

struct phonebook {
    struct contact *contacts;
    int num_contacts;
};

struct phonebook *create_phonebook() {
    struct phonebook *pb = malloc(sizeof(struct phonebook));
    pb->contacts = NULL;
    pb->num_contacts = 0;
    return pb;
}

void add_contact(struct phonebook *pb, char *name, char *number) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    pb->contacts = realloc(pb->contacts, (pb->num_contacts + 1) * sizeof(struct contact));
    pb->contacts[pb->num_contacts] = *new_contact;
    pb->num_contacts++;
}

void print_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].number);
    }
}

void free_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        free(pb->contacts[i].name);
        free(pb->contacts[i].number);
    }
    free(pb->contacts);
    free(pb);
}

int main() {
    struct phonebook *pb = create_phonebook();
    add_contact(pb, "John Doe", "555-123-4567");
    add_contact(pb, "Jane Smith", "555-234-5678");
    add_contact(pb, "Bill Johnson", "555-345-6789");
    print_phonebook(pb);
    free_phonebook(pb);
    return 0;
}