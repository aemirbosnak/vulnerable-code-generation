//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->contacts = malloc(sizeof(contact) * 10);
    list->num_contacts = 0;
    return list;
}

void add_contact(mailing_list *list, char *name, char *email) {
    if (list->num_contacts >= 10) {
        printf("Your heart is full! Cannot add more contacts.\n");
        return;
    }
    strcpy(list->contacts[list->num_contacts].name, name);
    strcpy(list->contacts[list->num_contacts].email, email);
    list->num_contacts++;
}

void remove_contact(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            break;
        }
    }
    if (i == list->num_contacts) {
        printf("Could not find that contact in your heart.\n");
        return;
    }
    for (; i < list->num_contacts - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->num_contacts--;
}

void print_mailing_list(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list *list = create_mailing_list();

    add_contact(list, "Alice", "alice@example.com");
    add_contact(list, "Bob", "bob@example.com");
    add_contact(list, "Eve", "eve@example.com");

    print_mailing_list(list);

    remove_contact(list, "Bob");

    print_mailing_list(list);

    free(list->contacts);
    free(list);
    return 0;
}