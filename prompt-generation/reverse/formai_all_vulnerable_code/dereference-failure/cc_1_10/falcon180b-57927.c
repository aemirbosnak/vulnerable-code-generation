//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 10000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *list;
    int size;
} mailing_list;

void init_list(mailing_list *list) {
    list->list = (contact *) malloc(MAX_LIST_SIZE * sizeof(contact));
    list->size = 0;
}

int add_contact(mailing_list *list, char *name, char *email) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return -1;
    }

    strcpy(list->list[list->size].name, name);
    strcpy(list->list[list->size].email, email);

    list->size++;

    return 0;
}

int remove_contact(mailing_list *list, char *email) {
    int i;

    for (i = 0; i < list->size; i++) {
        if (strcmp(list->list[i].email, email) == 0) {
            list->size--;

            while (i < list->size) {
                list->list[i] = list->list[i+1];
                i++;
            }

            return 0;
        }
    }

    printf("Error: Contact not found.\n");
    return -1;
}

int send_email(mailing_list *list, char *subject, char *message) {
    int i;

    for (i = 0; i < list->size; i++) {
        printf("Sending email to %s (%s)...\n", list->list[i].name, list->list[i].email);
    }

    return 0;
}

int main() {
    mailing_list list;
    init_list(&list);

    add_contact(&list, "Neo", "neo@matrix.com");
    add_contact(&list, "Trinity", "trinity@matrix.com");
    add_contact(&list, "Morpheus", "morpheus@matrix.com");

    printf("Sending email to all contacts...\n");
    send_email(&list, "Meeting at the Oracle's", "Don't forget your red pill.");

    remove_contact(&list, "trinity@matrix.com");

    printf("Sending email to remaining contacts...\n");
    send_email(&list, "Change of plans", "We're going to Zion instead.");

    return 0;
}