//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char *name;
    char *number;
};

struct PhoneBook {
    struct Contact *contacts;
    int num_contacts;
};

void add_contact(struct PhoneBook *pb, char *name, char *number) {
    struct Contact *new_contact = malloc(sizeof(struct Contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    pb->contacts = realloc(pb->contacts, (pb->num_contacts + 1) * sizeof(struct Contact));
    pb->contacts[pb->num_contacts++] = *new_contact;
}

void print_contact(struct Contact *c) {
    printf("%s: %s\n", c->name, c->number);
}

void print_phonebook(struct PhoneBook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        print_contact(&pb->contacts[i]);
    }
}

void free_contact(struct Contact *c) {
    free(c->name);
    free(c->number);
    free(c);
}

void free_phonebook(struct PhoneBook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        free_contact(&pb->contacts[i]);
    }
    free(pb->contacts);
    free(pb);
}

int main() {
    struct PhoneBook *pb = malloc(sizeof(struct PhoneBook));
    pb->contacts = NULL;
    pb->num_contacts = 0;

    add_contact(pb, "King Arthur", "1-800-KING-ART");
    add_contact(pb, "Sir Lancelot", "1-800-LANCELOT");
    add_contact(pb, "Sir Gawain", "1-800-GAWAIN");

    print_phonebook(pb);

    free_phonebook(pb);

    return 0;
}