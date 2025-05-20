//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    int size;
    int capacity;
    contact* contacts;
} contact_list;

void init_contact_list(contact_list* list) {
    list->size = 0;
    list->capacity = 10;
    list->contacts = (contact*) malloc(list->capacity * sizeof(contact));
}

void add_contact(contact_list* list, char* name, char* email) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->contacts = (contact*) realloc(list->contacts, list->capacity * sizeof(contact));
    }

    int index = list->size;
    strcpy(list->contacts[index].name, name);
    strcpy(list->contacts[index].email, email);

    list->size++;
}

void print_contacts(contact_list* list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s\nEmail: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void send_email(contact* recipient, char* subject, char* message) {
    printf("Sending email to %s:\nSubject: %s\n", recipient->email, subject);
    printf("Message:\n%s\n", message);
}

int main() {
    contact_list contacts;
    init_contact_list(&contacts);

    add_contact(&contacts, "King Arthur", "king@camelot.com");
    add_contact(&contacts, "Sir Lancelot", "sir@roundtable.com");
    add_contact(&contacts, "Merlin", "wizard@camelot.com");

    printf("Contacts:\n");
    print_contacts(&contacts);

    send_email(&contacts.contacts[0], "Knights of the Round Table Meeting", "Dear Knights,\n\nPlease assemble in the Great Hall for an important meeting.\n\nBest regards,\nKing Arthur");

    return 0;
}