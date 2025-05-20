//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
} Contact;

typedef struct {
    Contact* contacts;
    int size;
    int capacity;
} MailingList;

void init_list(MailingList* list) {
    list->contacts = NULL;
    list->size = 0;
    list->capacity = 0;
}

void add_contact(MailingList* list, Contact contact) {
    if (list->contacts == NULL) 
        list->contacts = (Contact*) malloc(sizeof(Contact));
    else if (list->size == list->capacity) {
        list->capacity *= 2;
        list->contacts = (Contact*) realloc(list->contacts, list->capacity * sizeof(Contact));
    }
    list->contacts[list->size++] = contact;
}

void print_list(MailingList list) {
    for (int i = 0; i < list.size; i++) {
        printf("[%d] %s: %s\n", i + 1, list.contacts[i].name, list.contacts[i].email);
    }
}

int main() {
    MailingList my_list;
    init_list(&my_list);

    Contact contact1 = {"John Smith", "johnsmith@example.com"};
    add_contact(&my_list, contact1);

    Contact contact2 = {"Jane Doe", "janedoe@example.com"};
    add_contact(&my_list, contact2);

    printf("Mailing list:\n");
    print_list(my_list);

    return 0;
}