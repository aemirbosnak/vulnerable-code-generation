//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *number;
} Contact;

Contact *phone_book = NULL;
int num_contacts = 0;

void add_contact(char *name, char *number) {
    phone_book = realloc(phone_book, sizeof(Contact) * (num_contacts + 1));
    phone_book[num_contacts].name = strdup(name);
    phone_book[num_contacts].number = strdup(number);
    num_contacts++;
}

void print_phone_book() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

void search_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            free(phone_book[i].name);
            free(phone_book[i].number);
            for (int j = i; j < num_contacts - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }
            num_contacts--;
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    add_contact("John Doe", "123-456-7890");
    add_contact("Jane Doe", "098-765-4321");
    add_contact("Bill Smith", "234-567-8901");

    print_phone_book();

    search_contact("John Doe");
    search_contact("Jane Doe");
    search_contact("Bill Smith");
    search_contact("Non-existent Contact");

    delete_contact("John Doe");
    print_phone_book();

    delete_contact("Non-existent Contact");

    return 0;
}