//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: automated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

struct contact {
    char name[50];
    char phone_number[15];
    int index;
};

struct contact* create_contact(char* name, char* phone_number) {
    struct contact* contact = (struct contact*)malloc(sizeof(struct contact));
    strcpy(contact->name, name);
    strcpy(contact->phone_number, phone_number);
    contact->index = rand() % 10000;
    return contact;
}

struct contact* search_contact(struct contact* contacts, int size, char* name) {
    for(int i = 0; i < size; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

void add_contact(struct contact* contacts, int* size, char* name, char* phone_number) {
    struct contact* new_contact = create_contact(name, phone_number);
    (*size)++;
    contacts = (struct contact*)realloc(contacts, sizeof(struct contact) * (*size));
    contacts[*size - 1] = *new_contact;
    free(new_contact);
}

void delete_contact(struct contact* contacts, int* size, char* name) {
    struct contact* contact = search_contact(contacts, *size, name);
    if(contact!= NULL) {
        for(int i = contact->index; i < (*size) - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*size)--;
        contacts = (struct contact*)realloc(contacts, sizeof(struct contact) * (*size));
    }
}

void display_contacts(struct contact* contacts, int size) {
    printf("Name\t\tPhone Number\n");
    for(int i = 0; i < size; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone_number);
    }
}

int main() {
    struct contact* contacts = NULL;
    int size = 0;

    contacts = (struct contact*)malloc(sizeof(struct contact));
    strcpy(contacts[0].name, "John Doe");
    strcpy(contacts[0].phone_number, "123-456-7890");
    size++;

    add_contact(contacts, &size, "Jane Doe", "987-654-3210");

    display_contacts(contacts, size);

    delete_contact(contacts, &size, "John Doe");

    display_contacts(contacts, size);

    free(contacts);
    return 0;
}