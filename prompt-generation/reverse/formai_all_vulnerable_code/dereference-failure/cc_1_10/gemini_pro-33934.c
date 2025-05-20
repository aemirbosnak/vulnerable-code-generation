//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct contact {
    char *name;
    char *number;
} contact;

typedef struct phonebook {
    contact *contacts;
    int size;
} phonebook;

phonebook *create_phonebook() {
    phonebook *pb = (phonebook *)malloc(sizeof(phonebook));
    pb->contacts = NULL;
    pb->size = 0;
    return pb;
}

void add_contact(phonebook *pb, char *name, char *number) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    new_contact->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_contact->name, name);
    new_contact->number = (char *)malloc(strlen(number) + 1);
    strcpy(new_contact->number, number);

    pb->contacts = (contact *)realloc(pb->contacts, (pb->size + 1) * sizeof(contact));
    pb->contacts[pb->size++] = *new_contact;

    free(new_contact);
}

contact *get_contact(phonebook *pb, char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

void print_phonebook(phonebook *pb) {
    for (int i = 0; i < pb->size; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].number);
    }
}

void free_phonebook(phonebook *pb) {
    for (int i = 0; i < pb->size; i++) {
        free(pb->contacts[i].name);
        free(pb->contacts[i].number);
    }
    free(pb->contacts);
    free(pb);
}

int main() {
    phonebook *pb = create_phonebook();

    add_contact(pb, "Alice", "123-456-7890");
    add_contact(pb, "Bob", "987-654-3210");
    add_contact(pb, "Carol", "111-222-3333");

    print_phonebook(pb);

    contact *alice = get_contact(pb, "Alice");
    if (alice != NULL) {
        printf("Alice's number is %s\n", alice->number);
    } else {
        printf("Alice not found\n");
    }

    free_phonebook(pb);

    return 0;
}