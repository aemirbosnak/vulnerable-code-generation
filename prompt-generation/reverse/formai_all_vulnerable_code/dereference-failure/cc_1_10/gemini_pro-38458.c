//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *number;
} Contact;

Contact *create_contact(char *name, char *number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

void free_contact(Contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

typedef struct {
    Contact **contacts;
    int size;
    int capacity;
} PhoneBook;

PhoneBook *create_phonebook() {
    PhoneBook *phonebook = malloc(sizeof(PhoneBook));
    phonebook->contacts = malloc(sizeof(Contact *) * 10);
    phonebook->size = 0;
    phonebook->capacity = 10;
    return phonebook;
}

void free_phonebook(PhoneBook *phonebook) {
    for (int i = 0; i < phonebook->size; i++) {
        free_contact(phonebook->contacts[i]);
    }
    free(phonebook->contacts);
    free(phonebook);
}

void add_contact(PhoneBook *phonebook, Contact *contact) {
    if (phonebook->size == phonebook->capacity) {
        phonebook->contacts = realloc(phonebook->contacts, sizeof(Contact *) * phonebook->capacity * 2);
        phonebook->capacity *= 2;
    }
    phonebook->contacts[phonebook->size++] = contact;
}

Contact *find_contact(PhoneBook *phonebook, char *name) {
    for (int i = 0; i < phonebook->size; i++) {
        if (strcmp(phonebook->contacts[i]->name, name) == 0) {
            return phonebook->contacts[i];
        }
    }
    return NULL;
}

void print_phonebook(PhoneBook *phonebook) {
    for (int i = 0; i < phonebook->size; i++) {
        printf("%s: %s\n", phonebook->contacts[i]->name, phonebook->contacts[i]->number);
    }
}

int main() {
    PhoneBook *phonebook = create_phonebook();
    add_contact(phonebook, create_contact("John Doe", "555-1212"));
    add_contact(phonebook, create_contact("Jane Doe", "555-1213"));
    add_contact(phonebook, create_contact("Bill Smith", "555-1214"));
    print_phonebook(phonebook);
    Contact *contact = find_contact(phonebook, "John Doe");
    printf("Found contact: %s: %s\n", contact->name, contact->number);
    free_phonebook(phonebook);
    return 0;
}