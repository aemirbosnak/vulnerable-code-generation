//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
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
} mailing_list;

void init_mailing_list(mailing_list* list) {
    list->size = 0;
    list->capacity = 10;
    list->contacts = (contact*)malloc(list->capacity * sizeof(contact));
}

void add_contact(mailing_list* list, char* name, char* email) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->contacts = (contact*)realloc(list->contacts, list->capacity * sizeof(contact));
    }

    int index = list->size;
    strcpy(list->contacts[index].name, name);
    strcpy(list->contacts[index].email, email);

    list->size++;
}

int search_contact(mailing_list* list, char* email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            return i;
        }
    }

    return -1;
}

void send_message(mailing_list* list, int recipient_index, char* subject, char* message) {
    printf("Sending message to %s...\n", list->contacts[recipient_index].name);
    printf("Subject: %s\n", subject);
    printf("Message:\n%s\n", message);
}

int main() {
    mailing_list list;
    init_mailing_list(&list);

    add_contact(&list, "John Doe", "john@example.com");
    add_contact(&list, "Jane Doe", "jane@example.com");

    int recipient_index = search_contact(&list, "john@example.com");
    if (recipient_index!= -1) {
        send_message(&list, recipient_index, "Hello", "How are you doing today?");
    }

    recipient_index = search_contact(&list, "jane@example.com");
    if (recipient_index!= -1) {
        send_message(&list, recipient_index, "Hi", "Just wanted to say hello!");
    }

    return 0;
}