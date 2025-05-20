//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char *name;
    char *number;
};

struct contactBook {
    struct contact *contacts;
    int numContacts;
};

struct contactBook *createContactBook() {
    struct contactBook *cb = malloc(sizeof(struct contactBook));
    cb->contacts = malloc(sizeof(struct contact) * 100);
    cb->numContacts = 0;
    return cb;
}

void addContact(struct contactBook *cb, char *name, char *number) {
    cb->contacts[cb->numContacts].name = malloc(strlen(name) + 1);
    strcpy(cb->contacts[cb->numContacts].name, name);
    cb->contacts[cb->numContacts].number = malloc(strlen(number) + 1);
    strcpy(cb->contacts[cb->numContacts].number, number);
    cb->numContacts++;
}

void printContactBook(struct contactBook *cb) {
    for (int i = 0; i < cb->numContacts; i++) {
        printf("%s: %s\n", cb->contacts[i].name, cb->contacts[i].number);
    }
}

void freeContactBook(struct contactBook *cb) {
    for (int i = 0; i < cb->numContacts; i++) {
        free(cb->contacts[i].name);
        free(cb->contacts[i].number);
    }
    free(cb->contacts);
    free(cb);
}

int main() {
    struct contactBook *cb = createContactBook();
    addContact(cb, "Romeo", "555-1212");
    addContact(cb, "Juliet", "555-1213");
    addContact(cb, "Tybalt", "555-1214");
    addContact(cb, "Mercutio", "555-1215");
    addContact(cb, "Benvolio", "555-1216");
    addContact(cb, "Paris", "555-1217");
    addContact(cb, "Lord Capulet", "555-1218");
    addContact(cb, "Lady Capulet", "555-1219");
    addContact(cb, "Lord Montague", "555-1220");
    addContact(cb, "Lady Montague", "555-1221");
    printContactBook(cb);
    freeContactBook(cb);
    return 0;
}