//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact* recipients;
    int num_recipients;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} mailing_list;

void add_contact(contact* list, int num_contacts, char* name, char* email) {
    if (num_contacts == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(list[i].email, email) == 0) {
            printf("Contact already exists.\n");
            return;
        }
    }
    strcpy(list[num_contacts].name, name);
    strcpy(list[num_contacts].email, email);
    printf("Contact added successfully.\n");
}

void remove_contact(contact* list, int num_contacts, char* email) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(list[i].email, email) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                list[j] = list[j + 1];
            }
            printf("Contact removed successfully.\n");
            num_contacts--;
            return;
        }
    }
    printf("Contact not found.\n");
}

void send_mail(mailing_list* list, int num_recipients) {
    printf("Sending mail to %d recipients...\n", num_recipients);
    for (int i = 0; i < num_recipients; i++) {
        printf("Sending mail to %s...\n", list->recipients[i].name);
    }
    printf("Mail sent successfully.\n");
}

int main() {
    contact john = {"John", "john@example.com"};
    contact jane = {"Jane", "jane@example.com"};
    contact bob = {"Bob", "bob@example.com"};
    contact* contacts = &john;
    int num_contacts = 1;
    add_contact(contacts, num_contacts, "Alice", "alice@example.com");
    remove_contact(contacts, num_contacts, "Bob");
    mailing_list list = {contacts, num_contacts, "Hello!", "How are you?"};
    send_mail(&list, num_contacts);
    return 0;
}