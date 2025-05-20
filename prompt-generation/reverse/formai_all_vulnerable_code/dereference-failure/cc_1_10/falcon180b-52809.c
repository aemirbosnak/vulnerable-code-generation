//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
    int max_contacts;
} MailingList;

MailingList *create_mailing_list(int max_contacts) {
    MailingList *list = malloc(sizeof(MailingList));
    list->contacts = malloc(max_contacts * sizeof(Contact));
    list->num_contacts = 0;
    list->max_contacts = max_contacts;
    return list;
}

void add_contact(MailingList *list, char *name, char *email) {
    if (list->num_contacts >= list->max_contacts) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strncpy(list->contacts[list->num_contacts].name, name, MAX_NAME_LEN);
    strncpy(list->contacts[list->num_contacts].email, email, MAX_EMAIL_LEN);
    list->num_contacts++;
}

void remove_contact(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            list->num_contacts--;
            memmove(&list->contacts[i], &list->contacts[i+1],
                    (list->num_contacts - i) * sizeof(Contact));
            break;
        }
    }
}

void print_contacts(MailingList *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("%s: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList *list = create_mailing_list(10);
    add_contact(list, "John Doe", "johndoe@example.com");
    add_contact(list, "Jane Smith", "janesmith@example.com");
    print_contacts(list);
    remove_contact(list, "johndoe@example.com");
    print_contacts(list);
    free(list->contacts);
    free(list);
    return 0;
}