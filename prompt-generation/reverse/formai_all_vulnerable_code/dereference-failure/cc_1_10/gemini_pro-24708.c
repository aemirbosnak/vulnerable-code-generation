//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONTACTS 10

struct contact {
    char* name;
    char* number;
};

struct phone_book {
    struct contact* contacts[MAX_CONTACTS];
    int num_contacts;
};

struct phone_book* create_phone_book() {
    struct phone_book* pb = (struct phone_book*)malloc(sizeof(struct phone_book));
    pb->num_contacts = 0;
    return pb;
}

void free_phone_book(struct phone_book* pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        free(pb->contacts[i]->name);
        free(pb->contacts[i]->number);
        free(pb->contacts[i]);
    }
    free(pb);
}

void add_contact(struct phone_book* pb, char* name, char* number) {
    if (pb->num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    struct contact* c = (struct contact*)malloc(sizeof(struct contact));
    c->name = strdup(name);
    c->number = strdup(number);
    pb->contacts[pb->num_contacts++] = c;
}

void remove_contact(struct phone_book* pb, char* name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i]->name, name) == 0) {
            free(pb->contacts[i]->name);
            free(pb->contacts[i]->number);
            free(pb->contacts[i]);
            pb->contacts[i] = pb->contacts[pb->num_contacts - 1];
            pb->num_contacts--;
            return;
        }
    }
    printf("Contact not found!\n");
}

void print_phone_book(struct phone_book* pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s\n", pb->contacts[i]->name, pb->contacts[i]->number);
    }
}

int main() {
    struct phone_book* pb = create_phone_book();

    char* names[] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "George", "Hannah", "Ian", "Jack"};
    char* numbers[] = {"111-111-1111", "222-222-2222", "333-333-3333", "444-444-4444", "555-555-5555", "666-666-6666", "777-777-7777", "888-888-8888", "999-999-9999", "000-000-0000"};

    for (int i = 0; i < MAX_CONTACTS; i++) {
        add_contact(pb, names[i], numbers[i]);
    }

    print_phone_book(pb);

    remove_contact(pb, "Bob");

    printf("After removing Bob:\n");
    print_phone_book(pb);

    free_phone_book(pb);

    return 0;
}