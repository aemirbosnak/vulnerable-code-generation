//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    char phone[16];
} Contact;

Contact *phonebook = NULL;
int num_contacts = 0;

void add_contact(Contact *contact) {
    phonebook = realloc(phonebook, (num_contacts + 1) * sizeof(Contact));
    phonebook[num_contacts++] = *contact;
}

void print_phonebook() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Contact not found\n");
}

int main() {
    char input[256];
    Contact contact;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "add\n") == 0) {
            printf("Enter name: ");
            fgets(contact.name, sizeof(contact.name), stdin);
            printf("Enter phone: ");
            fgets(contact.phone, sizeof(contact.phone), stdin);
            add_contact(&contact);
        } else if (strcmp(input, "print\n") == 0) {
            print_phonebook();
        } else if (strcmp(input, "search\n") == 0) {
            printf("Enter name: ");
            fgets(input, sizeof(input), stdin);
            search_contact(input);
        } else if (strcmp(input, "quit\n") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}