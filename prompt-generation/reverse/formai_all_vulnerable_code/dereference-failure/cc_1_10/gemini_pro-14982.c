//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

Contact *contacts;
int num_contacts;

void add_contact(char *name, char *number) {
    contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);
    num_contacts++;
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

void find_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(char *name) {
    int index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    num_contacts--;
    contacts = realloc(contacts, num_contacts * sizeof(Contact));
}

int main() {
    contacts = malloc(0);
    num_contacts = 0;

    add_contact("John Doe", "555-123-4567");
    add_contact("Jane Smith", "555-234-5678");
    add_contact("Bob Jones", "555-345-6789");

    print_contacts();

    find_contact("John Doe");

    delete_contact("Jane Smith");

    print_contacts();

    return 0;
}